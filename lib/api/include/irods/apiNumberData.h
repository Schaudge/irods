// clang-format off

/* 500 - 599 - Internal File I/O API calls */
API_NUMBER(FILE_CREATE_AN,                          500)
API_NUMBER(FILE_OPEN_AN,                            501)
API_NUMBER(FILE_WRITE_AN,                           502)
API_NUMBER(FILE_CLOSE_AN,                           503)
API_NUMBER(FILE_LSEEK_AN,                           504)
API_NUMBER(FILE_READ_AN,                            505)
API_NUMBER(FILE_UNLINK_AN,                          506)
API_NUMBER(FILE_MKDIR_AN,                           507)
API_NUMBER(FILE_CHMOD_AN,                           508)
API_NUMBER(FILE_RMDIR_AN,                           509)
API_NUMBER(FILE_STAT_AN,                            510)
API_NUMBER(FILE_FSTAT_AN,                           511)
API_NUMBER(FILE_FSYNC_AN,                           512)

API_NUMBER(FILE_STAGE_AN,                           513)
API_NUMBER(FILE_GET_FS_FREE_SPACE_AN,               514)
API_NUMBER(FILE_OPENDIR_AN,                         515)
API_NUMBER(FILE_CLOSEDIR_AN,                        516)
API_NUMBER(FILE_READDIR_AN,                         517)
API_NUMBER(FILE_PUT_AN,                             518)
API_NUMBER(FILE_GET_AN,                             519)
API_NUMBER(FILE_CHKSUM_AN,                          520)
API_NUMBER(CHK_N_V_PATH_PERM_AN,                    521)
API_NUMBER(FILE_RENAME_AN,                          522)
API_NUMBER(FILE_TRUNCATE_AN,                        523)
API_NUMBER(FILE_STAGE_TO_CACHE_AN,                  524)
API_NUMBER(FILE_SYNC_TO_ARCH_AN,                    525)

/* 600 - 699 - Object File I/O API calls */
API_NUMBER(DATA_OBJ_CREATE_AN,                      601)
API_NUMBER(DATA_OBJ_OPEN_AN,                        602)
API_NUMBER(DATA_OBJ_PUT_AN,                         606)
API_NUMBER(DATA_PUT_AN,                             607)
API_NUMBER(DATA_OBJ_GET_AN,                         608)
API_NUMBER(DATA_GET_AN,                             609)
API_NUMBER(DATA_COPY_AN,                            611)
// DEPRECATED: SimpleQuery is deprecated. Use GenQuery or SpecificQuery instead.
API_NUMBER(SIMPLE_QUERY_AN,                         614)
API_NUMBER(DATA_OBJ_UNLINK_AN,                      615)
API_NUMBER(REG_DATA_OBJ_AN,                         619)
API_NUMBER(UNREG_DATA_OBJ_AN,                       620)
API_NUMBER(REG_REPLICA_AN,                          621)
API_NUMBER(MOD_DATA_OBJ_META_AN,                    622)
API_NUMBER(RULE_EXEC_SUBMIT_AN,                     623)
API_NUMBER(RULE_EXEC_DEL_AN,                        624)
API_NUMBER(EXEC_MY_RULE_AN,                         625)
API_NUMBER(OPR_COMPLETE_AN,                         626)
API_NUMBER(DATA_OBJ_RENAME_AN,                      627)
API_NUMBER(DATA_OBJ_RSYNC_AN,                       628)
API_NUMBER(DATA_OBJ_CHKSUM_AN,                      629)
API_NUMBER(PHY_PATH_REG_AN,                         630)
API_NUMBER(DATA_OBJ_TRIM_AN,                        632)
API_NUMBER(OBJ_STAT_AN,                             633)
API_NUMBER(SUB_STRUCT_FILE_CREATE_AN,               635)
API_NUMBER(SUB_STRUCT_FILE_OPEN_AN,                 636)
API_NUMBER(SUB_STRUCT_FILE_READ_AN,                 637)
API_NUMBER(SUB_STRUCT_FILE_WRITE_AN,                638)
API_NUMBER(SUB_STRUCT_FILE_CLOSE_AN,                639)
API_NUMBER(SUB_STRUCT_FILE_UNLINK_AN,               640)
API_NUMBER(SUB_STRUCT_FILE_STAT_AN,                 641)
API_NUMBER(SUB_STRUCT_FILE_FSTAT_AN,                642)
API_NUMBER(SUB_STRUCT_FILE_LSEEK_AN,                643)
API_NUMBER(SUB_STRUCT_FILE_RENAME_AN,               644)
API_NUMBER(QUERY_SPEC_COLL_AN,                      645)
API_NUMBER(SUB_STRUCT_FILE_MKDIR_AN,                647)
API_NUMBER(SUB_STRUCT_FILE_RMDIR_AN,                648)
API_NUMBER(SUB_STRUCT_FILE_OPENDIR_AN,              649)
API_NUMBER(SUB_STRUCT_FILE_READDIR_AN,              650)
API_NUMBER(SUB_STRUCT_FILE_CLOSEDIR_AN,             651)
API_NUMBER(DATA_OBJ_TRUNCATE_AN,                    652)
API_NUMBER(SUB_STRUCT_FILE_TRUNCATE_AN,             653)
API_NUMBER(GET_XMSG_TICKET_AN,                      654)
API_NUMBER(SEND_XMSG_AN,                            655)
API_NUMBER(RCV_XMSG_AN,                             656)
API_NUMBER(SUB_STRUCT_FILE_GET_AN,                  657)
API_NUMBER(SUB_STRUCT_FILE_PUT_AN,                  658)
API_NUMBER(SYNC_MOUNTED_COLL_AN,                    659)
API_NUMBER(STRUCT_FILE_SYNC_AN,                     660)
API_NUMBER(CLOSE_COLLECTION_AN,                     661)
API_NUMBER(STRUCT_FILE_EXTRACT_AN,                  664)
API_NUMBER(STRUCT_FILE_EXT_AND_REG_AN,              665)
API_NUMBER(STRUCT_FILE_BUNDLE_AN,                   666)
API_NUMBER(CHK_OBJ_PERM_AND_STAT_AN,                667)
API_NUMBER(GET_REMOTE_ZONE_RESC_AN,                 668)
API_NUMBER(DATA_OBJ_OPEN_AND_STAT_AN,               669)
API_NUMBER(L3_FILE_GET_SINGLE_BUF_AN,               670)
API_NUMBER(L3_FILE_PUT_SINGLE_BUF_AN,               671)
API_NUMBER(DATA_OBJ_CREATE_AND_STAT_AN,             672)
API_NUMBER(DATA_OBJ_CLOSE_AN,                       673)
API_NUMBER(DATA_OBJ_LSEEK_AN,                       674)
API_NUMBER(DATA_OBJ_READ_AN,                        675)
API_NUMBER(DATA_OBJ_WRITE_AN,                       676)
API_NUMBER(COLL_REPL_AN,                            677)
API_NUMBER(OPEN_COLLECTION_AN,                      678)
API_NUMBER(RM_COLL_AN,                              679)
API_NUMBER(MOD_COLL_AN,                             680)
API_NUMBER(COLL_CREATE_AN,                          681)
API_NUMBER(DATA_OBJ_UNLOCK_AN,                      682)
API_NUMBER(REG_COLL_AN,                             683)
API_NUMBER(PHY_BUNDLE_COLL_AN,                      684)
API_NUMBER(UNBUN_AND_REG_PHY_BUNFILE_AN,            685)
API_NUMBER(GET_HOST_FOR_PUT_AN,                     686)
API_NUMBER(GET_RESC_QUOTA_AN,                       687)
API_NUMBER(BULK_DATA_OBJ_REG_AN,                    688)
API_NUMBER(BULK_DATA_OBJ_PUT_AN,                    689)
API_NUMBER(PROC_STAT_AN,                            690)
API_NUMBER(STREAM_READ_AN,                          691)
API_NUMBER(EXEC_CMD_AN,                             692)
API_NUMBER(STREAM_CLOSE_AN,                         693)
API_NUMBER(GET_HOST_FOR_GET_AN,                     694)
API_NUMBER(DATA_OBJ_REPL_AN,                        695)
API_NUMBER(DATA_OBJ_COPY_AN,                        696)
API_NUMBER(DATA_OBJ_PHYMV_AN,                       697)
API_NUMBER(DATA_OBJ_FSYNC_AN,                       698)
API_NUMBER(DATA_OBJ_LOCK_AN,                        699) // JMC - backport 4599

/* 700 - 799 - Metadata API calls */
API_NUMBER(GET_MISC_SVR_INFO_AN,                    700)
API_NUMBER(GENERAL_ADMIN_AN,                        701)
API_NUMBER(GEN_QUERY_AN,                            702)
API_NUMBER(AUTH_REQUEST_AN,                         703)
API_NUMBER(AUTH_RESPONSE_AN,                        704)
API_NUMBER(AUTH_CHECK_AN,                           705)
API_NUMBER(MOD_AVU_METADATA_AN,                     706)
API_NUMBER(MOD_ACCESS_CONTROL_AN,                   707)
API_NUMBER(RULE_EXEC_MOD_AN,                        708)
API_NUMBER(GET_TEMP_PASSWORD_AN,                    709)
API_NUMBER(GENERAL_UPDATE_AN,                       710)
API_NUMBER(READ_COLLECTION_AN,                      713)
API_NUMBER(USER_ADMIN_AN,                           714)
API_NUMBER(GENERAL_ROW_INSERT_AN,                   715)
API_NUMBER(GENERAL_ROW_PURGE_AN,                    716)
API_NUMBER(END_TRANSACTION_AN,                      718)
API_NUMBER(DATABASE_RESC_OPEN_AN,                   719)
API_NUMBER(DATABASE_OBJ_CONTROL_AN,                 720)
API_NUMBER(DATABASE_RESC_CLOSE_AN,                  721)
API_NUMBER(SPECIFIC_QUERY_AN,                       722)
API_NUMBER(TICKET_ADMIN_AN,                         723)
API_NUMBER(GET_TEMP_PASSWORD_FOR_OTHER_AN,          724)
API_NUMBER(PAM_AUTH_REQUEST_AN,                     725)
API_NUMBER(GET_LIMITED_PASSWORD_AN,                 726)

API_NUMBER(CHECK_AUTH_CREDENTIALS_AN,               800)
API_NUMBER(GET_LIBRARY_FEATURES_AN,                 801)

/* 1100 - 1200 - SSL API calls */
API_NUMBER(SSL_START_AN,                            1100)
API_NUMBER(SSL_END_AN,                              1101)

API_NUMBER(AUTH_PLUG_REQ_AN,                        1201)
API_NUMBER(AUTH_PLUG_RESP_AN,                       1202)
API_NUMBER(GET_HIER_FOR_RESC_AN,                    1203)
API_NUMBER(GET_HIER_FROM_LEAF_ID_AN,                1204)
API_NUMBER(SET_RR_CTX_AN,                           1205)
API_NUMBER(EXEC_RULE_EXPRESSION_AN,                 1206)

API_NUMBER(SERVER_REPORT_AN,                        10204)
API_NUMBER(ZONE_REPORT_AN,                          10205)
API_NUMBER(CLIENT_HINTS_AN,                         10215)

API_NUMBER(GET_RESOURCE_INFO_FOR_OPERATION_AN,      10220)

// clang-format on
