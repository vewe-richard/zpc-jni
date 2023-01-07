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

#ifndef ZWAVE_COMMAND_CLASS_BATTERY_HANDLERS_H
#define ZWAVE_COMMAND_CLASS_BATTERY_HANDLERS_H

/**
 * @ingroup command_classes
*/

/**
 * @defgroup COMMAND_CLASS_BATTERY_handler Command handlers for COMMAND_CLASS_BATTERY
 * @brief Functions for controlling COMMAND_CLASS_BATTERY
 * 
 * This module implement functions for generating and parsing the Z-Wave frames
 * for controlling COMMAND_CLASS_BATTERY. The module builds frames by reading data from the
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
  COMMAND_CLASS_BATTERY_VERSION [ label="COMMAND_CLASS_BATTERY_VERSION\nV0\nget:", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BATTERY_BATTERY_LEVEL [ label="BATTERY_BATTERY_LEVEL\nV1\nget:BATTERY_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BATTERY_REPLACE_RECHARGE [ label="BATTERY_REPLACE_RECHARGE\nV2\nget:BATTERY_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BATTERY_CHARGING_STATUS [ label="BATTERY_CHARGING_STATUS\nV2\nget:BATTERY_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BATTERY_HEALTH_MAXIMUM_CAPACITY [ label="BATTERY_HEALTH_MAXIMUM_CAPACITY\nV2\nget:BATTERY_HEALTH_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BATTERY_HEALTH_SCALE [ label="BATTERY_HEALTH_SCALE\nV2\nget:BATTERY_HEALTH_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BATTERY_HEALTH_PRECISION [ label="BATTERY_HEALTH_PRECISION\nV2\nget:BATTERY_HEALTH_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  BATTERY_HEALTH_BATTERY_TEMPERATURE [ label="BATTERY_HEALTH_BATTERY_TEMPERATURE\nV2\nget:BATTERY_HEALTH_GET", shape="ellipse" ]

  ep -> COMMAND_CLASS_BATTERY_VERSION
  ep -> BATTERY_BATTERY_LEVEL
  ep -> BATTERY_REPLACE_RECHARGE
  ep -> BATTERY_CHARGING_STATUS
  ep -> BATTERY_HEALTH_MAXIMUM_CAPACITY
  ep -> BATTERY_HEALTH_SCALE
  ep -> BATTERY_HEALTH_PRECISION
  ep -> BATTERY_HEALTH_BATTERY_TEMPERATURE
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
 * @brief Version of COMMAND_CLASS_BATTERY which this handlers is genrated for
 * 
 */
#define COMMAND_CLASS_BATTERY_VERSION 3


/**
 * @brief Initialisation of COMMAND_CLASS_BATTERY
 * 
 * This function registers the command handler with the attribute resolver 
 * and the command handler framework.
 * 
 */
sl_status_t zwave_COMMAND_CLASS_BATTERY_init();


/**
 * @brief Override function for BATTERY_REPORT
 * 
 * This if this function is implemented as a weak symbol. This provided
 * such an external component can modifiy the behaviour of the generated 
 * code.
 * 
 * @return If not SL_STATUS_OK the auto generated hander is executed after this.
 */
sl_status_t  zwave_BATTERY_REPORT_handle_report_command_override(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length) ;
/**
 * @brief Override function for BATTERY_HEALTH_REPORT
 * 
 * This if this function is implemented as a weak symbol. This provided
 * such an external component can modifiy the behaviour of the generated 
 * code.
 * 
 * @return If not SL_STATUS_OK the auto generated hander is executed after this.
 */
sl_status_t  zwave_BATTERY_HEALTH_REPORT_handle_report_command_override(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length) ;

/**
 * @brief Override function for BATTERY_GET
 * 
 * This if this function is implemented as a weak symbol. This provided such an
 * external component can modify the behaviour of the auto generated code. 
 * @param _node Attribute to genrate the get frame from.
 * @param frame Pointer to frame data which should be written into
 * @param frame_len Length of the generated frame. I this is 0 on exit the auto
 * generated code is executed otherwise it is not.
 * @return Return code to send to the resolver.
 */

sl_status_t zwave_BATTERY_GET_override(
  attribute_store_node_t  _node, uint8_t *frame, uint16_t *frame_len);
/**
 * @brief Override function for BATTERY_HEALTH_GET
 * 
 * This if this function is implemented as a weak symbol. This provided such an
 * external component can modify the behaviour of the auto generated code. 
 * @param _node Attribute to genrate the get frame from.
 * @param frame Pointer to frame data which should be written into
 * @param frame_len Length of the generated frame. I this is 0 on exit the auto
 * generated code is executed otherwise it is not.
 * @return Return code to send to the resolver.
 */

sl_status_t zwave_BATTERY_HEALTH_GET_override(
  attribute_store_node_t  _node, uint8_t *frame, uint16_t *frame_len);



#ifdef __cplusplus
}
#endif

#endif  //ZWAVE_HANDLERS_COMMAND_CLASS_BATTERY_H
/** @} end zwave_handlers.h */

