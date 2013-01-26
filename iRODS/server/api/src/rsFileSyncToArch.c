/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* rsFileSyncToArch.c - server routine that handles the fileSyncToArch
 * API
 */

/* script generated code */
#include "fileSyncToArch.h"
#include "fileOpr.h"
#include "miscServerFunct.h"
#include "dataObjOpr.h"
#include "physPath.h"

// =-=-=-=-=-=-=-
// eirods includes
#include "eirods_log.h"
#include "eirods_collection_object.h"


int
rsFileSyncToArch (rsComm_t *rsComm, fileStageSyncInp_t *fileSyncToArchInp,
char **outFileName)
{
    rodsServerHost_t *rodsServerHost;
    int remoteFlag;
    int status;

    remoteFlag = resolveHost (&fileSyncToArchInp->addr, &rodsServerHost);

    if (remoteFlag < 0) {
	return (remoteFlag);
    } else {
	status = rsFileSyncToArchByHost (rsComm, fileSyncToArchInp, 
	  outFileName, rodsServerHost);
	return (status);
    }
}

int 
rsFileSyncToArchByHost (rsComm_t *rsComm, 
fileStageSyncInp_t *fileSyncToArchInp, char **outFileName,
rodsServerHost_t *rodsServerHost)
{
    int status;
    int remoteFlag;

    if (rodsServerHost == NULL) {
        rodsLog (LOG_NOTICE,
         "rsFileSyncToArchByHost: Input NULL rodsServerHost");
	return (SYS_INTERNAL_NULL_INPUT_ERR);
    }
	    
    remoteFlag = rodsServerHost->localFlag;
    
    if (remoteFlag == LOCAL_HOST) {
	status = _rsFileSyncToArch (rsComm, fileSyncToArchInp, outFileName);
    } else if (remoteFlag == REMOTE_HOST) {
        status = remoteFileSyncToArch (rsComm, fileSyncToArchInp, 
	  outFileName, rodsServerHost);
    } else {
	if (remoteFlag < 0) {
	    return (remoteFlag);
	} else {
	    rodsLog (LOG_NOTICE,
	      "rsFileSyncToArchByHost: resolveHost returned value %d",
	       remoteFlag);
	    return (SYS_UNRECOGNIZED_REMOTE_FLAG);
	}
    }

    return (status);
}

int
remoteFileSyncToArch (rsComm_t *rsComm, 
fileStageSyncInp_t *fileSyncToArchInp, char **outFileName,
rodsServerHost_t *rodsServerHost)
{
    int status;

    if (rodsServerHost == NULL) {
        rodsLog (LOG_NOTICE,
	  "remoteFileSyncToArch: Invalid rodsServerHost");
        return SYS_INVALID_SERVER_HOST;
    }

    if ((status = svrToSvrConnect (rsComm, rodsServerHost)) < 0) {
        return status;
    }

    status = rcFileSyncToArch (rodsServerHost->conn, fileSyncToArchInp,
      outFileName);

    if (status < 0) { 
        rodsLog (LOG_NOTICE,
	 "remoteFileSyncToArch: rcFileSyncToArch failed for %s",
	  fileSyncToArchInp->filename);
    }

    return status;
}

// =-=-=-=-=-=-=-=
// _rsFileSyncToArch - this the local version of rsFileSyncToArch.
int _rsFileSyncToArch( rsComm_t *rsComm, fileStageSyncInp_t *fileSyncToArchInp, char **outFileName ) {
    // =-=-=-=-=-=-=-
    // XXXX need to check resource permission and vault permission
    // when RCAT is available 
    int status = -1;
    char myFileName[MAX_NAME_LEN];
    
    // =-=-=-=-=-=-=-
	// prep 
	*outFileName = NULL; // mem leak?
    rstrcpy( myFileName, fileSyncToArchInp->filename, MAX_NAME_LEN );

    // =-=-=-=-=-=-=-
	// make call to synctoarch via resource plugin
    eirods::error sync_err = fileSyncToArch( rsComm, myFileName, fileSyncToArchInp->cacheFilename, 
                                             fileSyncToArchInp->mode, fileSyncToArchInp->flags,
                                             fileSyncToArchInp->dataSize, &fileSyncToArchInp->condInput, 
											 status );

    if( !sync_err.ok() ) {

        if (getErrno (status) == ENOENT) {
			// =-=-=-=-=-=-=-
            // the directory does not exist, lets make one
            mkDirForFilePath( rsComm,"/", fileSyncToArchInp->filename, getDefDirMode() );
        } else if (getErrno (status) == EEXIST) {
			// =-=-=-=-=-=-=-
			// an empty dir may be there, make the call to rmdir via the resource plugin
			eirods::collection_object coll_obj( fileSyncToArchInp->filename, 0, 0 );
			eirods::error rmdir_err = fileRmdir( rsComm, coll_obj );
			if( !rmdir_err.ok() ) {
				std::stringstream msg;
				msg << "_rsFileSyncToArch: fileRmdir for ";
				msg << fileSyncToArchInp->filename;
				msg << ", status = ";
				msg << rmdir_err.code();
				eirods::error err = PASS( false, rmdir_err.code(), msg.str(), sync_err );
				eirods::log ( err );
			}
		} else {
			std::stringstream msg;
			msg << "_rsFileSyncToArch: fileSyncToArch for ";
			msg << myFileName;
			msg << ", status = ";
			msg << status;
			eirods::error err = PASS( false, status, msg.str(), sync_err );
			eirods::log ( err );
			return status;
		}
	
		// =-=-=-=-=-=-=-
		// make call to synctoarch via resource plugin
		sync_err = fileSyncToArch( rsComm, myFileName, fileSyncToArchInp->cacheFilename, 
								   fileSyncToArchInp->mode, fileSyncToArchInp->flags,
								   fileSyncToArchInp->dataSize, &fileSyncToArchInp->condInput, 
								   status );
        if( !sync_err.ok() ) {
			std::stringstream msg;
			msg << "_rsFileSyncToArch: fileSyncToArch for ";
			msg << myFileName;
			msg << ", status = ";
			msg << status;
			eirods::error err = PASS( false, status, msg.str(), sync_err );
			eirods::log ( err );
		}

    } // if !sync_err.ok()

    // =-=-=-=-=-=-=-
	// has the file name has changed?
    if( strcmp( myFileName, fileSyncToArchInp->filename ) != 0 ) {
		*outFileName = strdup (myFileName);
    }

    return (status);

} // _rsFileSyncToArch
 
