# We need to define everything for CPack at the top level of the project.
# Variables defined in CMake files included via add_subdirectory don't make it back to the calling CMake file.

# Dependency declarations for externals packages
string(REPLACE ";" ", " IRODS_PACKAGE_DEPENDENCIES_STRING "${IRODS_PACKAGE_DEPENDENCIES_LIST}")
string(REPLACE ";" ", " IRODS_DEVELOP_DEPENDENCIES_STRING "${IRODS_DEVELOP_DEPENDENCIES_LIST}")

# We build multiple packages, so this doesn't really matter.
# We define it anyway to avoid potential issues.
set(CPACK_PACKAGE_FILE_NAME "irods")

# CPackDeb TO_UPPERs all the component names when checking the ${CPACK_DEBIAN_<COMPONENT>...} variables
string(TOUPPER ${IRODS_PACKAGE_COMPONENT_SERVER_NAME} IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE)
string(TOUPPER ${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME} IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME_UPPERCASE)
string(TOUPPER ${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME} IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE)
string(TOUPPER ${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME} IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE)
string(TOUPPER ${IRODS_PACKAGE_COMPONENT_MYSQL_NAME} IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE)
string(TOUPPER ${IRODS_PACKAGE_COMPONENT_ORACLE_NAME} IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE)

include(IrodsCPackCommon)

if (CPACK_GENERATOR STREQUAL "DEB")
  # CPACK_DEBIAN_PACKAGE_VERSION was previously a cache variable. Evict it.
  unset(CPACK_DEBIAN_PACKAGE_VERSION CACHE)
  set(CPACK_DEBIAN_PACKAGE_VERSION "${IRODS_VERSION}")
elseif (CPACK_GENERATOR STREQUAL "RPM")
  set(CPACK_RPM_PACKAGE_VERSION "${IRODS_VERSION}")
endif()

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_COMPONENT_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_COMPONENTS_GROUPING IGNORE) # One package per component
set(CPACK_PACKAGE_VERSION "${IRODS_VERSION}")
set(CPACK_PACKAGE_VERSION_MAJOR "${IRODS_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${IRODS_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${IRODS_VERSION_PATCH}")

set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS OFF)
set(CPACK_DEBIAN_PACKAGE_CONTROL_STRICT_PERMISSION ON)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

set(CPACK_RPM_COMPONENT_INSTALL ON)
set(CPACK_RPM_PACKAGE_LICENSE "BSD-3-Clause")
set(CPACK_RPM_PACKAGE_AUTOREQ 0)
set(CPACK_RPM_PACKAGE_AUTOPROV 0)
set(CPACK_RPM_PACKAGE_RELOCATABLE ON)
set(CPACK_RPM_FILE_NAME RPM-DEFAULT)

set(CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/sbin")
if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "rocky")
  list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/lib")
endif()

set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)

#######################################
## Runtime package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE}_PACKAGE_NAME "irods-runtime")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods-runtime (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
if (OPENSSL_VERSION VERSION_LESS "3.0.0")
  set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, libc6, sudo, libssl1.1, libfuse2, libxml2, openssl")
else()
  set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, libc6, sudo, libssl3, libfuse2, libxml2, openssl")
endif()
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE}_PACKAGE_REPLACES "irods-server (<< 4.2.10-2~)")

get_filename_component(CURL_LIBRARY_REALPATH ${CURL_LIBRARY} REALPATH)
get_filename_component(CURL_LIBRARY_REALNAME ${CURL_LIBRARY_REALPATH} NAME_WE)
if (CURL_LIBRARY_REALNAME STREQUAL "libcurl-gnutls")
  set(CPACK_DEBIAN_PACKAGE_DEPENDS_CURL "libcurl3-gnutls")
elseif (CURL_LIBRARY_REALNAME STREQUAL "libcurl-nss")
  set(CPACK_DEBIAN_PACKAGE_DEPENDS_CURL "libcurl3-nss")
elseif (CURL_LIBRARY_REALNAME STREQUAL "libcurl")
  if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "ubuntu")
    if (IRODS_LINUX_DISTRIBUTION_VERSION_MAJOR GREATER_EQUAL "18")
      set(CPACK_DEBIAN_PACKAGE_DEPENDS_CURL "libcurl4")
    else()
      set(CPACK_DEBIAN_PACKAGE_DEPENDS_CURL "libcurl3")
    endif()
  elseif (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "debian")
    if (IRODS_LINUX_DISTRIBUTION_VERSION_MAJOR GREATER_EQUAL "10")
      set(CPACK_DEBIAN_PACKAGE_DEPENDS_CURL "libcurl4")
    else()
      set(CPACK_DEBIAN_PACKAGE_DEPENDS_CURL "libcurl3")
    endif()
  endif()
endif()
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE}_PACKAGE_DEPENDS "${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE}_PACKAGE_DEPENDS}, ${CPACK_DEBIAN_PACKAGE_DEPENDS_CURL}")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME}_PACKAGE_NAME "irods-runtime")
if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "opensuse")
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, libopenssl1_0_0, curl-devel, openssl")
else()
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, libxml2, curl-devel, openssl")
endif()

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME}_POST_INSTALL_SCRIPT_FILE "${CMAKE_IRODS_SOURCE_DIR}/packaging/runtime_library_postinst.sh")

if (CPACK_GENERATOR STREQUAL DEB)
  install(
    FILES
    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME_UPPERCASE}_PACKAGE_NAME}"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_RUNTIME_NAME}
    RENAME copyright
  )
endif()

#######################################
## Server package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_NAME "irods-server")
if (OPENSSL_VERSION VERSION_LESS "3.0.0")
  set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-runtime (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), libc6, sudo, libssl1.1, libfuse2, python3, openssl, python3-psutil, python3-requests, python3-pyodbc, python3-jsonschema, python3-distro, lsof")
else()
  set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-runtime (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), libc6, sudo, libssl3, libfuse2, python3, openssl, python3-psutil, python3-requests, python3-pyodbc, python3-jsonschema, python3-distro, lsof")
endif()
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_RECOMMENDS "irods-icommands (>= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods, irods-server (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_CONFLICTS "eirods")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_BREAKS "irods-icat, irods-resource")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_REPLACES "irods-icat, irods-resource")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/preinst;${CMAKE_CURRENT_SOURCE_DIR}/postinst;${CMAKE_CURRENT_SOURCE_DIR}/prerm;")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_NAME "irods-server")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-runtime = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, openssl, python3, python3-psutil")
if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "centos" AND IRODS_LINUX_DISTRIBUTION_VERSION_MAJOR EQUAL 7)
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_REQUIRES "${CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_REQUIRES}, python36-jsonschema, python36-requests, python36-distro")
else()
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_REQUIRES "${CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_REQUIRES}, python3-jsonschema, python3-requests, python3-distro, python3-pyodbc")
endif()
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_SUGGESTS "irods-icommands = ${CPACK_RPM_PACKAGE_VERSION}")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PRE_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/preinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_POST_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/postinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PRE_UNINSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/prerm")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_PROVIDES "irods")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_CONFLICTS "eirods")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_SERVER_NAME}_PACKAGE_OBSOLETES "irods-icat, irods-resource")

if (CPACK_GENERATOR STREQUAL DEB)
  install(
    FILES
    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_SERVER_NAME_UPPERCASE}_PACKAGE_NAME}"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_SERVER_NAME}
    RENAME copyright
  )
endif()

#######################################
## Development package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME_UPPERCASE}_PACKAGE_NAME "irods-dev")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_DEVELOP_DEPENDENCIES_STRING}, irods-runtime (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), libssl-dev")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods-dev (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME_UPPERCASE}_PACKAGE_REPLACES "irods-runtime (<< 4.3.0~)")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME}_PACKAGE_NAME "irods-devel")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME}_PACKAGE_REQUIRES "${IRODS_DEVELOP_DEPENDENCIES_STRING}, irods-runtime = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}")
if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "opensuse")
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME}_PACKAGE_REQUIRES "${CPACK_RPM_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME}_PACKAGE_REQUIRES}, libopenssl-devel")
else()
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME}_PACKAGE_REQUIRES "${CPACK_RPM_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME}_PACKAGE_REQUIRES}, openssl-devel")
endif()
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME}_PACKAGE_OBSOLETES "irods-dev")

if (CPACK_GENERATOR STREQUAL DEB)
  install(
    FILES
    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME_UPPERCASE}_PACKAGE_NAME}"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_DEVELOPMENT_NAME}
    RENAME copyright
  )
endif()

#######################################
## Postgres database plugin package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_NAME "irods-database-plugin-postgres")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), unixodbc, libodbc1, odbcinst, odbc-postgresql, postgresql-client, super, libc6")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods-database-plugin-postgres (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_CONFLICTS "irods-database-plugin-mysql, irods-database-plugin-oracle")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/preinst;${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postinst;${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postrm;")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_NAME "irods-database-plugin-postgres")
if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "opensuse")
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC, postgresql, psqlODBC")
elseif (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "centos" AND IRODS_LINUX_DISTRIBUTION_VERSION_MAJOR EQUAL 7)
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC, postgresql, authd, postgresql-odbc")
else()
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC, postgresql, postgresql-odbc")
endif()
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_CONFLICTS "irods-database-plugin-mysql, irods-database-plugin-oracle")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PRE_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/preinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_POST_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_POST_UNINSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postrm")

if (CPACK_GENERATOR STREQUAL DEB)
  install(
    FILES
    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_NAME}"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}
    RENAME copyright
  )
endif()

#######################################
## MySQL database plugin package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_NAME "irods-database-plugin-mysql")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), unixodbc, libodbc1, odbcinst, virtual-mysql-client, libc6")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_RECOMMENDS "odbc-mariadb | mariadb-connector-odbc | mysql-connector-odbc | mysql-connector-odbc-commercial | libmyodbc")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods-database-plugin-mysql (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_CONFLICTS "irods-database-plugin-postgres, irods-database-plugin-oracle")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/preinst;${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postinst;${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postrm;")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_NAME "irods-database-plugin-mysql")
if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "opensuse")
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, mariadb-client, unixODBC")
elseif (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "centos" AND IRODS_LINUX_DISTRIBUTION_VERSION_MAJOR EQUAL 7)
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, mysql, unixODBC, mysql-connector-odbc")
else()
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, mariadb, unixODBC, mariadb-connector-odbc")
endif()
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_CONFLICTS "irods-database-plugin-postgres, irods-database-plugin-oracle")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PRE_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/preinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_POST_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_POST_UNINSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postrm")

if (CPACK_GENERATOR STREQUAL DEB)
  install(
    FILES
    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_NAME}"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}
    RENAME copyright
  )
endif()

#######################################
## Oracle database plugin package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_NAME "irods-database-plugin-oracle")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), unixodbc, libodbc1, odbcinst, libc6")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods-database-plugin-oracle (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_CONFLICTS "irods-database-plugin-mysql, irods-database-plugin-postgres")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/preinst;${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postinst;${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postrm;")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_PACKAGE_NAME "irods-database-plugin-oracle")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_PACKAGE_CONFLICTS "irods-database-plugin-mysql, irods-database-plugin-postgres")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_PRE_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/preinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_POST_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_POST_UNINSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/plugins/database/packaging/postrm")

if (CPACK_GENERATOR STREQUAL DEB)
  install(
    FILES
    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_NAME}"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}
    RENAME copyright
  )
endif()
