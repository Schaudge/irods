/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/

/* rodsGenQueryNames.h - common header file for the generalized query names.
 * Maps the user specified strings to the corresponding #define values.
 */

#ifndef GEN_QUERY_NAMES_H__
#define GEN_QUERY_NAMES_H__

#include "irods/rodsGenQuery.h"

typedef struct {
    int columnId;
    char *columnName;
} columnName_t;

columnName_t columnNames[] = {
    { COL_ZONE_ID,          "ZONE_ID", },
    { COL_ZONE_NAME,        "ZONE_NAME", },

    { COL_ZONE_TYPE,        "ZONE_TYPE", },
    { COL_ZONE_CONNECTION,  "ZONE_CONNECTION", },
    { COL_ZONE_COMMENT,     "ZONE_COMMENT", },
    { COL_ZONE_CREATE_TIME, "ZONE_CREATE_TIME", },
    { COL_ZONE_MODIFY_TIME, "ZONE_MODIFY_TIME", },

    { COL_USER_ID,          "USER_ID", },
    { COL_USER_NAME,        "USER_NAME", },
    { COL_USER_TYPE,        "USER_TYPE", },
    { COL_USER_ZONE,        "USER_ZONE", },
    { COL_USER_DN,          "USER_DN", },
    { COL_USER_INFO,        "USER_INFO", },
    { COL_USER_COMMENT,     "USER_COMMENT", },
    { COL_USER_CREATE_TIME, "USER_CREATE_TIME", },
    { COL_USER_MODIFY_TIME, "USER_MODIFY_TIME", },

    { COL_R_RESC_ID,     "RESC_ID", },
    { COL_R_RESC_NAME,   "RESC_NAME", },
    { COL_R_ZONE_NAME,   "RESC_ZONE_NAME", },
    { COL_R_TYPE_NAME,   "RESC_TYPE_NAME", },
    { COL_R_CLASS_NAME,  "RESC_CLASS_NAME", },
    { COL_R_LOC,         "RESC_LOC", },
    { COL_R_VAULT_PATH,  "RESC_VAULT_PATH", },
    { COL_R_FREE_SPACE,  "RESC_FREE_SPACE", },
    { COL_R_FREE_SPACE_TIME,  "RESC_FREE_SPACE_TIME", },
    { COL_R_RESC_INFO,   "RESC_INFO", },
    { COL_R_RESC_COMMENT, "RESC_COMMENT", },
    { COL_R_CREATE_TIME, "RESC_CREATE_TIME", },
    { COL_R_MODIFY_TIME, "RESC_MODIFY_TIME", },
    { COL_R_RESC_STATUS, "RESC_STATUS", },
    { COL_R_RESC_CHILDREN, "RESC_CHILDREN", },
    { COL_R_RESC_CONTEXT,  "RESC_CONTEXT", },
    { COL_R_RESC_PARENT,   "RESC_PARENT", },
    { COL_R_RESC_PARENT_CONTEXT,   "RESC_PARENT_CONTEXT", },

    { COL_D_DATA_ID,        "DATA_ID", },
    { COL_D_COLL_ID,        "DATA_COLL_ID", },
    { COL_DATA_NAME,        "DATA_NAME", },
    { COL_DATA_REPL_NUM,    "DATA_REPL_NUM", },
    { COL_DATA_VERSION,     "DATA_VERSION", },
    { COL_DATA_TYPE_NAME,   "DATA_TYPE_NAME", },
    { COL_DATA_SIZE,        "DATA_SIZE", },
    { COL_DATA_MODE,        "DATA_MODE", },
    { COL_D_RESC_NAME,      "DATA_RESC_NAME", },
    { COL_D_RESC_HIER,      "DATA_RESC_HIER", },
    { COL_D_DATA_PATH,      "DATA_PATH", },
    { COL_D_OWNER_NAME,     "DATA_OWNER_NAME", },
    { COL_D_OWNER_ZONE,     "DATA_OWNER_ZONE", },
    { COL_D_REPL_STATUS,    "DATA_REPL_STATUS", },
    { COL_D_DATA_STATUS,    "DATA_STATUS", },
    { COL_D_DATA_CHECKSUM,  "DATA_CHECKSUM", },
    { COL_D_EXPIRY,         "DATA_EXPIRY", },
    { COL_D_MAP_ID,         "DATA_MAP_ID", },
    { COL_D_COMMENTS,       "DATA_COMMENTS", },
    { COL_D_CREATE_TIME,    "DATA_CREATE_TIME", },
    { COL_D_MODIFY_TIME,    "DATA_MODIFY_TIME", },
    { COL_D_RESC_ID,        "DATA_RESC_ID", },
    { COL_DATA_USER_NAME,   "DATA_USER_NAME", },
    { COL_DATA_USER_ZONE,   "DATA_ZONE_NAME", },

    { COL_DATA_ACCESS_TYPE,     "DATA_ACCESS_TYPE", },
    { COL_DATA_ACCESS_NAME,     "DATA_ACCESS_NAME", },
    { COL_DATA_TOKEN_NAMESPACE, "DATA_TOKEN_NAMESPACE", },
    { COL_DATA_ACCESS_USER_ID,  "DATA_ACCESS_USER_ID", },
    { COL_DATA_ACCESS_DATA_ID,  "DATA_ACCESS_DATA_ID", },

    { COL_COLL_ID,            "COLL_ID", },
    { COL_COLL_NAME,          "COLL_NAME", },
    { COL_COLL_PARENT_NAME,   "COLL_PARENT_NAME", },
    { COL_COLL_OWNER_NAME,    "COLL_OWNER_NAME", },
    { COL_COLL_OWNER_ZONE,    "COLL_OWNER_ZONE", },
    { COL_COLL_MAP_ID,        "COLL_MAP_ID", },
    { COL_COLL_INHERITANCE,   "COLL_INHERITANCE", },
    { COL_COLL_COMMENTS,      "COLL_COMMENTS", },
    { COL_COLL_CREATE_TIME,   "COLL_CREATE_TIME", },
    { COL_COLL_MODIFY_TIME,   "COLL_MODIFY_TIME", },
    { COL_COLL_USER_NAME,     "COLL_USER_NAME", },
    { COL_COLL_USER_ZONE,     "COLL_ZONE_NAME", },
    { COL_COLL_TYPE,          "COLL_TYPE", },
    { COL_COLL_INFO1,         "COLL_INFO_1", },
    { COL_COLL_INFO2,         "COLL_INFO_2", },

    { COL_COLL_ACCESS_TYPE,     "COLL_ACCESS_TYPE", },
    { COL_COLL_ACCESS_NAME,     "COLL_ACCESS_NAME", },
    { COL_COLL_TOKEN_NAMESPACE, "COLL_TOKEN_NAMESPACE", },
    { COL_COLL_ACCESS_USER_ID,  "COLL_ACCESS_USER_ID", },
    { COL_COLL_ACCESS_COLL_ID,  "COLL_ACCESS_COLL_ID", },


    { COL_META_DATA_ATTR_NAME,  "META_DATA_ATTR_NAME", },
    { COL_META_DATA_ATTR_VALUE, "META_DATA_ATTR_VALUE", },
    { COL_META_DATA_ATTR_UNITS, "META_DATA_ATTR_UNITS", },
    { COL_META_DATA_ATTR_ID,    "META_DATA_ATTR_ID", },
    { COL_META_DATA_CREATE_TIME, "META_DATA_CREATE_TIME", },
    { COL_META_DATA_MODIFY_TIME, "META_DATA_MODIFY_TIME", },

    { COL_META_COLL_ATTR_NAME,  "META_COLL_ATTR_NAME", },
    { COL_META_COLL_ATTR_VALUE, "META_COLL_ATTR_VALUE", },
    { COL_META_COLL_ATTR_UNITS, "META_COLL_ATTR_UNITS", },
    { COL_META_COLL_ATTR_ID,    "META_COLL_ATTR_ID", },
    { COL_META_COLL_CREATE_TIME,  "META_COLL_CREATE_TIME", },
    { COL_META_COLL_MODIFY_TIME,  "META_COLL_MODIFY_TIME", },

    { COL_META_NAMESPACE_COLL,  "META_NAMESPACE_COLL", },
    { COL_META_NAMESPACE_DATA,  "META_NAMESPACE_DATA", },
    { COL_META_NAMESPACE_RESC,  "META_NAMESPACE_RESC", },
    { COL_META_NAMESPACE_USER,  "META_NAMESPACE_USER", },
    { COL_META_NAMESPACE_RESC_GROUP,  "META_NAMESPACE_RESC_GROUP", },
    { COL_META_NAMESPACE_RULE,    "META_NAMESPACE_RULE", },
    { COL_META_NAMESPACE_MSRVC,   "META_NAMESPACE_MSRVC", },
    { COL_META_NAMESPACE_MET2,    "META_NAMESPACE_MET2", },

    { COL_META_RESC_ATTR_NAME,  "META_RESC_ATTR_NAME", },
    { COL_META_RESC_ATTR_VALUE, "META_RESC_ATTR_VALUE", },
    { COL_META_RESC_ATTR_UNITS, "META_RESC_ATTR_UNITS", },
    { COL_META_RESC_ATTR_ID,    "META_RESC_ATTR_ID", },
    { COL_META_RESC_CREATE_TIME,  "META_RESC_CREATE_TIME", },
    { COL_META_RESC_MODIFY_TIME,  "META_RESC_MODIFY_TIME", },

    { COL_META_RESC_GROUP_ATTR_NAME,  "META_RESC_GROUP_ATTR_NAME", },
    { COL_META_RESC_GROUP_ATTR_VALUE, "META_RESC_GROUP_ATTR_VALUE", },
    { COL_META_RESC_GROUP_ATTR_UNITS, "META_RESC_GROUP_ATTR_UNITS", },
    { COL_META_RESC_GROUP_ATTR_ID,    "META_RESC_GROUP_ATTR_ID", },
    { COL_META_RESC_GROUP_CREATE_TIME,    "META_RESC_GROUP_CREATE_TIME", },
    { COL_META_RESC_GROUP_MODIFY_TIME,    "META_RESC_GROUP_MODIFY_TIME", },

    { COL_META_USER_ATTR_NAME,  "META_USER_ATTR_NAME", },
    { COL_META_USER_ATTR_VALUE, "META_USER_ATTR_VALUE", },
    { COL_META_USER_ATTR_UNITS, "META_USER_ATTR_UNITS", },
    { COL_META_USER_ATTR_ID,    "META_USER_ATTR_ID", },
    { COL_META_USER_CREATE_TIME,  "META_USER_CREATE_TIME", },
    { COL_META_USER_MODIFY_TIME,  "META_USER_MODIFY_TIME", },

    { COL_META_RULE_ATTR_NAME,    "META_RULE_ATTR_NAME", },
    { COL_META_RULE_ATTR_VALUE,   "META_RULE_ATTR_VALUE", },
    { COL_META_RULE_ATTR_UNITS,   "META_RULE_ATTR_UNITS", },
    { COL_META_RULE_ATTR_ID,      "META_RULE_ATTR_ID", },
    { COL_META_RULE_CREATE_TIME,  "META_RULE_CREATE_TIME", },
    { COL_META_RULE_MODIFY_TIME,  "META_RULE_MODIFY_TIME", },

    { COL_META_MSRVC_ATTR_NAME,   "META_MSRVC_ATTR_NAME", },
    { COL_META_MSRVC_ATTR_VALUE,  "META_MSRVC_ATTR_VALUE", },
    { COL_META_MSRVC_ATTR_UNITS,  "META_MSRVC_ATTR_UNITS", },
    { COL_META_MSRVC_ATTR_ID,     "META_MSRVC_ATTR_ID", },
    { COL_META_MSRVC_CREATE_TIME, "META_MSRVC_CREATE_TIME", },
    { COL_META_MSRVC_MODIFY_TIME, "META_MSRVC_MODIFY_TIME", },

    { COL_META_MET2_ATTR_NAME,    "META_MET2_ATTR_NAME", },
    { COL_META_MET2_ATTR_VALUE,   "META_MET2_ATTR_VALUE", },
    { COL_META_MET2_ATTR_UNITS,   "META_MET2_ATTR_UNITS", },
    { COL_META_MET2_ATTR_ID,      "META_MET2_ATTR_ID", },
    { COL_META_MET2_CREATE_TIME,  "META_MET2_CREATE_TIME", },
    { COL_META_MET2_MODIFY_TIME,  "META_MET2_MODIFY_TIME", },

//    { COL_RESC_GROUP_RESC_ID,   "RESC_GROUP_RESC_ID", },	// gone in 4.1 #1472
//    { COL_RESC_GROUP_NAME,      "RESC_GROUP_NAME", },
//    { COL_RESC_GROUP_ID,        "RESC_GROUP_ID", },

    { COL_USER_GROUP_ID,        "USER_GROUP_ID", },
    { COL_USER_GROUP_NAME,      "USER_GROUP_NAME", },

    { COL_RULE_EXEC_ID,                 "RULE_EXEC_ID", },
    { COL_RULE_EXEC_NAME,               "RULE_EXEC_NAME", },
    { COL_RULE_EXEC_REI_FILE_PATH,      "RULE_EXEC_REI_FILE_PATH", },
    { COL_RULE_EXEC_USER_NAME,          "RULE_EXEC_USER_NAME", },
    { COL_RULE_EXEC_ADDRESS,            "RULE_EXEC_ADDRESS", },
    { COL_RULE_EXEC_TIME,               "RULE_EXEC_TIME", },
    { COL_RULE_EXEC_FREQUENCY,          "RULE_EXEC_FREQUENCY", },
    { COL_RULE_EXEC_PRIORITY,           "RULE_EXEC_PRIORITY", },
    { COL_RULE_EXEC_ESTIMATED_EXE_TIME, "RULE_EXEC_ESTIMATED_EXE_TIME", },
    { COL_RULE_EXEC_NOTIFICATION_ADDR,  "RULE_EXEC_NOTIFICATION_ADDR", },
    { COL_RULE_EXEC_LAST_EXE_TIME,      "RULE_EXEC_LAST_EXE_TIME", },
    { COL_RULE_EXEC_STATUS,             "RULE_EXEC_STATUS", },
    { COL_RULE_EXEC_CONTEXT,            "RULE_EXEC_CONTEXT", },

    { COL_TOKEN_NAMESPACE, "TOKEN_NAMESPACE", },
    { COL_TOKEN_ID,        "TOKEN_ID", },
    { COL_TOKEN_NAME,      "TOKEN_NAME", },
    { COL_TOKEN_VALUE,     "TOKEN_VALUE", },
    { COL_TOKEN_VALUE2,    "TOKEN_VALUE2", },
    { COL_TOKEN_VALUE3,    "TOKEN_VALUE3", },
    { COL_TOKEN_COMMENT,   "TOKEN_COMMENT", },
    { COL_TOKEN_CREATE_TIME, "TOKEN_CREATE_TIME", },
    { COL_TOKEN_MODIFY_TIME, "TOKEN_MODIFY_TIME", },

    { COL_AUDIT_OBJ_ID,      "AUDIT_OBJ_ID", },
    { COL_AUDIT_USER_ID,     "AUDIT_USER_ID", },
    { COL_AUDIT_ACTION_ID,   "AUDIT_ACTION_ID", },
    { COL_AUDIT_COMMENT,     "AUDIT_COMMENT", },
    { COL_AUDIT_CREATE_TIME, "AUDIT_CREATE_TIME", },
    { COL_AUDIT_MODIFY_TIME, "AUDIT_MODIFY_TIME", },

    { COL_SL_HOST_NAME,   "SL_HOST_NAME", },
    { COL_SL_RESC_NAME,   "SL_RESC_NAME", },
    { COL_SL_CPU_USED,    "SL_CPU_USED", },
    { COL_SL_MEM_USED,    "SL_MEM_USED", },
    { COL_SL_SWAP_USED,   "SL_SWAP_USED", },
    { COL_SL_RUNQ_LOAD,   "SL_RUNQ_LOAD", },
    { COL_SL_DISK_SPACE,  "SL_DISK_SPACE", },
    { COL_SL_NET_INPUT,   "SL_NET_INPUT", },
    { COL_SL_NET_OUTPUT,  "SL_NET_OUTPUT", },
    { COL_SL_CREATE_TIME, "SL_CREATE_TIME", },
    { COL_SLD_RESC_NAME,  "SLD_RESC_NAME", },
    { COL_SLD_LOAD_FACTOR, "SLD_LOAD_FACTOR", },
    { COL_SLD_CREATE_TIME, "SLD_CREATE_TIME", },

    { COL_RULE_BASE_MAP_VERSION,        "RULE_BASE_MAP_VERSION", },
    { COL_RULE_BASE_MAP_PRIORITY,       "RULE_BASE_MAP_PRIORITY", },
    { COL_RULE_BASE_MAP_BASE_NAME,      "RULE_BASE_MAP_BASE_NAME", },
    { COL_RULE_BASE_MAP_OWNER_NAME,     "RULE_BASE_MAP_OWNER_NAME", },
    { COL_RULE_BASE_MAP_OWNER_ZONE,     "RULE_BASE_MAP_OWNER_ZONE", },
    { COL_RULE_BASE_MAP_COMMENT,        "RULE_BASE_MAP_COMMENT", },
    { COL_RULE_BASE_MAP_CREATE_TIME,    "RULE_BASE_MAP_CREATE_TIME", },
    { COL_RULE_BASE_MAP_MODIFY_TIME,    "RULE_BASE_MAP_MODIFY_TIME", },

    { COL_RULE_ID,          "RULE_ID", },
    { COL_RULE_VERSION,     "RULE_VERSION", },
    { COL_RULE_BASE_NAME,   "RULE_BASE_NAME", },
    { COL_RULE_NAME,        "RULE_NAME", },
    { COL_RULE_EVENT,       "RULE_EVENT", },
    { COL_RULE_CONDITION,   "RULE_CONDITION", },
    { COL_RULE_BODY,        "RULE_BODY", },
    { COL_RULE_RECOVERY,    "RULE_RECOVERY", },
    { COL_RULE_STATUS,      "RULE_STATUS", },
    { COL_RULE_OWNER_NAME,  "RULE_OWNER_NAME", },
    { COL_RULE_OWNER_ZONE,  "RULE_OWNER_ZONE", },
    { COL_RULE_DESCR_1,     "RULE_DESCR_1", },
    { COL_RULE_DESCR_2,     "RULE_DESCR_2", },
    { COL_RULE_INPUT_PARAMS, "RULE_INPUT_PARAMS", },
    { COL_RULE_OUTPUT_PARAMS, "RULE_OUTPUT_PARAMS", },
    { COL_RULE_DOLLAR_VARS, "RULE_DOLLAR_VARS", },
    { COL_RULE_ICAT_ELEMENTS, "RULE_ICAT_ELEMENTS", },
    { COL_RULE_SIDEEFFECTS, "RULE_SIDEEFFECTS", },
    { COL_RULE_COMMENT,     "RULE_COMMENT", },
    { COL_RULE_CREATE_TIME, "RULE_CREATE_TIME", },
    { COL_RULE_MODIFY_TIME, "RULE_MODIFY_TIME", },

    { COL_DVM_BASE_MAP_VERSION,        "DVM_BASE_MAP_VERSION", },
    { COL_DVM_BASE_MAP_BASE_NAME,      "DVM_BASE_MAP_BASE_NAME", },
    { COL_DVM_BASE_MAP_OWNER_NAME,     "DVM_BASE_MAP_OWNER_NAME", },
    { COL_DVM_BASE_MAP_OWNER_ZONE,     "DVM_BASE_MAP_OWNER_ZONE", },
    { COL_DVM_BASE_MAP_COMMENT,        "DVM_BASE_MAP_COMMENT", },
    { COL_DVM_BASE_MAP_CREATE_TIME,    "DVM_BASE_MAP_CREATE_TIME", },
    { COL_DVM_BASE_MAP_MODIFY_TIME,    "DVM_BASE_MAP_MODIFY_TIME", },

    { COL_DVM_ID,           "DVM_ID", },
    { COL_DVM_VERSION,      "DVM_VERSION", },
    { COL_DVM_BASE_NAME,    "DVM_BASE_NAME", },
    { COL_DVM_EXT_VAR_NAME, "DVM_EXT_VAR_NAME", },
    { COL_DVM_CONDITION,    "DVM_CONDITION", },
    { COL_DVM_INT_MAP_PATH, "DVM_INT_MAP_PATH", },
    { COL_DVM_STATUS,       "DVM_STATUS", },
    { COL_DVM_OWNER_NAME,   "DVM_OWNER_NAME", },
    { COL_DVM_OWNER_ZONE,   "DVM_OWNER_ZONE", },
    { COL_DVM_COMMENT,      "DVM_COMMENT", },
    { COL_DVM_CREATE_TIME,  "DVM_CREATE_TIME", },
    { COL_DVM_MODIFY_TIME,  "DVM_MODIFY_TIME", },

    { COL_FNM_BASE_MAP_VERSION,        "FNM_BASE_MAP_VERSION", },
    { COL_FNM_BASE_MAP_BASE_NAME,      "FNM_BASE_MAP_BASE_NAME", },
    { COL_FNM_BASE_MAP_OWNER_NAME,     "FNM_BASE_MAP_OWNER_NAME", },
    { COL_FNM_BASE_MAP_OWNER_ZONE,     "FNM_BASE_MAP_OWNER_ZONE", },
    { COL_FNM_BASE_MAP_COMMENT,        "FNM_BASE_MAP_COMMENT", },
    { COL_FNM_BASE_MAP_CREATE_TIME,    "FNM_BASE_MAP_CREATE_TIME", },
    { COL_FNM_BASE_MAP_MODIFY_TIME,    "FNM_BASE_MAP_MODIFY_TIME", },

    { COL_FNM_ID,           "FNM_ID", },
    { COL_FNM_VERSION,      "FNM_VERSION", },
    { COL_FNM_BASE_NAME,    "FNM_BASE_NAME", },
    { COL_FNM_EXT_FUNC_NAME, "FNM_EXT_FUNC_NAME", },
    { COL_FNM_INT_FUNC_NAME, "FNM_INT_FUNC_NAME", },
    { COL_FNM_STATUS,       "FNM_STATUS", },
    { COL_FNM_OWNER_NAME,   "FNM_OWNER_NAME", },
    { COL_FNM_OWNER_ZONE,   "FNM_OWNER_ZONE", },
    { COL_FNM_COMMENT,      "FNM_COMMENT", },
    { COL_FNM_CREATE_TIME,  "FNM_CREATE_TIME", },
    { COL_FNM_MODIFY_TIME,  "FNM_MODIFY_TIME", },

    { COL_QUOTA_USER_ID, "QUOTA_USER_ID", },
    { COL_QUOTA_RESC_ID, "QUOTA_RESC_ID", },
    { COL_QUOTA_LIMIT,   "QUOTA_LIMIT", },
    { COL_QUOTA_OVER,    "QUOTA_OVER", },
    { COL_QUOTA_MODIFY_TIME, "QUOTA_MODIFY_TIME", },

    {COL_QUOTA_USAGE_USER_ID,     "QUOTA_USAGE_USER_ID", },
    {COL_QUOTA_USAGE_RESC_ID,     "QUOTA_USAGE_RESC_ID", },
    {COL_QUOTA_USAGE,             "QUOTA_USAGE", },
    {COL_QUOTA_USAGE_MODIFY_TIME, "QUOTA_USAGE_MODIFY_TIME", },

    {COL_QUOTA_USER_NAME, "QUOTA_USER_NAME", },
    {COL_QUOTA_USER_ZONE, "QUOTA_USER_ZONE", },
    {COL_QUOTA_USER_TYPE, "QUOTA_USER_TYPE", },
    {COL_QUOTA_RESC_NAME, "QUOTA_RESC_NAME", },

    { COL_MSRVC_ID,       "MSRVC_ID", },
    { COL_MSRVC_NAME,     "MSRVC_NAME", },
    { COL_MSRVC_SIGNATURE,        "MSRVC_SIGNATURE", },
    { COL_MSRVC_DOXYGEN,  "MSRVC_DOXYGEN", },
    { COL_MSRVC_VARIATIONS,       "MSRVC_VARIATIONS", },
    { COL_MSRVC_STATUS,   "MSRVC_STATUS", },
    { COL_MSRVC_OWNER_NAME,       "MSRVC_OWNER_NAME", },
    { COL_MSRVC_OWNER_ZONE,       "MSRVC_OWNER_ZONE", },
    { COL_MSRVC_COMMENT,  "MSRVC_COMMENT", },
    { COL_MSRVC_CREATE_TIME,      "MSRVC_CREATE_TIME", },
    { COL_MSRVC_MODIFY_TIME,      "MSRVC_MODIFY_TIME", },
    { COL_MSRVC_MODULE_NAME,     "MSRVC_MODULE_NAME", },

    { COL_MSRVC_VERSION,  "MSRVC_VERSION", },
    { COL_MSRVC_HOST,     "MSRVC_HOST", },
    { COL_MSRVC_LOCATION, "MSRVC_LOCATION", },
    { COL_MSRVC_LANGUAGE, "MSRVC_LANGUAGE", },
    { COL_MSRVC_TYPE_NAME,        "MSRVC_TYPE_NAME", },
    { COL_MSRVC_VER_OWNER_NAME,   "MSRVC_VER_OWNER_NAME", },
    { COL_MSRVC_VER_OWNER_ZONE,   "MSRVC_VER_OWNER_ZONE", },
    { COL_MSRVC_VER_COMMENT,      "MSRVC_VER_COMMENT", },
    { COL_MSRVC_VER_CREATE_TIME,  "MSRVC_VER_CREATE_TIME", },
    { COL_MSRVC_VER_MODIFY_TIME,  "MSRVC_VER_MODIFY_TIME", },

    { COL_META_ACCESS_TYPE,       "META_ACCESS_TYPE", },
    { COL_META_ACCESS_NAME,       "META_ACCESS_NAME", },
    { COL_META_TOKEN_NAMESPACE,   "META_TOKEN_NAMESPACE", },
    { COL_META_ACCESS_USER_ID,    "META_ACCESS_USER_ID", },
    { COL_META_ACCESS_META_ID,    "META_ACCESS_META_ID", },
    { COL_RESC_ACCESS_TYPE,       "RESC_ACCESS_TYPE", },
    { COL_RESC_ACCESS_NAME,       "RESC_ACCESS_NAME", },
    { COL_RESC_TOKEN_NAMESPACE,   "RESC_TOKEN_NAMESPACE", },
    { COL_RESC_ACCESS_USER_ID,    "RESC_ACCESS_USER_ID", },
    { COL_RESC_ACCESS_RESC_ID,    "RESC_ACCESS_RESC_ID", },
    { COL_RULE_ACCESS_TYPE,       "RULE_ACCESS_TYPE", },
    { COL_RULE_ACCESS_NAME,       "RULE_ACCESS_NAME", },
    { COL_RULE_TOKEN_NAMESPACE,   "RULE_TOKEN_NAMESPACE", },
    { COL_RULE_ACCESS_USER_ID,    "RULE_ACCESS_USER_ID", },
    { COL_RULE_ACCESS_RULE_ID,    "RULE_ACCESS_RULE_ID", },
    { COL_MSRVC_ACCESS_TYPE,      "MSRVC_ACCESS_TYPE", },
    { COL_MSRVC_ACCESS_NAME,      "MSRVC_ACCESS_NAME", },
    { COL_MSRVC_TOKEN_NAMESPACE,  "MSRVC_TOKEN_NAMESPACE", },
    { COL_MSRVC_ACCESS_USER_ID,   "MSRVC_ACCESS_USER_ID", },
    { COL_MSRVC_ACCESS_MSRVC_ID,  "MSRVC_ACCESS_MSRVC_ID", },

    { COL_TICKET_ID,                       "TICKET_ID", },
    { COL_TICKET_STRING,                   "TICKET_STRING", },
    { COL_TICKET_TYPE,                     "TICKET_TYPE", },
    { COL_TICKET_USER_ID,                  "TICKET_USER_ID", },
    { COL_TICKET_OBJECT_ID,                "TICKET_OBJECT_ID", },
    { COL_TICKET_OBJECT_TYPE,              "TICKET_OBJECT_TYPE", },
    { COL_TICKET_USES_LIMIT,               "TICKET_USES_LIMIT", },
    { COL_TICKET_USES_COUNT,               "TICKET_USES_COUNT", },
    { COL_TICKET_WRITE_FILE_COUNT,         "TICKET_WRITE_FILE_COUNT", },
    { COL_TICKET_WRITE_FILE_LIMIT,         "TICKET_WRITE_FILE_LIMIT", },
    { COL_TICKET_WRITE_BYTE_COUNT,         "TICKET_WRITE_BYTE_COUNT", },
    { COL_TICKET_WRITE_BYTE_LIMIT,         "TICKET_WRITE_BYTE_LIMIT", },
    { COL_TICKET_EXPIRY_TS,                "TICKET_EXPIRY", },
    { COL_TICKET_CREATE_TIME,              "TICKET_CREATE_TIME", },
    { COL_TICKET_MODIFY_TIME,              "TICKET_MODIFY_TIME", },
    { COL_TICKET_ALLOWED_HOST_TICKET_ID,   "TICKET_ALLOWED_HOST_TICKET_ID", },
    { COL_TICKET_ALLOWED_HOST,             "TICKET_ALLOWED_HOST", },
    { COL_TICKET_ALLOWED_USER_TICKET_ID,   "TICKET_ALLOWED_USER_TICKET_ID", },
    { COL_TICKET_ALLOWED_USER_NAME,        "TICKET_ALLOWED_USER_NAME", },
    { COL_TICKET_ALLOWED_GROUP_TICKET_ID,  "TICKET_ALLOWED_GROUP_TICKET_ID", },
    { COL_TICKET_ALLOWED_GROUP_NAME,       "TICKET_ALLOWED_GROUP_NAME", },
    { COL_TICKET_DATA_NAME,                "TICKET_DATA_NAME", },
    { COL_TICKET_DATA_COLL_NAME,           "TICKET_DATA_COLL_NAME", },
    { COL_TICKET_COLL_NAME,                "TICKET_COLL_NAME", },
    { COL_TICKET_OWNER_NAME,               "TICKET_OWNER_NAME", },
    { COL_TICKET_OWNER_ZONE,               "TICKET_OWNER_ZONE", },

};

int NumOfColumnNames = sizeof( columnNames ) / sizeof( columnName_t );

#endif	/* GEN_QUERY_NAMES_H__ */
