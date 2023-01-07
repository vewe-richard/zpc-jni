/******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

#ifndef ZWAVE_COMMAND_CLASS_BASIC_TARIFF_INFO_HANDLERS_H
#define ZWAVE_COMMAND_CLASS_BASIC_TARIFF_INFO_HANDLERS_H

/**
 * @ingroup command_classes
*/

/**
 * @defgroup COMMAND_CLASS_BASIC_TARIFF_INFO_handler Command handlers for COMMAND_CLASS_BASIC_TARIFF_INFO
 * @brief Functions for controlling COMMAND_CLASS_BASIC_TARIFF_INFO
 * 
 * This module implement functions for generating and parsing the Z-Wave frames
 * for controlling COMMAND_CLASS_BASIC_TARIFF_INFO. The module builds frames by reading data from the
 * attribute according to the tree data model shown below. When data is received 
 * is will also update the attribute store with data again according the the model 
 * described below.
 * 
 * In addition the module will react on the on_version update events from the
 * attribute store to and insert required attributes into to attribute store. A 
 * set of helper functions  for inserting attribute for more complex data is also 
 * provided. The complex data are generally data dependign on some sort of index.
 *
 * 
@dot
digraph G {
  rankdir=LR;
  splines="ortho";
  ep [ label="endpoint", shape="box"]
  COMMAND_CLASS_BASIC_TARIFF_INFO_VERSION [ label="COMMAND_CLASS_BASIC_TARIFF_INFO_VERSION\nV0\nget:", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BASIC_TARIFF_INFO_TOTAL_NO_IMPORT_RATES [ label="BASIC_TARIFF_INFO_TOTAL_NO_IMPORT_RATES\nV1\nget:BASIC_TARIFF_INFO_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BASIC_TARIFF_INFO_E_CURRENT_RATE_IN_USE [ label="BASIC_TARIFF_INFO_E_CURRENT_RATE_IN_USE\nV1\nget:BASIC_TARIFF_INFO_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BASIC_TARIFF_INFO_E_RATE_CONSUMPTION_REGISTER [ label="BASIC_TARIFF_INFO_E_RATE_CONSUMPTION_REGISTER\nV1\nget:BASIC_TARIFF_INFO_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_HOURS [ label="BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_HOURS\nV1\nget:BASIC_TARIFF_INFO_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_MINUTES [ label="BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_MINUTES\nV1\nget:BASIC_TARIFF_INFO_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_SECONDS [ label="BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_SECONDS\nV1\nget:BASIC_TARIFF_INFO_GET", shape="ellipse" ]

  ep -> COMMAND_CLASS_BASIC_TARIFF_INFO_VERSION
  ep -> BASIC_TARIFF_INFO_TOTAL_NO_IMPORT_RATES
  ep -> BASIC_TARIFF_INFO_E_CURRENT_RATE_IN_USE
  ep -> BASIC_TARIFF_INFO_E_RATE_CONSUMPTION_REGISTER
  ep -> BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_HOURS
  ep -> BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_MINUTES
  ep -> BASIC_TARIFF_INFO_E_TIME_FOR_NEXT_RATE_SECONDS
}
@enddot

@{
*/
#ifdef __cplusplus
extern "C" {
#endif
#include "attribute_store.h"
#include "sl_status.h"



/**
 * @brief Version of COMMAND_CLASS_BASIC_TARIFF_INFO which this handlers is genrated for
 * 
 */
#define COMMAND_CLASS_BASIC_TARIFF_INFO_VERSION 1


/**
 * @brief Initialisation of COMMAND_CLASS_BASIC_TARIFF_INFO
 * 
 * This function registers the command handler with the attribute resolver 
 * and the command handler framework.
 * 
 */
sl_status_t zwave_COMMAND_CLASS_BASIC_TARIFF_INFO_init();


/**
 * @brief Override function for BASIC_TARIFF_INFO_REPORT
 * 
 * This if this function is implemented as a weak symbol. This provided
 * such an external component can modifiy the behaviour of the generated 
 * code.
 * 
 * @return If not SL_STATUS_OK the auto generated hander is executed after this.
 */
sl_status_t  zwave_BASIC_TARIFF_INFO_REPORT_handle_report_command_override(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length) ;

/**
 * @brief Override function for BASIC_TARIFF_INFO_GET
 * 
 * This if this function is implemented as a weak symbol. This provided such an
 * external component can modify the behaviour of the auto generated code. 
 * @param _node Attribute to genrate the get frame from.
 * @param frame Pointer to frame data which should be written into
 * @param frame_len Length of the generated frame. I this is 0 on exit the auto
 * generated code is executed otherwise it is not.
 * @return Return code to send to the resolver.
 */

sl_status_t zwave_BASIC_TARIFF_INFO_GET_override(
  attribute_store_node_t  _node, uint8_t *frame, uint16_t *frame_len);



#ifdef __cplusplus
}
#endif

#endif  //ZWAVE_HANDLERS_COMMAND_CLASS_BASIC_TARIFF_INFO_H
/** @} end zwave_handlers.h */

