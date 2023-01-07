/******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

#define ATTRIBUTE_AUTO_GENERATED


// Generic includes
#include <assert.h>
#include <stdlib.h>

// Includes from other components
#include "attribute.hpp"
#include "attribute_resolver.h"
#include "attribute_store_defined_attribute_types.h"
#include "attribute_store_helper.h"
#include "sl_log.h"
#include "zpc_attribute_store_network_helper.h"
#include "zwave_command_classes_utils.h"
#include "zwave_command_handler.h"
#include "zwave_unid.h"

// Log tag
#define LOG_TAG "zwave_COMMAND_CLASS_INDICATOR"

#include "zwave_COMMAND_CLASS_INDICATOR_attribute_id.h"
#include "zwave_COMMAND_CLASS_INDICATOR_handlers.h"

using namespace attribute_store;

///////////////////////////////////////////////////////////////////////////////
// Private functions, used to handle individual incoming commands.
///////////////////////////////////////////////////////////////////////////////

// Override functions

sl_status_t  __attribute__((weak)) zwave_INDICATOR_REPORT_handle_report_command_override(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length)
{
  return SL_STATUS_IDLE;
}
sl_status_t  __attribute__((weak)) zwave_INDICATOR_SUPPORTED_REPORT_handle_report_command_override(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length)
{
  return SL_STATUS_IDLE;
}

sl_status_t  __attribute__((weak)) zwave_INDICATOR_GET_override(
  attribute_store_node_t   _node, uint8_t *frame, uint16_t *frame_len)
{
  *frame_len = 0;
  return SL_STATUS_IDLE;
}
sl_status_t  __attribute__((weak)) zwave_INDICATOR_SUPPORTED_GET_override(
  attribute_store_node_t   _node, uint8_t *frame, uint16_t *frame_len)
{
  *frame_len = 0;
  return SL_STATUS_IDLE;
}

sl_status_t __attribute__((weak)) zwave_INDICATOR_SET_override(
  attribute_store_node_t    _node, uint8_t *frame, uint16_t *frame_len)
{
  *frame_len = 0;
  return SL_STATUS_IDLE;
}

/**
 * Generators for COMMAND_CLASS_INDICATOR_GET Commands
 */

static sl_status_t zwave_INDICATOR_GET(
  attribute_store_node_t _node, uint8_t *frame, uint16_t *frame_len)
{
   sl_status_t rc = zwave_INDICATOR_GET_override(_node, frame, frame_len);
   if( *frame_len > 0 ) {
     return rc;
  }  

  try {
    uint8_t offset=0;
    uint8_t size=0;
    uint8_t param_offsets[255] = {0}; // To avoid -Wno-maybe-uninitialized

    attribute node(_node);
    attribute parent = node.first_parent(ATTRIBUTE_ENDPOINT_ID);

    frame[offset++] = 0x87;
    frame[offset++] = 0x02; // INDICATOR_GET
    //parameter Indicator ID CONST
    node = parent.child_by_type(ATTRIBUTE_INDICATOR_INDICATOR_ID);
    //parameter is 1 bytes long
    node.get(REPORTED_ATTRIBUTE, &frame[offset], &size );
    param_offsets[0x00] = offset;  offset += 1;
    
    *frame_len = offset;
    return SL_STATUS_OK;
  } catch(const std::exception& e) {
    sl_log_debug(LOG_TAG, "%s: %s", __func__, e.what());
    return SL_STATUS_FAIL;
  }
}
static sl_status_t zwave_INDICATOR_SUPPORTED_GET(
  attribute_store_node_t _node, uint8_t *frame, uint16_t *frame_len)
{
   sl_status_t rc = zwave_INDICATOR_SUPPORTED_GET_override(_node, frame, frame_len);
   if( *frame_len > 0 ) {
     return rc;
  }  

  try {
    uint8_t offset=0;
    uint8_t size=0;
    uint8_t param_offsets[255] = {0}; // To avoid -Wno-maybe-uninitialized

    attribute node(_node);
    attribute parent = node.first_parent(ATTRIBUTE_ENDPOINT_ID);

    frame[offset++] = 0x87;
    frame[offset++] = 0x04; // INDICATOR_SUPPORTED_GET
    //parameter Indicator ID CONST
    node = parent.child_by_type(ATTRIBUTE_INDICATOR_INDICATOR_ID);
    //parameter is 1 bytes long
    node.get(REPORTED_ATTRIBUTE, &frame[offset], &size );
    param_offsets[0x00] = offset;  offset += 1;
    
    *frame_len = offset;
    return SL_STATUS_OK;
  } catch(const std::exception& e) {
    sl_log_debug(LOG_TAG, "%s: %s", __func__, e.what());
    return SL_STATUS_FAIL;
  }
}

/**
 * Generators for COMMAND_CLASS_INDICATOR_SET Commands
 */

static sl_status_t zwave_INDICATOR_SET(
  attribute_store_node_t _node, uint8_t *frame, uint16_t *frame_len)
{
   sl_status_t rc = zwave_INDICATOR_SET_override(_node, frame, frame_len);
   if( *frame_len > 0 ) {
     return rc;
  }  

  try {
    uint8_t offset = 0;
    uint8_t size = 0;
    uint8_t param_offsets[255] = {0}; // To avoid -Wno-maybe-uninitialized
    uint8_t param_key = 0;

    attribute node(_node);
    attribute parent = node.first_parent(ATTRIBUTE_ENDPOINT_ID);

    frame[offset++] = 0x87 ;
    frame[offset++] = 0x01; // INDICATOR_SET
    // parameter name: Indicator 0 Value type: BYTE
    node = parent.child_by_type(ATTRIBUTE_INDICATOR_INDICATOR_VALUE);
    node.get(DESIRED_OR_REPORTED_ATTRIBUTE, &frame[offset], &size );
    param_offsets[0x00] = offset;  offset += 1;
    
    // parameter name: Indicator Object Count type: 
    
    
    // parameter name: Reserved type: 
    
    param_offsets[param_key++] = offset; offset += 1;
    *frame_len = offset;
    return SL_STATUS_OK;
  } catch(const std::exception& e) {
    sl_log_debug(LOG_TAG, "%s: %s", __func__, e.what());
    return SL_STATUS_FAIL;
  }
}

/**
 * Handles incoming COMMAND_CLASS_INDICATOR_REPORT Commands
 */

static sl_status_t zwave_INDICATOR_REPORT_handle_report_command(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length)
{
  if( zwave_INDICATOR_REPORT_handle_report_command_override(connection_info,frame,frame_length) == SL_STATUS_OK)  {
    return SL_STATUS_OK;
  }

  try {
    // Find out the unid of the sending node:
    unid_t supporting_node_unid;
    attribute node;

    zwave_unid_from_node_id(connection_info->remote.node_id,
                            supporting_node_unid);

    // Get the corresponding Attribute Store entry for this unid / endpoint:
    attribute parent
      = attribute_store_network_helper_get_endpoint_node(
        supporting_node_unid,
        connection_info->remote.endpoint_id);

    int offset = 2;
    int param_offsets[255] = {0}; // To avoid -Wno-maybe-uninitialized
    int size = 0;
    int value;

    // parameter name: Indicator 0 Value, type: BYTE, length: 1, key: 0x00,
    // fieldmask: 0xff, shifter: 0
    value = (frame[offset] & 0xff) >> 0;
    node = parent.child_by_type(ATTRIBUTE_INDICATOR_INDICATOR_VALUE);
    size = 1;
    if( !node.is_valid() ) {
      sl_log_debug(LOG_TAG,"Unable to locate INDICATOR_INDICATOR_VALUE attribute (may not be a problem).");
    } else {
      //Check if there is more data
    if( (offset + 1) > frame_length) {
      node.set_reported<int32_t>(0);
    }
    else { // If we sill have frame data
    
     node.set_reported<int32_t>(value);
    
    
    
    
    }
    node.clear_desired();
    }
    param_offsets[0x00] = offset; offset += size;
    // parameter name: Indicator Object Count, type: , length: 0, key: 0x00,
    // fieldmask: 0x1F, shifter: 0
    param_offsets[0x00] = offset; offset += size;
    // parameter name: Reserved, type: , length: 0, key: 0x01,
    // fieldmask: 0xE0, shifter: 5
    param_offsets[0x01] = offset; offset += 1;

    return SL_STATUS_OK;
  } catch(const std::exception& e) {
    sl_log_debug(LOG_TAG, "%s: %s", __func__, e.what());
    return SL_STATUS_FAIL;
  }
}
static sl_status_t zwave_INDICATOR_SUPPORTED_REPORT_handle_report_command(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length)
{
  if( zwave_INDICATOR_SUPPORTED_REPORT_handle_report_command_override(connection_info,frame,frame_length) == SL_STATUS_OK)  {
    return SL_STATUS_OK;
  }

  try {
    // Find out the unid of the sending node:
    unid_t supporting_node_unid;
    attribute node;

    zwave_unid_from_node_id(connection_info->remote.node_id,
                            supporting_node_unid);

    // Get the corresponding Attribute Store entry for this unid / endpoint:
    attribute parent
      = attribute_store_network_helper_get_endpoint_node(
        supporting_node_unid,
        connection_info->remote.endpoint_id);

    int offset = 2;
    int param_offsets[255] = {0}; // To avoid -Wno-maybe-uninitialized
    int size = 0;
    int value;

    // parameter name: Indicator ID, type: CONST, length: 1, key: 0x00,
    // fieldmask: 0xff, shifter: 0
    value = (frame[offset] & 0xff) >> 0;
    parent = parent.child_by_type_and_value<uint8_t>(ATTRIBUTE_INDICATOR_INDICATOR_ID, value);
    if(!parent.is_valid()) {
      sl_log_debug(LOG_TAG, "Unable to locate INDICATOR_INDICATOR_ID attribute with value %i.", value);
    }
    param_offsets[0x00] = offset; offset += size;
    // parameter name: Next Indicator ID, type: CONST, length: 1, key: 0x01,
    // fieldmask: 0xff, shifter: 0
    param_offsets[0x01] = offset; offset += size;
    // parameter name: Property Supported Bit Mask Length, type: , length: 0, key: 0x00,
    // fieldmask: 0x1F, shifter: 0
    param_offsets[0x00] = offset; offset += size;
    // parameter name: Reserved, type: , length: 0, key: 0x01,
    // fieldmask: 0xE0, shifter: 5
    param_offsets[0x01] = offset; offset += 1;
    // parameter name: Property Supported Bit Mask, type: BITMASK, length: 1, key: 0x03,
    // fieldmask: 0xff, shifter: 0
    value = (frame[offset] & 0xff) >> 0;
    node = parent.child_by_type(ATTRIBUTE_INDICATOR_SUPPORTED_PROPERTY_SUPPORTED_BIT_MASK);
    size = 1;
    if( !node.is_valid() ) {
      sl_log_debug(LOG_TAG,"Unable to locate INDICATOR_SUPPORTED_PROPERTY_SUPPORTED_BIT_MASK attribute (may not be a problem).");
    } else {
      //Check if there is more data
    if( (offset + 1) > frame_length) {
      node.set_reported<int32_t>(0);
    }
    else { // If we sill have frame data
    
     node.set_reported<int32_t>(value);
    
    
    
    
    }
    node.clear_desired();
    }
    param_offsets[0x03] = offset; offset += size;

    return SL_STATUS_OK;
  } catch(const std::exception& e) {
    sl_log_debug(LOG_TAG, "%s: %s", __func__, e.what());
    return SL_STATUS_FAIL;
  }
}

sl_status_t zwave_COMMAND_CLASS_INDICATOR_handler(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame_data,
  uint16_t frame_length)
{
  if (frame_length < 2) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  switch (frame_data[1]) {
    case 0x03: //INDICATOR_REPORT
      return zwave_INDICATOR_REPORT_handle_report_command(
        connection_info,
        frame_data,
        frame_length);
      break;
    case 0x05: //INDICATOR_SUPPORTED_REPORT
      return zwave_INDICATOR_SUPPORTED_REPORT_handle_report_command(
        connection_info,
        frame_data,
        frame_length);
      break;
    default:
      return SL_STATUS_NOT_SUPPORTED;
      break;
  }
}

/**
 * Function that detects a new COMMAND_CLASS_INDICATOR and
 * creates the required Attributes for the COMMAND_CLASS_INDICATOR
 * sub-component.
 */
static void COMMAND_CLASS_INDICATOR_on_version_attribute_update(
  attribute_store_node_t _updated_node, attribute_store_change_t change)
{
  if (change != ATTRIBUTE_UPDATED) {
    return;
  }

  zwave_cc_version_t version      = 0;
  attribute updated_node(_updated_node);
  attribute endpoint_node = updated_node.first_parent(ATTRIBUTE_ENDPOINT_ID);


  if (is_zwave_command_class_filtered_for_root_device(
        0x87, _updated_node) == true) {
    return;
  }

  try {
  version = updated_node.reported<zwave_cc_version_t>();
  } catch(std::invalid_argument& e) {
    return;
  }

  assert(ATTRIBUTE_COMMAND_CLASS_INDICATOR_VERSION == updated_node.type());

  if( version >= 0 )
  {
    attribute value_node = endpoint_node.child_by_type(ATTRIBUTE_COMMAND_CLASS_INDICATOR_VERSION);
    if( !value_node.is_valid() ) {
      endpoint_node.add_node(ATTRIBUTE_COMMAND_CLASS_INDICATOR_VERSION);
    }
  }
      // parent INDICATOR_PROPERTY_ID
  //Skipped INDICATOR_INDICATOR_ID
      // parent INDICATOR_INDICATOR_ID
      // parent INDICATOR_INDICATOR_ID
}


///////// Helper functions to create child attributes

void zwave_COMMAND_CLASS_INDICATOR_add_INDICATOR_INDICATOR_ID( attribute_store_node_t __parent, uint8_t val ) {
  attribute parent(__parent);
  attribute ep = parent.first_parent( ATTRIBUTE_ENDPOINT_ID );
  attribute version = ep.child_by_type(ATTRIBUTE_COMMAND_CLASS_INDICATOR_VERSION);
  attribute node = parent.add_node( ATTRIBUTE_INDICATOR_INDICATOR_ID );

  node.set_reported<uint8_t>(val);

  if( version.reported<uint8_t>() >= 2 )
  {
    attribute value_node = node.child_by_type(ATTRIBUTE_INDICATOR_PROPERTY_ID);
    if(! value_node.is_valid()) {
      node.add_node(ATTRIBUTE_INDICATOR_PROPERTY_ID);
    }
  }
  if( version.reported<uint8_t>() >= 2 )
  {
    attribute value_node = node.child_by_type(ATTRIBUTE_INDICATOR_SUPPORTED_PROPERTY_SUPPORTED_BIT_MASK);
    if(! value_node.is_valid()) {
      node.add_node(ATTRIBUTE_INDICATOR_SUPPORTED_PROPERTY_SUPPORTED_BIT_MASK);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
// Public interface functions
///////////////////////////////////////////////////////////////////////////////

sl_status_t zwave_COMMAND_CLASS_INDICATOR_init()
{
  attribute_resolver_register_rule(ATTRIBUTE_INDICATOR_INDICATOR_VALUE,
    zwave_INDICATOR_SET, zwave_INDICATOR_GET
  );
  // ATTRIBUTE_INDICATOR_INDICATOR_ID skipped because its a parameter
  attribute_resolver_register_rule(ATTRIBUTE_INDICATOR_PROPERTY_ID,
    zwave_INDICATOR_SET, zwave_INDICATOR_GET
  );
  attribute_resolver_register_rule(ATTRIBUTE_INDICATOR_SUPPORTED_PROPERTY_SUPPORTED_BIT_MASK,
    NULL, zwave_INDICATOR_SUPPORTED_GET
  );

  attribute_store_register_callback_by_type(
    COMMAND_CLASS_INDICATOR_on_version_attribute_update,ATTRIBUTE_COMMAND_CLASS_INDICATOR_VERSION);

  // The support side of things: Register our handler to the Z-Wave CC framework:
  zwave_command_handler_t handler = {0};
  handler.support_handler         = nullptr;
  handler.control_handler         = zwave_COMMAND_CLASS_INDICATOR_handler;
  handler.command_class_name      = "Indicator";
  handler.comments                = "Control Part is auto-generated.";
  // Not supported, so this does not really matter
  handler.minimal_scheme = ZWAVE_CONTROLLER_ENCAPSULATION_NETWORK_SCHEME;
  handler.command_class                     = 0x87;
  handler.version                           = COMMAND_CLASS_INDICATOR_VERSION;
  handler.manual_security_validation        = false;

  zwave_command_handler_register_handler(handler);

  return SL_STATUS_OK;
}