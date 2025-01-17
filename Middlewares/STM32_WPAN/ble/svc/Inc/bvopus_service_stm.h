/**
  ******************************************************************************
  * @file    bluevoice_opus.h
  * @author  SRA-A&SP
  * @version V1.0.0
  * @date    08-May-2019
  * @brief   This file contains definitions for BlueVoiceOPUS service.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2019 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BVOPUS_SERVICE_STM_H
#define __BVOPUS_SERVICE_STM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "opus.h"
#include "string.h"  
#include "opus_private.h"
#include "ble_gatt_aci.h"
#include "opus_interface_stm.h"

/*!< Return states values. */
typedef enum 
{
  BV_OPUS_SUCCESS = 0x00,                       /*!< Success.*/
  BV_OPUS_ERROR = 0x01,                         /*!< Error.*/
  BV_OPUS_TIMEOUT = 0x02,                       /*!< A BLE timeout occurred.*/
  BV_OPUS_TX_HANDLE_NOT_AVAILABLE = 0x10,       /*!< TX BlueVoiceOPUS characteristics handle not set.*/
  BV_OPUS_NOTIF_DISABLE = 0x11,                 /*!< The notifications are disabled.*/
  BV_OPUS_INVALID_PARAM = 0x12,                 /*!< Invalid Opus parameters.*/
  BV_OPUS_ENC_NOT_CONFIG = 0x13,                /*!< BlueVoiceOPUS encoder not configured.*/
  BV_OPUS_DEC_NOT_CONFIG = 0x14,                /*!< BlueVoiceOPUS decoder not configured.*/
  BV_OPUS_PKT_NOT_COMPLETE = 0x15,              /*!< Received Opus packet not completed.*/
} BV_OPUS_Status;

/*!< BVOPUS control event type. */
typedef enum
{
  BVOPUS_STM_START_STREAMING_EVT,               /*!< Requested to start audio streaming.*/
  BVOPUS_STM_STOP_STREAMING_EVT,                /*!< Requested to stop audio streaming.*/
  BVOPUS_STM_ENABLE_CTRL_EVT,                   /*!< Control char enabled.*/
  BVOPUS_STM_DISABLE_CTRL_EVT,                  /*!< Control char disable.*/
  BVOPUS_STM_ERROR_EVT,                         /*!< Error.*/
} BVOPUS_STM_evt_code_t;

/*!< BlueVoice service and characteristics uuid. */
typedef struct
{
  Service_UUID_t service_uuid;          /*!< Service UUID.*/
  Char_UUID_t audio_uuid;               /*!< Audio characteristic UUID.*/
  Char_UUID_t ctrl_uuid;                /*!< Control characteristic UUID.*/  
} BV_OPUS_uuid_t;

/*!<  BlueVoiceOPUS service and characteristics handle. */
typedef struct
{
  uint16_t ServiceHandle;               /*!< Service handle.*/
  uint16_t CharAudioHandle;             /*!< Audio characteristic handle.*/ 
  uint16_t CharCtrlHandle;              /*!< Control characteristic handle.*/
} BV_OPUS_ProfileHandle_t;


/* Define --------------------------------------------------------------------*/

/*!< BlueNRG low-level communication timeout.*/      
#define BV_OPUS_SENDING_TIMEOUT                 0xFF                  

/*!<  Control message type */
#define BV_OPUS_CONTROL                         (uint8_t)0x0A  
#define BV_OPUS_ENABLE_NOTIF_REQ                (uint8_t)0x10
#define BV_OPUS_DISABLE_NOTIF_REQ               (uint8_t)0x11

/* External constant ---------------------------------------------------------*/
extern const uint8_t bvopus_service_uuid[16];
extern const uint8_t bvopus_audio_char_uuid[16];
extern const uint8_t bvopus_ctrl_char_uuid[16];
 
/* Function prototype --------------------------------------------------------*/

/**
* @brief  Called when a Start or Stop streaming event occurs.
* @param  Evt_code: start or stop streaming event.
* @retval None.
*/
void BVOPUS_STM_APP_Notification(BVOPUS_STM_evt_code_t Evt_code);

/**
 * @brief  BlueVoice Opus Service initialization
 * @param  None
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
void BVOPUS_STM_Init(void);

/**
 * @brief  This function initializes Opus encoder.
 * @param  Opus encoder configuration.
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
BV_OPUS_Status BVOPUS_CodecEncInit(OPUS_IF_ENC_ConfigTypeDef *ENC_configOpus);

/**
 * @brief  This function initializes Opus decoder.
 * @param  Opus decoder configuration.
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
BV_OPUS_Status BVOPUS_CodecDecInit(OPUS_IF_DEC_ConfigTypeDef *DEC_configOpus);

/**
 * @brief  This function returns the audio notification status.
 * @param  None.
 * @retval 1 if audio notification are enabled, 0 otherwise.
 */
uint8_t BluevoiceOPUS_isAudioNotifEnabled(void);

/**
 * @brief  This function returns the control notification status.
 * @param  None.
 * @retval 1 if the control notification are enabled, 0 otherwise.
 */
uint8_t BluevoiceOPUS_isCtrlNotifEnabled(void);

/**
 * @brief  This function is called to decode audio data using opus.
 * @param  buf_in: pointer to the encoded buffer.
 * @param  len_in: buffer in length.
 * @param  buf_out: pointer to the decoded buffer.
 * @param  pcm_samples: number of PCM samples decoded.
 * @param  opus_err: @ref opus_errorcodes.
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
BV_OPUS_Status BluevoiceOPUS_ParseData(uint8_t *buf_in, uint8_t len_in, uint8_t *buf_out, uint16_t *pcm_samples, int *opus_err);

/**
 * @brief  This function is called to packetize, encode and send audio data.
 * @param  data_buffer: data to be sent
 * @param  opus_err: @ref opus_errorcodes.
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
BV_OPUS_Status BluevoiceOPUS_SendAudioData(uint8_t *data_buffer, int *opus_err);

/**
 * @brief  This function is called to send control command.
 * @param  data_buffer: data to be sent
 * @param  Nb_bytes: number of bytes to be sent (max 20)
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
BV_OPUS_Status BluevoiceOPUS_SendCtrlData(uint8_t *data_buffer, uint8_t Nb_bytes);

/**
 * @brief  This function is called to send an enable notification request.
 * @param  None
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
BV_OPUS_Status BluevoiceOPUS_SendEnableNotifReq(void);

/**
 * @brief  This function is called to send a disable notification request.
 * @param  None
 * @retval BV_OPUS_Status: Value indicating success or error code.
 */
BV_OPUS_Status BluevoiceOPUS_SendDisableNotifReq(void);


#ifdef __cplusplus
}
#endif

#endif /* __BVOPUS_SERVICE_STM_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
