| 合约名 | 方法名 | 资源名 | 功能 | 默认权限 | 备注 | 
|----------------|----------------|--------------------------------|----------------|----------------|----------------|
|  |  | ARCHIVE |  | {[ADMIN] ANY []} |  |
|  |  | CONSENSUS |  | {[CONSENSUS] ANY []} |  |
|  |  | INVOKE_CONTRACT |  | {[] ANY []} |  |
|  |  | SUBSCRIBE |  | {[] ANY []} |  |
|  |  | QUERY_CONTRACT |  | {[] ANY []} |  |
|  |  | PRIVATE_COMPUTE |  | {[] FORBIDDEN []} |  |
| ACCOUNT_MANAGER | REFUND_GAS_VM | ACCOUNT_MANAGER-REFUND_GAS_VM |  | {[] FORBIDDEN []} |  |
| ACCOUNT_MANAGER | SET_ADMIN | ACCOUNT_MANAGER-SET_ADMIN |  | {[] FORBIDDEN []} |  |
| CERT_MANAGE | CERTS_ALIAS_DELETE | CERT_MANAGE-CERTS_ALIAS_DELETE |  | {[] FORBIDDEN []} |  |
| CERT_MANAGE | CERTS_DELETE | CERT_MANAGE-CERTS_DELETE |  | {[] FORBIDDEN []} |  |
| CERT_MANAGE | CERTS_FREEZE | CERT_MANAGE-CERTS_FREEZE |  | {[] FORBIDDEN []} |  |
| CERT_MANAGE | CERTS_REVOKE | CERT_MANAGE-CERTS_REVOKE |  | {[] FORBIDDEN []} |  |
| CERT_MANAGE | CERTS_UNFREEZE | CERT_MANAGE-CERTS_UNFREEZE |  | {[] FORBIDDEN []} |  |
| CERT_MANAGE | CERT_ADD | CERT_MANAGE-CERT_ADD |  | {[] FORBIDDEN []} |  |
| CERT_MANAGE | CERT_ALIAS_ADD | CERT_MANAGE-CERT_ALIAS_ADD |  | {[] FORBIDDEN []} |  |
| CERT_MANAGE | CERT_ALIAS_UPDATE | CERT_MANAGE-CERT_ALIAS_UPDATE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | ALTER_ADDR_TYPE | CHAIN_CONFIG-ALTER_ADDR_TYPE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | BLOCK_UPDATE | CHAIN_CONFIG-BLOCK_UPDATE |  | {[ADMIN] ANY []} |  |
| CHAIN_CONFIG | CONSENSUS_EXT_ADD | CHAIN_CONFIG-CONSENSUS_EXT_ADD |  | {[ADMIN] MAJORITY []} |  |
| CHAIN_CONFIG | CONSENSUS_EXT_DELETE | CHAIN_CONFIG-CONSENSUS_EXT_DELETE |  | {[ADMIN] MAJORITY []} |  |
| CHAIN_CONFIG | CONSENSUS_EXT_UPDATE | CHAIN_CONFIG-CONSENSUS_EXT_UPDATE |  | {[ADMIN] MAJORITY []} |  |
| CHAIN_CONFIG | CORE_UPDATE | CHAIN_CONFIG-CORE_UPDATE |  | {[ADMIN] ANY []} |  |
| CHAIN_CONFIG | ENABLE_OR_DISABLE_GAS | CHAIN_CONFIG-ENABLE_OR_DISABLE_GAS |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | NODE_ID_ADD | CHAIN_CONFIG-NODE_ID_ADD |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | NODE_ID_DELETE | CHAIN_CONFIG-NODE_ID_DELETE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | NODE_ID_UPDATE | CHAIN_CONFIG-NODE_ID_UPDATE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | NODE_ORG_ADD | CHAIN_CONFIG-NODE_ORG_ADD |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | NODE_ORG_DELETE | CHAIN_CONFIG-NODE_ORG_DELETE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | NODE_ORG_UPDATE | CHAIN_CONFIG-NODE_ORG_UPDATE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | PERMISSION_ADD | CHAIN_CONFIG-PERMISSION_ADD |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | PERMISSION_DELETE | CHAIN_CONFIG-PERMISSION_DELETE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | PERMISSION_UPDATE | CHAIN_CONFIG-PERMISSION_UPDATE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | TRUST_MEMBER_ADD | CHAIN_CONFIG-TRUST_MEMBER_ADD |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | TRUST_MEMBER_DELETE | CHAIN_CONFIG-TRUST_MEMBER_DELETE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | TRUST_MEMBER_UPDATE | CHAIN_CONFIG-TRUST_MEMBER_UPDATE |  | {[] FORBIDDEN []} |  |
| CHAIN_CONFIG | TRUST_ROOT_ADD | CHAIN_CONFIG-TRUST_ROOT_ADD |  | {[ADMIN] MAJORITY []} |  |
| CHAIN_CONFIG | TRUST_ROOT_DELETE | CHAIN_CONFIG-TRUST_ROOT_DELETE |  | {[ADMIN] MAJORITY []} |  |
| CHAIN_CONFIG | TRUST_ROOT_UPDATE | CHAIN_CONFIG-TRUST_ROOT_UPDATE |  | {[ADMIN] SELF []} |  |
| CONTRACT_MANAGE | FREEZE_CONTRACT | CONTRACT_MANAGE-FREEZE_CONTRACT |  | {[ADMIN] ANY []} |  |
| CONTRACT_MANAGE | GET_DISABLED_CONTRACT_LIST | CONTRACT_MANAGE-GET_DISABLED_CONTRACT_LIST |  | {[] FORBIDDEN []} |  |
| CONTRACT_MANAGE | GRANT_CONTRACT_ACCESS | CONTRACT_MANAGE-GRANT_CONTRACT_ACCESS |  | {[] FORBIDDEN []} |  |
| CONTRACT_MANAGE | REVOKE_CONTRACT | CONTRACT_MANAGE-REVOKE_CONTRACT |  | {[ADMIN] ANY []} |  |
| CONTRACT_MANAGE | REVOKE_CONTRACT_ACCESS | CONTRACT_MANAGE-REVOKE_CONTRACT_ACCESS |  | {[] FORBIDDEN []} |  |
| CONTRACT_MANAGE | UNFREEZE_CONTRACT | CONTRACT_MANAGE-UNFREEZE_CONTRACT |  | {[ADMIN] ANY []} |  |
| CONTRACT_MANAGE | UPGRADE_CONTRACT | CONTRACT_MANAGE-UPGRADE_CONTRACT |  | {[ADMIN] ANY []} |  |
| CONTRACT_MANAGE | VERIFY_CONTRACT_ACCESS | CONTRACT_MANAGE-VERIFY_CONTRACT_ACCESS |  | {[] FORBIDDEN []} |  |
| MULTI_SIGN | QUERY | MULTI_SIGN-QUERY |  | {[] FORBIDDEN []} |  |
| MULTI_SIGN | REQ | MULTI_SIGN-REQ |  | {[] FORBIDDEN []} |  |
| MULTI_SIGN | VOTE | MULTI_SIGN-VOTE |  | {[] FORBIDDEN []} |  |
| PRIVATE_COMPUTE | SAVE_CA_CERT | PRIVATE_COMPUTE-SAVE_CA_CERT |  | {[] FORBIDDEN []} |  |
| PRIVATE_COMPUTE | SAVE_ENCLAVE_REPORT | PRIVATE_COMPUTE-SAVE_ENCLAVE_REPORT |  | {[] FORBIDDEN []} |  |
| PUBKEY_MANAGE | PUBKEY_ADD | PUBKEY_MANAGE-PUBKEY_ADD |  | {[] FORBIDDEN []} |  |
| PUBKEY_MANAGE | PUBKEY_DELETE | PUBKEY_MANAGE-PUBKEY_DELETE |  | {[] FORBIDDEN []} |  |