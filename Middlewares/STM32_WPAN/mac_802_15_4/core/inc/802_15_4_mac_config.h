/******************************************************************************
 * @file   802_15_4_mac_config.h
 * @author  MDG-RF Team
 * @brief   Header for mac interface types
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */

#ifndef _INC_802_15_4_MAC_CONFIG_H_
#define _INC_802_15_4_MAC_CONFIG_H_

#include <stdint.h>

/**************************** Public Macro Definitions ***********************/

/** @brief  Defines the max num of PAN descriptors supported */
#define g_MAX_PAN_DESC_SUPPORTED_c  6

/** @brief  Defines the max num of sounding devices */
#define g_MAX_SOUNDING_LIST_SUPPORTED_c 6

/** @brief  Defines the max num of target device in beacon indication in case
of pending data*/
#define  g_MAX_PENDING_ADDRESS_c 5

/** @brief  Defines the max num of ED scan results supported */
#define g_MAX_ED_SCAN_RESULTS_SUPPORTED_c   16

#define g_SIZE_LONG_INT_c                   4
#define NOBUFFER                      255
#define g_LONG_ADDRESS_LENGTH_c             8

#define g_TX_OPTION_DIRECT_c          0x00
#define g_TX_OPTION_ACK_c             0x01
#define g_TX_OPTION_INDIRECT_c            0x04
#define g_TX_OPTION_INDIRECT_WITH_ACK_c   0x05
#define g_aResponse_Time_c                  0x01EB
#define g_SWITCH_OFF_RECIEVER_c             0x00
#define g_SWITCH_ON_RECIEVER_c              0x01

#define g_TRUE      0x01
#define g_FALSE     0x00

/**************************** Public Enum Definitions ************************/

/*! @brief Address Mode values */
typedef enum Addr_Mode_Tag {
    /*! -0x00 - No address mode specified */
    g_NO_ADDR_MODE_c,

    /*! -0x01 - Reserved */
    g_RESERVED_MODE_c,

    /*! -0x02 - Short address mode */
    g_SHORT_ADDR_MODE_c,

    /*! -0x03 - Long or extended address mode */
    g_EXTENDED_ADDR_MODE_c
} Addr_Mode_t;

/*! @brief Boolean values for true and false */
typedef enum Bool_Tag {
    /*! -False is defined as 0x00 */
    g_FALSE_c,

    /*! -True is defined as 0x01 */
    g_TRUE_c
} Bool_t;

/** @brief   Message ID of MAC request/response/indication/confirmation */
typedef enum MAC_Message_ID_Tag {
    /*! -MCPS Data Request */
    g_MCPS_DATA_REQUEST_c = (uint8_t) 0x40,

    /*! -MCPS Data Confirm */
    g_MCPS_DATA_CONFIRM_c,

    /*! -MCPS Data Indication */
    g_MCPS_DATA_INDICATION_c,

    /*! -MCPS Purge request */
    g_MCPS_PURGE_REQUEST_c,

    /*! -MCPS Purge Confirm */
    g_MCPS_PURGE_CONFIRM_c,

    /*! -MLME Associate Request */
    g_MLME_ASSOCIATE_REQUEST_c,

    /*! -MLME Associate Confirm */
    g_MLME_ASSOCIATE_CONFIRM_c,

    /*! -MLME Associate Indication */
    g_MLME_ASSOCIATE_INDICATION_c,

    /*! -MLME Associate Response */
    g_MLME_ASSOCIATE_RESPONSE_c,

    /*! -MLME Disassociate Request */
    g_MLME_DISASSOCIATE_REQUEST_c,

    /*! -MLME Disassociate Confirm */
    g_MLME_DISASSOCIATE_CONFIRM_c,

    /*! -MLME Disassociate Indication */
    g_MLME_DISASSOCIATE_INDICATION_c,

    /*! -MLME Beacon Notify Indication */
    g_MLME_BEACON_NOTIFY_INDICATION_c,

    /*! -MLME Get Request */
    g_MLME_GET_REQUEST_c,

    /*! -MLME Get Confirm */
    g_MLME_GET_CONFIRM_c,

    /*! -MLME Orphan Indication */
    g_MLME_ORPHAN_INDICATION_c,

    /*! -MLME Orphan Response */
    g_MLME_ORPHAN_RESPONSE_c,

    /*! -MLME Reset Request */
    g_MLME_RESET_REQUEST_c,

    /*! -MLME Reset Confirm */
    g_MLME_RESET_CONFIRM_c,

    /*! -MLME RX Enable Request */
    g_MLME_RX_ENABLE_REQUEST_c,

    /*! -MLME RX Enable Confirm */
    g_MLME_RX_ENABLE_CONFIRM_c,

    /*! -MLME Scan Request */
    g_MLME_SCAN_REQUEST_c,

    /*! -MLME Scan Confirm */
    g_MLME_SCAN_CONFIRM_c,

    /*! -MLME Comm Status Indication */
    g_MLME_COMM_STATUS_INDICATION_c,

    /*! -MLME Set Request */
    g_MLME_SET_REQUEST_c,

    /*! -MLME Set Confirm */
    g_MLME_SET_CONFIRM_c,

    /*! -MLME Start Request */
    g_MLME_START_REQUEST_c,

    /*! -MLME Start Confirm */
    g_MLME_START_CONFIRM_c,

    /*! -MLME Sync Loss Indication */
    g_MLME_SYNC_LOSS_INDICATION_c,

    /*! -MLME Poll Request */
    g_MLME_POLL_REQUEST_c,

    /*! -MLME Poll Confirm */
    g_MLME_POLL_CONFIRM_c
} MAC_Message_ID_t;

/******************************************************************************/

/** @brief MAC Transmission Options */
typedef enum MAC_Tx_Options_Tag {
    /*! -Acknowledged Transmission */
    g_ACK_TX_c = (uint8_t) 0x01,

    /*! -GTS Transmission */
    g_GTS_TX_c = (uint8_t) 0x02,

    /*! -Indirect Transmission */
    g_INDIRECT_TX_c = (uint8_t) 0x04,

    /*! -Security Enabled Transmission */
    g_SECURED_TX_c = (uint8_t) 0x08
} MAC_Tx_Options_t;

/******************************************************************************/
/** @brief MAC Association Status */
typedef enum MAC_Association_Status_Tag {
    /*! -Association successful */
    g_MAC_ASSO_SUCCESS_c = (uint8_t) 0x00,

    /*! -PAN at capacity */
    g_MAC_PAN_AT_CAPACITY_c = (uint8_t) 0x01,

    /*! -PAN access denied */
    g_MAC_PAN_ACCESS_DENIED_c = (uint8_t) 0x02
} MAC_Association_Status_t;

/******************************************************************************/
/** @brief MAC Disassociation reason codes */
typedef enum MAC_Disassociation_Reason_Tag {
    /*! -The coordinator wishes the device to leave the PAN. */
    g_COORD_REQUESTED_c = (uint8_t) 0x01,

    /*! -The device wishes to leave the PAN. */
    g_DEVICE_REQUESTED_c = (uint8_t) 0x02

} MAC_Disassociation_Reason_t;

/******************************************************************************/
/** @brief MAC Security Mode */
typedef enum MAC_Security_Mode_Tag {
    /*! - MAC Unsecured Mode Security */
    g_MAC_UNSECURED_MODE_c = (uint8_t) 0x00,

    /*! - MAC ACL Mode Security */
    g_MAC_ACL_MODE_c = (uint8_t) 0x01,

    /*! - MAC Secured Mode Security */
    g_MAC_SECURED_MODE_c = (uint8_t) 0x02
} MAC_Security_Mode_t;

/**
 * The maximum size of an MPDU, in octets, that can be
 * followed by a short interframe spacing (SIFS) period.
 * @ingroup apiMacConst
 */
#define aMaxSIFSFrameSize               (18)

/******************************************************************************/
/** @brief This enum contains all the mac pib Ids */
typedef enum MAC_Pib_Ids_Tag {
    /*! -Id of mac attribute mac_ack_wait_duration */
    g_MAC_ACK_WAIT_DURATION_c = (uint8_t) 0x40,

    /*! -Id of mac attribute mac_association_permit */
    g_MAC_ASSOCIATION_PERMIT_c = (uint8_t) 0x41,

    /*! -Id of mac attribute mac_auto_request */
    g_MAC_AUTO_REQUEST_c = (uint8_t) 0x42,

    /*! -Id of mac attribute mac_beacon_payload */
    g_MAC_BEACON_PAYLOAD_c = (uint8_t) 0x45,

    /*! -Id of mac attribute mac_beacon_payload_length */
    g_MAC_BEACON_PAYLOAD_LENGTH_c = (uint8_t) 0x46,

    /*! -Id of mac attribute mac_beacon_order */
    g_MAC_BEACON_ORDER_c = (uint8_t) 0x47,

    /*! -Id of mac attribute mac_bsn */
    g_MAC_BSN_c = (uint8_t) 0x49,

    /*! -Id of mac attribute mac_coord_extended_address */
    g_MAC_COORD_EXTENDED_ADDDRESS_c = (uint8_t) 0x4A,

    /*! -Id of mac attribute mac_coord_short_address */
    g_MAC_COORD_SHORT_ADDRESS_c = (uint8_t) 0x4B,

    /*! -Id of mac attribute mac_dsn */
    g_MAC_DSN_c = (uint8_t) 0x4C,

    /*! -Id of mac attribute mac_max_frame_total_wait_time */
    g_MAC_MAX_FRAME_TOTAL_WAIT_TIME_c = (uint8_t) 0x58,

    /*! -Id of mac attribute mac_max_frame_retries */
    g_MAC_MAX_FRAME_RETRIES_c = (uint8_t) 0x59,

    /*! -Id of mac attribute mac_pan_id */
    g_MAC_PAN_ID_c = (uint8_t) 0x50,

    /*! -Id of mac attribute mac_response_wait_time */
    g_MAC_RESPONSE_WAIT_TIME_c = (uint8_t) 0x5A,

    /*! -Id of mac attribute mac_rx_on_when_idle */
    g_MAC_RX_ON_WHEN_IDLE_c = (uint8_t) 0x52,

    /*! -Id of mac attribute mac_security_enabled */
    g_MAC_SECURITY_ENABLED_c = (uint8_t) 0x5D,

    /*! -Id of mac attribute mac_short_address */
    g_MAC_SHORT_ADDRESS_c = (uint8_t) 0x53,

    /*! -Id of mac attribute mac_superframe_order */
    g_MAC_SUPERFRAME_ORDER_c = (uint8_t) 0x54,

    /*! -Id of mac attribute mac_time_stamp_supported */
    g_MAC_TIMESTAMP_SUPPORTED_c = (uint8_t) 0x5C,

    /*! -Id of mac attribute mac_transaction_persistence_time */
    g_MAC_TRANSACTION_PERSISTENCE_TIME_c = (uint8_t) 0x55,

    /*! -Id of mac attribute mac_max_be */
    g_MAC_MAX_BE_c = (uint8_t) 0x57,

    /*! -Id of mac attribute mac_lifs */
    g_MAC_LIFS_PERIOD_c = (uint8_t) 0x5E,

    /*! -Id of mac attribute mac_sifs */
    g_MAC_SIFS_PERIOD_c = (uint8_t) 0x5F,

    /*! -Id of mac attribute mac_max_csma_backoffs */
    g_MAC_MAX_CSMA_BACKOFFS_c = (uint8_t) 0x4E,

    /*! -Id of mac attribute mac_min_be */
    g_MAC_MIN_BE_c = (uint8_t) 0x4F,

    /*! -Id of pan coordinator */
    g_MAC_PAN_COORDINATOR_c = (uint8_t) 0x10,

    /*! -Id of parent is a pan coordinator */
    g_MAC_ASSOC_PAN_COORDINATOR_c = (uint8_t) 0x11,

    /*! -Id of mac extended address */
    g_MAC_EXTENDED_ADDRESS_c = (uint8_t) 0x6F,

    /*! -Id for MAC ACL Entry */
    g_MAC_ACL_ENTRY_DESCRIPTOR_c = (uint8_t) 0x70,

    /*! -Id for No of ACL Security Descriptor Entries */
    g_MAC_ACL_ENTRY_DESCRIPTOR_SIZE_c = (uint8_t) 0x71,

    /*! -Id for MAC Default Security Support */
    g_MAC_DEFAULT_SECURITY_c = (uint8_t) 0x72,

    /*! -Id for MAC Default Security material length */
    g_MAC_DEFAULT_SECURITY_MATERIAL_LENGTH_c = (uint8_t) 0x73,

    /*! -Id for MAC Default Security Material */
    g_MAC_DEFAULT_SECURITY_MATERIAL_c = (uint8_t) 0x74,

    /*! -Id for MAC Default Security Suite */
    g_MAC_DEFAULT_SECURITY_SUITE_c = (uint8_t) 0x75,

    /*! -Id for MAC Security Mode */
    g_MAC_SECURITY_MODE_c = (uint8_t) 0x76,

    /*! - Proprietary Id for Current number of ACL Entries  */
    g_MAC_CURRENT_ACL_ENTRIES_c = (uint8_t) 0x80,

    /*! - Proprietary Id for Default MAC Security Extended Address  */
    g_MAC_DEFAULT_SECURITY_EXTENDED_ADDRESS_c = (uint8_t) 0x81,

    /*! - Proprietary Id for Default MAC Security Extended Address  */
    g_MAC_ASSOCIATED_PAN_COORDINATOR_c = (uint8_t) 0x56,

#ifdef GENMAC_CERTIF_DEDICATED_ATTRIB
    /*! - Proprietary Id to force FC frameType field to 'Reserved'  */
    g_MAC_CERTIF_SET_FC_RESERVED_FRAME_c = (uint8_t) 0x90,
    /*! - Proprietary Id to force FC security field to 'Enabled'  */
    g_MAC_CERTIF_SET_FC_SECURITY_FRAME_c = (uint8_t) 0x91,
#endif
} MAC_Pib_Ids_t;

/******************************************************************************/
/** @brief This enum indicates the type of scan to be performed */
typedef enum MAC_Scan_Types_Tag {
    /*! -ED Scan */
    g_MAC_ED_SCAN_TYPE_c = (uint8_t) 0x00,

    /*! -Active Scan */
    g_MAC_ACTIVE_SCAN_TYPE_c,

    /*! -Passive Scan */
    g_MAC_PASSIVE_SCAN_TYPE_c,

    /*! -Orphan Scan */
    g_MAC_ORPHAN_SCAN_TYPE_c
} MAC_Scan_Types_t;

#endif /* _INC_802_15_4_MAC_CONFIG_H_ */
