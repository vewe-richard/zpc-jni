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
#define LOG_TAG "zwave_COMMAND_CLASS_ZWAVEPLUS_INFO"

#include "zwave_COMMAND_CLASS_ZWAVEPLUS_INFO_attribute_id.h"
#include "zwave_COMMAND_CLASS_ZWAVEPLUS_INFO_handlers.h"

using namespace attribute_store;

///////////////////////////////////////////////////////////////////////////////
// Private functions, used to handle individual incoming commands.
///////////////////////////////////////////////////////////////////////////////

// Override functions

sl_status_t  __attribute__((weak)) zwave_ZWAVEPLUS_INFO_REPORT_handle_report_command_override(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length)
{
  return SL_STATUS_IDLE;
}

sl_status_t  __attribute__((weak)) zwave_ZWAVEPLUS_INFO_GET_override(
  attribute_store_node_t   _node, uint8_t *frame, uint16_t *frame_len)
{
  *frame_len = 0;
  return SL_STATUS_IDLE;
}


/**
 * Generators for COMMAND_CLASS_ZWAVEPLUS_INFO_GET Commands
 */

static sl_status_t zwave_ZWAVEPLUS_INFO_GET(
  attribute_store_node_t _node, uint8_t *frame, uint16_t *frame_len)
{
   sl_status_t rc = zwave_ZWAVEPLUS_INFO_GET_override(_node, frame, frame_len);
   if( *frame_len > 0 ) {
     return rc;
  }  

  try {
    uint8_t offset=0;
    uint8_t size=0;
    uint8_t param_offsets[255] = {0}; // To avoid -Wno-maybe-uninitialized

    attribute node(_node);
    attribute parent = node.first_parent(ATTRIBUTE_ENDPOINT_ID);

    frame[offset++] = 0x5E;
    frame[offset++] = 0x01; // ZWAVEPLUS_INFO_GET
    *frame_len = offset;
    return SL_STATUS_OK;
  } catch(const std::exception& e) {
    sl_log_debug(LOG_TAG, "%s: %s", __func__, e.what());
    return SL_STATUS_FAIL;
  }
}

/**
 * Generators for COMMAND_CLASS_ZWAVEPLUS_INFO_SET Commands
 */


/**
 * Handles incoming COMMAND_CLASS_ZWAVEPLUS_INFO_REPORT Commands
 */

static sl_status_t zwave_ZWAVEPLUS_INFO_REPORT_handle_report_command(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame,
  uint16_t frame_length)
{
  if( zwave_ZWAVEPLUS_INFO_REPORT_handle_report_command_override(connection_info,frame,frame_length) == SL_STATUS_OK)  {
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

    // parameter name: Z-Wave+ Version, type: BYTE, length: 1, key: 0x00,
    // fieldmask: 0xff, shifter: 0
    value = (frame[offset] & 0xff) >> 0;
    node = parent.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_Z_WAVE_VERSION);
    size = 1;
    if( !node.is_valid() ) {
      sl_log_debug(LOG_TAG,"Unable to locate ZWAVEPLUS_INFO_Z_WAVE_VERSION attribute (may not be a problem).");
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
    // parameter name: Role Type, type: CONST, length: 1, key: 0x01,
    // fieldmask: 0xff, shifter: 0
    value = (frame[offset] & 0xff) >> 0;
    node = parent.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_ROLE_TYPE);
    size = 1;
    if( !node.is_valid() ) {
      sl_log_debug(LOG_TAG,"Unable to locate ZWAVEPLUS_INFO_ROLE_TYPE attribute (may not be a problem).");
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
    param_offsets[0x01] = offset; offset += size;
    // parameter name: Node Type, type: CONST, length: 1, key: 0x02,
    // fieldmask: 0xff, shifter: 0
    value = (frame[offset] & 0xff) >> 0;
    node = parent.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_NODE_TYPE);
    size = 1;
    if( !node.is_valid() ) {
      sl_log_debug(LOG_TAG,"Unable to locate ZWAVEPLUS_INFO_NODE_TYPE attribute (may not be a problem).");
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
    param_offsets[0x02] = offset; offset += size;
    // parameter name: Installer Icon Type, type: WORD, length: 2, key: 0x03,
    // fieldmask: 0xff, shifter: 0
    value = (frame[offset] & 0xff) >> 0;
    node = parent.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_INSTALLER_ICON_TYPE);
    size = 2;
    if( !node.is_valid() ) {
      sl_log_debug(LOG_TAG,"Unable to locate ZWAVEPLUS_INFO_INSTALLER_ICON_TYPE attribute (may not be a problem).");
    } else {
      //Check if there is more data
    if( (offset + 2) > frame_length) {
      node.set_reported<int32_t>(0);
    }
    else { // If we sill have frame data
    
    
     value = (frame[offset] << 8) | (frame[offset+1]);
      node.set_reported<int32_t>(value);
    
    
    
    }
    node.clear_desired();
    }
    param_offsets[0x03] = offset; offset += size;
    // parameter name: User Icon Type, type: WORD, length: 2, key: 0x04,
    // fieldmask: 0xff, shifter: 0
    value = (frame[offset] & 0xff) >> 0;
    node = parent.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_USER_ICON_TYPE);
    size = 2;
    if( !node.is_valid() ) {
      sl_log_debug(LOG_TAG,"Unable to locate ZWAVEPLUS_INFO_USER_ICON_TYPE attribute (may not be a problem).");
    } else {
      //Check if there is more data
    if( (offset + 2) > frame_length) {
      node.set_reported<int32_t>(0);
    }
    else { // If we sill have frame data
    
    
     value = (frame[offset] << 8) | (frame[offset+1]);
      node.set_reported<int32_t>(value);
    
    
    
    }
    node.clear_desired();
    }
    param_offsets[0x04] = offset; offset += size;

    return SL_STATUS_OK;
  } catch(const std::exception& e) {
    sl_log_debug(LOG_TAG, "%s: %s", __func__, e.what());
    return SL_STATUS_FAIL;
  }
}

sl_status_t zwave_COMMAND_CLASS_ZWAVEPLUS_INFO_handler(
  const zwave_controller_connection_info_t *connection_info,
  const uint8_t *frame_data,
  uint16_t frame_length)
{
  if (frame_length < 2) {
    return SL_STATUS_NOT_SUPPORTED;
  }

  switch (frame_data[1]) {
    case 0x02: //ZWAVEPLUS_INFO_REPORT
      return zwave_ZWAVEPLUS_INFO_REPORT_handle_report_command(
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
 * Function that detects a new COMMAND_CLASS_ZWAVEPLUS_INFO and
 * creates the required Attributes for the COMMAND_CLASS_ZWAVEPLUS_INFO
 * sub-component.
 */
static void COMMAND_CLASS_ZWAVEPLUS_INFO_on_version_attribute_update(
  attribute_store_node_t _updated_node, attribute_store_change_t change)
{
  if (change != ATTRIBUTE_UPDATED) {
    return;
  }

  zwave_cc_version_t version      = 0;
  attribute updated_node(_updated_node);
  attribute endpoint_node = updated_node.first_parent(ATTRIBUTE_ENDPOINT_ID);


  if (is_zwave_command_class_filtered_for_root_device(
        0x5E, _updated_node) == true) {
    return;
  }

  try {
  version = updated_node.reported<zwave_cc_version_t>();
  } catch(std::invalid_argument& e) {
    return;
  }

  assert(ATTRIBUTE_COMMAND_CLASS_ZWAVEPLUS_INFO_VERSION == updated_node.type());

  if( version >= 0 )
  {
    attribute value_node = endpoint_node.child_by_type(ATTRIBUTE_COMMAND_CLASS_ZWAVEPLUS_INFO_VERSION);
    if( !value_node.is_valid() ) {
      endpoint_node.add_node(ATTRIBUTE_COMMAND_CLASS_ZWAVEPLUS_INFO_VERSION);
    }
  }
  if( version >= 1 )
  {
    attribute value_node = endpoint_node.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_Z_WAVE_VERSION);
    if( !value_node.is_valid() ) {
      endpoint_node.add_node(ATTRIBUTE_ZWAVEPLUS_INFO_Z_WAVE_VERSION);
    }
  }
  if( version >= 1 )
  {
    attribute value_node = endpoint_node.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_ROLE_TYPE);
    if( !value_node.is_valid() ) {
      endpoint_node.add_node(ATTRIBUTE_ZWAVEPLUS_INFO_ROLE_TYPE);
    }
  }
  if( version >= 1 )
  {
    attribute value_node = endpoint_node.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_NODE_TYPE);
    if( !value_node.is_valid() ) {
      endpoint_node.add_node(ATTRIBUTE_ZWAVEPLUS_INFO_NODE_TYPE);
    }
  }
  if( version >= 2 )
  {
    attribute value_node = endpoint_node.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_INSTALLER_ICON_TYPE);
    if( !value_node.is_valid() ) {
      endpoint_node.add_node(ATTRIBUTE_ZWAVEPLUS_INFO_INSTALLER_ICON_TYPE);
    }
  }
  if( version >= 2 )
  {
    attribute value_node = endpoint_node.child_by_type(ATTRIBUTE_ZWAVEPLUS_INFO_USER_ICON_TYPE);
    if( !value_node.is_valid() ) {
      endpoint_node.add_node(ATTRIBUTE_ZWAVEPLUS_INFO_USER_ICON_TYPE);
    }
  }
}


///////// Helper functions to create child attributes


///////////////////////////////////////////////////////////////////////////////
// Public interface functions
///////////////////////////////////////////////////////////////////////////////

sl_status_t zwave_COMMAND_CLASS_ZWAVEPLUS_INFO_init()
{
  attribute_resolver_register_rule(ATTRIBUTE_ZWAVEPLUS_INFO_Z_WAVE_VERSION,
    NULL, zwave_ZWAVEPLUS_INFO_GET
  );
  attribute_resolver_register_rule(ATTRIBUTE_ZWAVEPLUS_INFO_ROLE_TYPE,
    NULL, zwave_ZWAVEPLUS_INFO_GET
  );
  attribute_resolver_register_rule(ATTRIBUTE_ZWAVEPLUS_INFO_NODE_TYPE,
    NULL, zwave_ZWAVEPLUS_INFO_GET
  );
  attribute_resolver_register_rule(ATTRIBUTE_ZWAVEPLUS_INFO_INSTALLER_ICON_TYPE,
    NULL, zwave_ZWAVEPLUS_INFO_GET
  );
  attribute_resolver_register_rule(ATTRIBUTE_ZWAVEPLUS_INFO_USER_ICON_TYPE,
    NULL, zwave_ZWAVEPLUS_INFO_GET
  );

  attribute_store_register_callback_by_type(
    COMMAND_CLASS_ZWAVEPLUS_INFO_on_version_attribute_update,ATTRIBUTE_COMMAND_CLASS_ZWAVEPLUS_INFO_VERSION);

  // The support side of things: Register our handler to the Z-Wave CC framework:
  zwave_command_handler_t handler = {0};
  handler.support_handler         = nullptr;
  handler.control_handler         = zwave_COMMAND_CLASS_ZWAVEPLUS_INFO_handler;
  handler.command_class_name      = "Z-Wave Plus Info";
  handler.comments                = "Control Part is auto-generated.";
  // Not supported, so this does not really matter
  handler.minimal_scheme = ZWAVE_CONTROLLER_ENCAPSULATION_NETWORK_SCHEME;
  handler.command_class                     = 0x5E;
  handler.version                           = COMMAND_CLASS_ZWAVEPLUS_INFO_VERSION;
  handler.manual_security_validation        = false;

  zwave_command_handler_register_handler(handler);

  return SL_STATUS_OK;
}