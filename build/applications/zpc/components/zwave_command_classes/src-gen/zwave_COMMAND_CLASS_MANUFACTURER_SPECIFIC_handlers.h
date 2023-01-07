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

#ifndef ZWAVE_COMMAND_CLASS_MANUFACTURER_SPECIFIC_HANDLERS_H
#define ZWAVE_COMMAND_CLASS_MANUFACTURER_SPECIFIC_HANDLERS_H

/**
 * @ingroup command_classes
*/

/**
 * @defgroup COMMAND_CLASS_MANUFACTURER_SPECIFIC_handler Command handlers for COMMAND_CLASS_MANUFACTURER_SPECIFIC
 * @brief Functions for controlling COMMAND_CLASS_MANUFACTURER_SPECIFIC
 * 
 * This module implement functions for generating and parsing the Z-Wave frames
 * for controlling COMMAND_CLASS_MANUFACTURER_SPECIFIC. The module builds frames by reading data from the
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
  COMMAND_CLASS_MANUFACTURER_SPECIFIC_VERSION [ label="COMMAND_CLASS_MANUFACTURER_SPECIFIC_VERSION\nV0\nget:", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  MANUFACTURER_SPECIFIC_MANUFACTURER_ID [ label="MANUFACTURER_SPECIFIC_MANUFACTURER_ID\nV1\nget:MANUFACTURER_SPECIFIC_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  MANUFACTURER_SPECIFIC_PRODUCT_TYPE_ID [ label="MANUFACTURER_SPECIFIC_PRODUCT_TYPE_ID\nV1\nget:MANUFACTURER_SPECIFIC_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  MANUFACTURER_SPECIFIC_PRODUCT_ID [ label="MANUFACTURER_SPECIFIC_PRODUCT_ID\nV1\nget:MANUFACTURER_SPECIFIC_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  DEVICE_SPECIFIC_DEVICE_ID_TYPE [ label="DEVICE_SPECIFIC_DEVICE_ID_TYPE\nV2\nget:DEVICE_SPECIFIC_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  DEVICE_SPECIFIC_DEVICE_ID_DATA_LENGTH_INDICATOR [ label="DEVICE_SPECIFIC_DEVICE_ID_DATA_LENGTH_INDICATOR\nV2\nget:DEVICE_SPECIFIC_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  DEVICE_SPECIFIC_DEVICE_ID_DATA_FORMAT [ label="DEVICE_SPECIFIC_DEVICE_ID_DATA_FORMAT\nV2\nget:DEVICE_SPECIFIC_GET", shape="ellipse" ]
  ep [ label="endpoint", shape="box"]
  DEVICE_SPECIFIC_DEVICE_ID_DATA [ label="DEVICE_SPECIFIC_DEVICE_ID_DATA\nV2\nget:DEVICE_SPECIFIC_GET", shape="ellipse" ]

  ep -> COMMAND_CLASS_MANUFACTURER_SPECIFIC_VERSION
  ep -> MANUFACTURER_SPECIFIC_MANUFACTURER_ID
  ep -> MANUFACTURER_SPECIFIC_PRODUCT_TYPE_ID
  ep -> MANUFACTURER_SPECIFIC_PRODUCT_ID
  ep -> DEVICE_SPECIFIC_DEVICE_ID_TYPE
  DEVICE_SPECIFIC_DEVICE_ID_TYPE -> DEVICE_SPECIFIC_DEVICE_ID_DATA_LENGTH_INDICATOR 
  DEVICE_SPECIFIC_DEVICE_ID_TYPE -> DEVICE_SPECIFIC_DEVICE_ID_DATA_FORMAT 
  DEVICE_SPECIFIC_DEVICE_ID_TYPE -> DEVICE_SPECIFIC_DEVICE_ID_DATA 
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
 * @brief Version of COMMAND_CLASS_MANUFACTURER_SPECIFIC which this handlers is genrated for
 * 
 */
#define COMMAND_CLASS_MANUFACTURER_SPECIFIC_VERSION 2

/**
 * @brief Add DEVICE_SPECIFIC_DEVICE_ID_TYPE and its mandatory children to a parent
 * 
 * This function will add an attribute of type DEVICE_SPECIFIC_DEVICE_ID_TYPE under the given parent
 * attribute. The value of the new attribute set to index, and the manetory
 * children are also created under the new attribute, considering the commad
 * class version.
 * 
 * @param parent attribute store node to add children to.
 * @param index Index of the new attribute subtree to created
 */
void zwave_COMMAND_CLASS_MANUFACTURER_SPECIFIC_add_DEVICE_SPECIFIC_DEVICE_ID_TYPE( attribute_store_node_t parent, uint8_t index );

/**
 * @brief Initialisation of COMMAND_CLASS_MANUFACTURER_SPECIFIC
 * 
 * This function registers the command handler with the attribute resolver 
 * and the command handler framework.
 * 
 */
sl_status_t zwave_COMMAND_CLASS_MANUFACTURER_SPECIFIC_init();


/**
 * @brief Override function for MANUFACTURER_SPECIFIC_REPORT
 * 
 * This if this function is implemented as a weak symbol. This provided
 * such an external component can modifiy the behaviour of the generated 
 * code.
 * 
 * @return If not SL_STATUS_OK the auto generated hander is executed after this.
 */
sl_status_t  zwave_MANUFACTURER_SPECIFIC_REPORT_handle_report_command_override(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length) ;
/**
 * @brief Override function for DEVICE_SPECIFIC_REPORT
 * 
 * This if this function is implemented as a weak symbol. This provided
 * such an external component can modifiy the behaviour of the generated 
 * code.
 * 
 * @return If not SL_STATUS_OK the auto generated hander is executed after this.
 */
sl_status_t  zwave_DEVICE_SPECIFIC_REPORT_handle_report_command_override(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length) ;

/**
 * @brief Override function for MANUFACTURER_SPECIFIC_GET
 * 
 * This if this function is implemented as a weak symbol. This provided such an
 * external component can modify the behaviour of the auto generated code. 
 * @param _node Attribute to genrate the get frame from.
 * @param frame Pointer to frame data which should be written into
 * @param frame_len Length of the generated frame. I this is 0 on exit the auto
 * generated code is executed otherwise it is not.
 * @return Return code to send to the resolver.
 */

sl_status_t zwave_MANUFACTURER_SPECIFIC_GET_override(
  attribute_store_node_t  _node, uint8_t *frame, uint16_t *frame_len);
/**
 * @brief Override function for DEVICE_SPECIFIC_GET
 * 
 * This if this function is implemented as a weak symbol. This provided such an
 * external component can modify the behaviour of the auto generated code. 
 * @param _node Attribute to genrate the get frame from.
 * @param frame Pointer to frame data which should be written into
 * @param frame_len Length of the generated frame. I this is 0 on exit the auto
 * generated code is executed otherwise it is not.
 * @return Return code to send to the resolver.
 */

sl_status_t zwave_DEVICE_SPECIFIC_GET_override(
  attribute_store_node_t  _node, uint8_t *frame, uint16_t *frame_len);



#ifdef __cplusplus
}
#endif

#endif  //ZWAVE_HANDLERS_COMMAND_CLASS_MANUFACTURER_SPECIFIC_H
/** @} end zwave_handlers.h */

