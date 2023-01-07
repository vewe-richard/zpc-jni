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

#ifndef DOTDOT_MQTT_TRANSLATORS_H
#define DOTDOT_MQTT_TRANSLATORS_H
#include <sstream>
#include <string>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace bpt = boost::property_tree;

struct constCharPtrTranslator {
  typedef std::string internal_type;
  typedef const char* external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    return boost::optional<external_type>(str.c_str());
  }

  boost::optional<internal_type> put_value(const external_type& e)
  {
    return boost::optional<internal_type>(std::string(e));
  }
};

struct ArmArmModeTranslator {
  typedef std::string internal_type;
  typedef ArmArmMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Disarm", ZCL_ARM_ARM_MODE_DISARM },
        { "ArmDayHomeZonesOnly", ZCL_ARM_ARM_MODE_ARM_DAY_HOME_ZONES_ONLY },
        { "ArmNightSleepZonesOnly", ZCL_ARM_ARM_MODE_ARM_NIGHT_SLEEP_ZONES_ONLY },
        { "ArmAllZones", ZCL_ARM_ARM_MODE_ARM_ALL_ZONES }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ARM_ARM_MODE_DISARM, "Disarm" },
      { ZCL_ARM_ARM_MODE_ARM_DAY_HOME_ZONES_ONLY, "ArmDayHomeZonesOnly" },
      { ZCL_ARM_ARM_MODE_ARM_NIGHT_SLEEP_ZONES_ONLY, "ArmNightSleepZonesOnly" },
      { ZCL_ARM_ARM_MODE_ARM_ALL_ZONES, "ArmAllZones" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ArmResponseArmNotificationTranslator {
  typedef std::string internal_type;
  typedef ArmResponseArmNotification   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "AllZonesDisarmed", ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ALL_ZONES_DISARMED },
        { "OnlyDayHomeZonesArmed", ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ONLY_DAY_HOME_ZONES_ARMED },
        { "OnlyNightSleepZonesArmed", ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ONLY_NIGHT_SLEEP_ZONES_ARMED },
        { "AllZonesArmed", ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ALL_ZONES_ARMED },
        { "InvalidArmDisarmCode", ZCL_ARM_RESPONSE_ARM_NOTIFICATION_INVALID_ARM_DISARM_CODE },
        { "NotReadyToArm", ZCL_ARM_RESPONSE_ARM_NOTIFICATION_NOT_READY_TO_ARM },
        { "AlreadyDisarmed", ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ALREADY_DISARMED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ALL_ZONES_DISARMED, "AllZonesDisarmed" },
      { ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ONLY_DAY_HOME_ZONES_ARMED, "OnlyDayHomeZonesArmed" },
      { ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ONLY_NIGHT_SLEEP_ZONES_ARMED, "OnlyNightSleepZonesArmed" },
      { ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ALL_ZONES_ARMED, "AllZonesArmed" },
      { ZCL_ARM_RESPONSE_ARM_NOTIFICATION_INVALID_ARM_DISARM_CODE, "InvalidArmDisarmCode" },
      { ZCL_ARM_RESPONSE_ARM_NOTIFICATION_NOT_READY_TO_ARM, "NotReadyToArm" },
      { ZCL_ARM_RESPONSE_ARM_NOTIFICATION_ALREADY_DISARMED, "AlreadyDisarmed" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct BarrierControlMovingStateTranslator {
  typedef std::string internal_type;
  typedef BarrierControlMovingState   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Stopped", ZCL_BARRIER_CONTROL_MOVING_STATE_STOPPED },
        { "Closing", ZCL_BARRIER_CONTROL_MOVING_STATE_CLOSING },
        { "Opening", ZCL_BARRIER_CONTROL_MOVING_STATE_OPENING }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_BARRIER_CONTROL_MOVING_STATE_STOPPED, "Stopped" },
      { ZCL_BARRIER_CONTROL_MOVING_STATE_CLOSING, "Closing" },
      { ZCL_BARRIER_CONTROL_MOVING_STATE_OPENING, "Opening" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct BasicGenericDeviceClassTranslator {
  typedef std::string internal_type;
  typedef BasicGenericDeviceClass   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Lighting", ZCL_BASIC_GENERIC_DEVICE_CLASS_LIGHTING }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_BASIC_GENERIC_DEVICE_CLASS_LIGHTING, "Lighting" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct BasicGenericDeviceTypeTranslator {
  typedef std::string internal_type;
  typedef BasicGenericDeviceType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Incandescent", ZCL_BASIC_GENERIC_DEVICE_TYPE_INCANDESCENT },
        { "SpotlightHalogen", ZCL_BASIC_GENERIC_DEVICE_TYPE_SPOTLIGHT_HALOGEN },
        { "HalogenBulb", ZCL_BASIC_GENERIC_DEVICE_TYPE_HALOGEN_BULB },
        { "CFL", ZCL_BASIC_GENERIC_DEVICE_TYPE_CFL },
        { "LinearFluorescent", ZCL_BASIC_GENERIC_DEVICE_TYPE_LINEAR_FLUORESCENT },
        { "LEDBulb", ZCL_BASIC_GENERIC_DEVICE_TYPE_LED_BULB },
        { "SpotlightLED", ZCL_BASIC_GENERIC_DEVICE_TYPE_SPOTLIGHT_LED },
        { "LEDStrip", ZCL_BASIC_GENERIC_DEVICE_TYPE_LED_STRIP },
        { "LEDTube", ZCL_BASIC_GENERIC_DEVICE_TYPE_LED_TUBE },
        { "GenericIndoorLuminaireOrLightFixture", ZCL_BASIC_GENERIC_DEVICE_TYPE_GENERIC_INDOOR_LUMINAIRE_OR_LIGHT_FIXTURE },
        { "GenericOutdoorLuminaireOrLightFixture", ZCL_BASIC_GENERIC_DEVICE_TYPE_GENERIC_OUTDOOR_LUMINAIRE_OR_LIGHT_FIXTURE },
        { "PendantLuminaireOrLightFixture", ZCL_BASIC_GENERIC_DEVICE_TYPE_PENDANT_LUMINAIRE_OR_LIGHT_FIXTURE },
        { "FloorStandingLuminaireOrLightFixture", ZCL_BASIC_GENERIC_DEVICE_TYPE_FLOOR_STANDING_LUMINAIRE_OR_LIGHT_FIXTURE },
        { "GenericController", ZCL_BASIC_GENERIC_DEVICE_TYPE_GENERIC_CONTROLLER },
        { "WallSwitch", ZCL_BASIC_GENERIC_DEVICE_TYPE_WALL_SWITCH },
        { "PortableRemoteController", ZCL_BASIC_GENERIC_DEVICE_TYPE_PORTABLE_REMOTE_CONTROLLER },
        { "MotionSensorOrLightSensor", ZCL_BASIC_GENERIC_DEVICE_TYPE_MOTION_SENSOR_OR_LIGHT_SENSOR },
        { "GenericActuator", ZCL_BASIC_GENERIC_DEVICE_TYPE_GENERIC_ACTUATOR },
        { "WallSocket", ZCL_BASIC_GENERIC_DEVICE_TYPE_WALL_SOCKET },
        { "GatewayOrBridge", ZCL_BASIC_GENERIC_DEVICE_TYPE_GATEWAY_OR_BRIDGE },
        { "PlugInUnit", ZCL_BASIC_GENERIC_DEVICE_TYPE_PLUG_IN_UNIT },
        { "RetrofitActuator", ZCL_BASIC_GENERIC_DEVICE_TYPE_RETROFIT_ACTUATOR },
        { "Unspecified", ZCL_BASIC_GENERIC_DEVICE_TYPE_UNSPECIFIED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_INCANDESCENT, "Incandescent" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_SPOTLIGHT_HALOGEN, "SpotlightHalogen" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_HALOGEN_BULB, "HalogenBulb" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_CFL, "CFL" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_LINEAR_FLUORESCENT, "LinearFluorescent" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_LED_BULB, "LEDBulb" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_SPOTLIGHT_LED, "SpotlightLED" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_LED_STRIP, "LEDStrip" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_LED_TUBE, "LEDTube" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_GENERIC_INDOOR_LUMINAIRE_OR_LIGHT_FIXTURE, "GenericIndoorLuminaireOrLightFixture" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_GENERIC_OUTDOOR_LUMINAIRE_OR_LIGHT_FIXTURE, "GenericOutdoorLuminaireOrLightFixture" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_PENDANT_LUMINAIRE_OR_LIGHT_FIXTURE, "PendantLuminaireOrLightFixture" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_FLOOR_STANDING_LUMINAIRE_OR_LIGHT_FIXTURE, "FloorStandingLuminaireOrLightFixture" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_GENERIC_CONTROLLER, "GenericController" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_WALL_SWITCH, "WallSwitch" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_PORTABLE_REMOTE_CONTROLLER, "PortableRemoteController" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_MOTION_SENSOR_OR_LIGHT_SENSOR, "MotionSensorOrLightSensor" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_GENERIC_ACTUATOR, "GenericActuator" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_WALL_SOCKET, "WallSocket" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_GATEWAY_OR_BRIDGE, "GatewayOrBridge" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_PLUG_IN_UNIT, "PlugInUnit" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_RETROFIT_ACTUATOR, "RetrofitActuator" },
      { ZCL_BASIC_GENERIC_DEVICE_TYPE_UNSPECIFIED, "Unspecified" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct BasicPhysicalEnvironmentTranslator {
  typedef std::string internal_type;
  typedef BasicPhysicalEnvironment   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "UnspecifiedEnvironment", ZCL_BASIC_PHYSICAL_ENVIRONMENT_UNSPECIFIED_ENVIRONMENT },
        { "Deprecated", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DEPRECATED },
        { "Bar", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BAR },
        { "Courtyard", ZCL_BASIC_PHYSICAL_ENVIRONMENT_COURTYARD },
        { "Bathroom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BATHROOM },
        { "Bedroom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BEDROOM },
        { "BilliardRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BILLIARD_ROOM },
        { "UtilityRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_UTILITY_ROOM },
        { "Cellar", ZCL_BASIC_PHYSICAL_ENVIRONMENT_CELLAR },
        { "StorageCloset", ZCL_BASIC_PHYSICAL_ENVIRONMENT_STORAGE_CLOSET },
        { "Theater", ZCL_BASIC_PHYSICAL_ENVIRONMENT_THEATER },
        { "Office", ZCL_BASIC_PHYSICAL_ENVIRONMENT_OFFICE },
        { "Deck", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DECK },
        { "Den", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DEN },
        { "DiningRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DINING_ROOM },
        { "ElectricalRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_ELECTRICAL_ROOM },
        { "Elevator", ZCL_BASIC_PHYSICAL_ENVIRONMENT_ELEVATOR },
        { "Entry", ZCL_BASIC_PHYSICAL_ENVIRONMENT_ENTRY },
        { "FamilyRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_FAMILY_ROOM },
        { "MainFloor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_MAIN_FLOOR },
        { "Upstairs", ZCL_BASIC_PHYSICAL_ENVIRONMENT_UPSTAIRS },
        { "Downstairs", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DOWNSTAIRS },
        { "Basement/LowerLevel", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BASEMENT_LOWER_LEVEL },
        { "Gallery", ZCL_BASIC_PHYSICAL_ENVIRONMENT_GALLERY },
        { "GameRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_GAME_ROOM },
        { "Garage", ZCL_BASIC_PHYSICAL_ENVIRONMENT_GARAGE },
        { "Gym", ZCL_BASIC_PHYSICAL_ENVIRONMENT_GYM },
        { "Hallway", ZCL_BASIC_PHYSICAL_ENVIRONMENT_HALLWAY },
        { "House", ZCL_BASIC_PHYSICAL_ENVIRONMENT_HOUSE },
        { "Kitchen", ZCL_BASIC_PHYSICAL_ENVIRONMENT_KITCHEN },
        { "LaundryRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_LAUNDRY_ROOM },
        { "Library", ZCL_BASIC_PHYSICAL_ENVIRONMENT_LIBRARY },
        { "MasterBedroom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_MASTER_BEDROOM },
        { "MudRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_MUD_ROOM },
        { "Nursery", ZCL_BASIC_PHYSICAL_ENVIRONMENT_NURSERY },
        { "Pantry", ZCL_BASIC_PHYSICAL_ENVIRONMENT_PANTRY },
        { "SecondaryOffice", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SECONDARY_OFFICE },
        { "Outside", ZCL_BASIC_PHYSICAL_ENVIRONMENT_OUTSIDE },
        { "Pool", ZCL_BASIC_PHYSICAL_ENVIRONMENT_POOL },
        { "Porch", ZCL_BASIC_PHYSICAL_ENVIRONMENT_PORCH },
        { "SewingRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SEWING_ROOM },
        { "SittingRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SITTING_ROOM },
        { "Stairway", ZCL_BASIC_PHYSICAL_ENVIRONMENT_STAIRWAY },
        { "Yard", ZCL_BASIC_PHYSICAL_ENVIRONMENT_YARD },
        { "Attic", ZCL_BASIC_PHYSICAL_ENVIRONMENT_ATTIC },
        { "HotTub", ZCL_BASIC_PHYSICAL_ENVIRONMENT_HOT_TUB },
        { "LivingRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_LIVING_ROOM },
        { "Sauna", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SAUNA },
        { "ShopOrWorkshop", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SHOP_OR_WORKSHOP },
        { "GuestBedroom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_GUEST_BEDROOM },
        { "GuestBath", ZCL_BASIC_PHYSICAL_ENVIRONMENT_GUEST_BATH },
        { "PowderRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_POWDER_ROOM },
        { "BackYard", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BACK_YARD },
        { "FrontYard", ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRONT_YARD },
        { "Patio", ZCL_BASIC_PHYSICAL_ENVIRONMENT_PATIO },
        { "Driveway", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DRIVEWAY },
        { "SunRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SUN_ROOM },
        { "SecondaryLivingRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SECONDARY_LIVING_ROOM },
        { "Spa", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SPA },
        { "Whirlpool", ZCL_BASIC_PHYSICAL_ENVIRONMENT_WHIRLPOOL },
        { "Shed", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SHED },
        { "EquipmentStorage", ZCL_BASIC_PHYSICAL_ENVIRONMENT_EQUIPMENT_STORAGE },
        { "HobbyOrCraftRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_HOBBY_OR_CRAFT_ROOM },
        { "Fountain", ZCL_BASIC_PHYSICAL_ENVIRONMENT_FOUNTAIN },
        { "Pond", ZCL_BASIC_PHYSICAL_ENVIRONMENT_POND },
        { "ReceptionRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_RECEPTION_ROOM },
        { "BreakfastRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BREAKFAST_ROOM },
        { "Nook", ZCL_BASIC_PHYSICAL_ENVIRONMENT_NOOK },
        { "Garden", ZCL_BASIC_PHYSICAL_ENVIRONMENT_GARDEN },
        { "Balcony", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BALCONY },
        { "PanicRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_PANIC_ROOM },
        { "Terrace", ZCL_BASIC_PHYSICAL_ENVIRONMENT_TERRACE },
        { "Roof", ZCL_BASIC_PHYSICAL_ENVIRONMENT_ROOF },
        { "Toilet", ZCL_BASIC_PHYSICAL_ENVIRONMENT_TOILET },
        { "ToiletMain", ZCL_BASIC_PHYSICAL_ENVIRONMENT_TOILET_MAIN },
        { "OutsideToilet", ZCL_BASIC_PHYSICAL_ENVIRONMENT_OUTSIDE_TOILET },
        { "ShowerRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_SHOWER_ROOM },
        { "Study", ZCL_BASIC_PHYSICAL_ENVIRONMENT_STUDY },
        { "FrontGarden", ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRONT_GARDEN },
        { "BackGarden", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BACK_GARDEN },
        { "Kettle", ZCL_BASIC_PHYSICAL_ENVIRONMENT_KETTLE },
        { "Television", ZCL_BASIC_PHYSICAL_ENVIRONMENT_TELEVISION },
        { "Stove", ZCL_BASIC_PHYSICAL_ENVIRONMENT_STOVE },
        { "Microwave", ZCL_BASIC_PHYSICAL_ENVIRONMENT_MICROWAVE },
        { "Toaster", ZCL_BASIC_PHYSICAL_ENVIRONMENT_TOASTER },
        { "Vacuum", ZCL_BASIC_PHYSICAL_ENVIRONMENT_VACUUM },
        { "Appliance", ZCL_BASIC_PHYSICAL_ENVIRONMENT_APPLIANCE },
        { "FrontDoor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRONT_DOOR },
        { "BackDoor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_BACK_DOOR },
        { "FridgeDoor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRIDGE_DOOR },
        { "MedicationCabinetDoor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_MEDICATION_CABINET_DOOR },
        { "WardrobeDoor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_WARDROBE_DOOR },
        { "FrontCupboardDoor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRONT_CUPBOARD_DOOR },
        { "OtherDoor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_OTHER_DOOR },
        { "WaitingRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_WAITING_ROOM },
        { "TriageRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_TRIAGE_ROOM },
        { "DoctorsOffice", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DOCTORS_OFFICE },
        { "PatientsPrivateRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_PATIENTS_PRIVATE_ROOM },
        { "ConsultationRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_CONSULTATION_ROOM },
        { "NurseStation", ZCL_BASIC_PHYSICAL_ENVIRONMENT_NURSE_STATION },
        { "Ward", ZCL_BASIC_PHYSICAL_ENVIRONMENT_WARD },
        { "Corridor", ZCL_BASIC_PHYSICAL_ENVIRONMENT_CORRIDOR },
        { "OperatingTheatre", ZCL_BASIC_PHYSICAL_ENVIRONMENT_OPERATING_THEATRE },
        { "DentalSurgeryRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DENTAL_SURGERY_ROOM },
        { "MedicalImagingRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_MEDICAL_IMAGING_ROOM },
        { "DecontaminationRoom", ZCL_BASIC_PHYSICAL_ENVIRONMENT_DECONTAMINATION_ROOM },
        { "Atrium", ZCL_BASIC_PHYSICAL_ENVIRONMENT_ATRIUM },
        { "Mirror", ZCL_BASIC_PHYSICAL_ENVIRONMENT_MIRROR },
        { "UnknownEnvironment", ZCL_BASIC_PHYSICAL_ENVIRONMENT_UNKNOWN_ENVIRONMENT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_UNSPECIFIED_ENVIRONMENT, "UnspecifiedEnvironment" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DEPRECATED, "Deprecated" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BAR, "Bar" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_COURTYARD, "Courtyard" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BATHROOM, "Bathroom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BEDROOM, "Bedroom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BILLIARD_ROOM, "BilliardRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_UTILITY_ROOM, "UtilityRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_CELLAR, "Cellar" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_STORAGE_CLOSET, "StorageCloset" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_THEATER, "Theater" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_OFFICE, "Office" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DECK, "Deck" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DEN, "Den" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DINING_ROOM, "DiningRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_ELECTRICAL_ROOM, "ElectricalRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_ELEVATOR, "Elevator" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_ENTRY, "Entry" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_FAMILY_ROOM, "FamilyRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_MAIN_FLOOR, "MainFloor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_UPSTAIRS, "Upstairs" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DOWNSTAIRS, "Downstairs" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BASEMENT_LOWER_LEVEL, "Basement/LowerLevel" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_GALLERY, "Gallery" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_GAME_ROOM, "GameRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_GARAGE, "Garage" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_GYM, "Gym" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_HALLWAY, "Hallway" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_HOUSE, "House" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_KITCHEN, "Kitchen" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_LAUNDRY_ROOM, "LaundryRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_LIBRARY, "Library" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_MASTER_BEDROOM, "MasterBedroom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_MUD_ROOM, "MudRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_NURSERY, "Nursery" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_PANTRY, "Pantry" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SECONDARY_OFFICE, "SecondaryOffice" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_OUTSIDE, "Outside" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_POOL, "Pool" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_PORCH, "Porch" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SEWING_ROOM, "SewingRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SITTING_ROOM, "SittingRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_STAIRWAY, "Stairway" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_YARD, "Yard" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_ATTIC, "Attic" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_HOT_TUB, "HotTub" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_LIVING_ROOM, "LivingRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SAUNA, "Sauna" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SHOP_OR_WORKSHOP, "ShopOrWorkshop" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_GUEST_BEDROOM, "GuestBedroom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_GUEST_BATH, "GuestBath" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_POWDER_ROOM, "PowderRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BACK_YARD, "BackYard" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRONT_YARD, "FrontYard" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_PATIO, "Patio" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DRIVEWAY, "Driveway" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SUN_ROOM, "SunRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SECONDARY_LIVING_ROOM, "SecondaryLivingRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SPA, "Spa" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_WHIRLPOOL, "Whirlpool" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SHED, "Shed" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_EQUIPMENT_STORAGE, "EquipmentStorage" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_HOBBY_OR_CRAFT_ROOM, "HobbyOrCraftRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_FOUNTAIN, "Fountain" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_POND, "Pond" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_RECEPTION_ROOM, "ReceptionRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BREAKFAST_ROOM, "BreakfastRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_NOOK, "Nook" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_GARDEN, "Garden" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BALCONY, "Balcony" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_PANIC_ROOM, "PanicRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_TERRACE, "Terrace" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_ROOF, "Roof" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_TOILET, "Toilet" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_TOILET_MAIN, "ToiletMain" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_OUTSIDE_TOILET, "OutsideToilet" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_SHOWER_ROOM, "ShowerRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_STUDY, "Study" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRONT_GARDEN, "FrontGarden" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BACK_GARDEN, "BackGarden" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_KETTLE, "Kettle" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_TELEVISION, "Television" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_STOVE, "Stove" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_MICROWAVE, "Microwave" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_TOASTER, "Toaster" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_VACUUM, "Vacuum" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_APPLIANCE, "Appliance" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRONT_DOOR, "FrontDoor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_BACK_DOOR, "BackDoor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRIDGE_DOOR, "FridgeDoor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_MEDICATION_CABINET_DOOR, "MedicationCabinetDoor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_WARDROBE_DOOR, "WardrobeDoor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_FRONT_CUPBOARD_DOOR, "FrontCupboardDoor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_OTHER_DOOR, "OtherDoor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_WAITING_ROOM, "WaitingRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_TRIAGE_ROOM, "TriageRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DOCTORS_OFFICE, "DoctorsOffice" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_PATIENTS_PRIVATE_ROOM, "PatientsPrivateRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_CONSULTATION_ROOM, "ConsultationRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_NURSE_STATION, "NurseStation" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_WARD, "Ward" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_CORRIDOR, "Corridor" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_OPERATING_THEATRE, "OperatingTheatre" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DENTAL_SURGERY_ROOM, "DentalSurgeryRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_MEDICAL_IMAGING_ROOM, "MedicalImagingRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_DECONTAMINATION_ROOM, "DecontaminationRoom" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_ATRIUM, "Atrium" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_MIRROR, "Mirror" },
      { ZCL_BASIC_PHYSICAL_ENVIRONMENT_UNKNOWN_ENVIRONMENT, "UnknownEnvironment" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct BasicPowerSourceTranslator {
  typedef std::string internal_type;
  typedef BasicPowerSource   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Unknown", ZCL_BASIC_POWER_SOURCE_UNKNOWN },
        { "SinglePhaseMains", ZCL_BASIC_POWER_SOURCE_SINGLE_PHASE_MAINS },
        { "ThreePhaseMains", ZCL_BASIC_POWER_SOURCE_THREE_PHASE_MAINS },
        { "Battery", ZCL_BASIC_POWER_SOURCE_BATTERY },
        { "DCSource", ZCL_BASIC_POWER_SOURCE_DC_SOURCE },
        { "EmergencyMainsConstantlyPowered", ZCL_BASIC_POWER_SOURCE_EMERGENCY_MAINS_CONSTANTLY_POWERED },
        { "EmergencyMainsAndTransferSwitch", ZCL_BASIC_POWER_SOURCE_EMERGENCY_MAINS_AND_TRANSFER_SWITCH },
        { "UnknownWithBatteryBackup", ZCL_BASIC_POWER_SOURCE_UNKNOWN_WITH_BATTERY_BACKUP },
        { "SinglePhaseMainsWithBatteryBackup", ZCL_BASIC_POWER_SOURCE_SINGLE_PHASE_MAINS_WITH_BATTERY_BACKUP },
        { "ThreePhaseMainsWithBatteryBackup", ZCL_BASIC_POWER_SOURCE_THREE_PHASE_MAINS_WITH_BATTERY_BACKUP },
        { "BatteryWithBatteryBackup", ZCL_BASIC_POWER_SOURCE_BATTERY_WITH_BATTERY_BACKUP },
        { "DCSourceWithBatteryBackup", ZCL_BASIC_POWER_SOURCE_DC_SOURCE_WITH_BATTERY_BACKUP },
        { "EmergencyMainsConstantlyPoweredWithBatteryBackup", ZCL_BASIC_POWER_SOURCE_EMERGENCY_MAINS_CONSTANTLY_POWERED_WITH_BATTERY_BACKUP },
        { "EmergencyMainsAndTransferSwitchWithBatteryBackup", ZCL_BASIC_POWER_SOURCE_EMERGENCY_MAINS_AND_TRANSFER_SWITCH_WITH_BATTERY_BACKUP }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_BASIC_POWER_SOURCE_UNKNOWN, "Unknown" },
      { ZCL_BASIC_POWER_SOURCE_SINGLE_PHASE_MAINS, "SinglePhaseMains" },
      { ZCL_BASIC_POWER_SOURCE_THREE_PHASE_MAINS, "ThreePhaseMains" },
      { ZCL_BASIC_POWER_SOURCE_BATTERY, "Battery" },
      { ZCL_BASIC_POWER_SOURCE_DC_SOURCE, "DCSource" },
      { ZCL_BASIC_POWER_SOURCE_EMERGENCY_MAINS_CONSTANTLY_POWERED, "EmergencyMainsConstantlyPowered" },
      { ZCL_BASIC_POWER_SOURCE_EMERGENCY_MAINS_AND_TRANSFER_SWITCH, "EmergencyMainsAndTransferSwitch" },
      { ZCL_BASIC_POWER_SOURCE_UNKNOWN_WITH_BATTERY_BACKUP, "UnknownWithBatteryBackup" },
      { ZCL_BASIC_POWER_SOURCE_SINGLE_PHASE_MAINS_WITH_BATTERY_BACKUP, "SinglePhaseMainsWithBatteryBackup" },
      { ZCL_BASIC_POWER_SOURCE_THREE_PHASE_MAINS_WITH_BATTERY_BACKUP, "ThreePhaseMainsWithBatteryBackup" },
      { ZCL_BASIC_POWER_SOURCE_BATTERY_WITH_BATTERY_BACKUP, "BatteryWithBatteryBackup" },
      { ZCL_BASIC_POWER_SOURCE_DC_SOURCE_WITH_BATTERY_BACKUP, "DCSourceWithBatteryBackup" },
      { ZCL_BASIC_POWER_SOURCE_EMERGENCY_MAINS_CONSTANTLY_POWERED_WITH_BATTERY_BACKUP, "EmergencyMainsConstantlyPoweredWithBatteryBackup" },
      { ZCL_BASIC_POWER_SOURCE_EMERGENCY_MAINS_AND_TRANSFER_SWITCH_WITH_BATTERY_BACKUP, "EmergencyMainsAndTransferSwitchWithBatteryBackup" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct BatterySizeTranslator {
  typedef std::string internal_type;
  typedef BatterySize   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "NoBattery", ZCL_BATTERY_SIZE_NO_BATTERY },
        { "BuiltIn", ZCL_BATTERY_SIZE_BUILT_IN },
        { "Other", ZCL_BATTERY_SIZE_OTHER },
        { "AA", ZCL_BATTERY_SIZE_AA },
        { "AAA", ZCL_BATTERY_SIZE_AAA },
        { "C", ZCL_BATTERY_SIZE_C },
        { "D", ZCL_BATTERY_SIZE_D },
        { "CR2", ZCL_BATTERY_SIZE_CR2 },
        { "CR123A", ZCL_BATTERY_SIZE_CR123_A },
        { "Unknown", ZCL_BATTERY_SIZE_UNKNOWN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_BATTERY_SIZE_NO_BATTERY, "NoBattery" },
      { ZCL_BATTERY_SIZE_BUILT_IN, "BuiltIn" },
      { ZCL_BATTERY_SIZE_OTHER, "Other" },
      { ZCL_BATTERY_SIZE_AA, "AA" },
      { ZCL_BATTERY_SIZE_AAA, "AAA" },
      { ZCL_BATTERY_SIZE_C, "C" },
      { ZCL_BATTERY_SIZE_D, "D" },
      { ZCL_BATTERY_SIZE_CR2, "CR2" },
      { ZCL_BATTERY_SIZE_CR123_A, "CR123A" },
      { ZCL_BATTERY_SIZE_UNKNOWN, "Unknown" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct BypassResponseZoneIDBypassResultTranslator {
  typedef std::string internal_type;
  typedef BypassResponseZoneIDBypassResult   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "ZoneBypassed", ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_ZONE_BYPASSED },
        { "ZoneNotBypassed", ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_ZONE_NOT_BYPASSED },
        { "NotAllowed", ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_NOT_ALLOWED },
        { "InvalidZoneID", ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_INVALID_ZONE_ID },
        { "UnknownZoneID", ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_UNKNOWN_ZONE_ID },
        { "InvalidArmDisarmCode", ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_INVALID_ARM_DISARM_CODE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_ZONE_BYPASSED, "ZoneBypassed" },
      { ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_ZONE_NOT_BYPASSED, "ZoneNotBypassed" },
      { ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_NOT_ALLOWED, "NotAllowed" },
      { ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_INVALID_ZONE_ID, "InvalidZoneID" },
      { ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_UNKNOWN_ZONE_ID, "UnknownZoneID" },
      { ZCL_BYPASS_RESPONSE_ZONE_ID_BYPASS_RESULT_INVALID_ARM_DISARM_CODE, "InvalidArmDisarmCode" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct CCColorLoopDirectionTranslator {
  typedef std::string internal_type;
  typedef CCColorLoopDirection   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "DecrementEnhancedCurrentHue", ZCL_CC_COLOR_LOOP_DIRECTION_DECREMENT_ENHANCED_CURRENT_HUE },
        { "IncrementEnhancedCurrentHue", ZCL_CC_COLOR_LOOP_DIRECTION_INCREMENT_ENHANCED_CURRENT_HUE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_CC_COLOR_LOOP_DIRECTION_DECREMENT_ENHANCED_CURRENT_HUE, "DecrementEnhancedCurrentHue" },
      { ZCL_CC_COLOR_LOOP_DIRECTION_INCREMENT_ENHANCED_CURRENT_HUE, "IncrementEnhancedCurrentHue" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct CCDirectionTranslator {
  typedef std::string internal_type;
  typedef CCDirection   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "ShortestDistance", ZCL_CC_DIRECTION_SHORTEST_DISTANCE },
        { "LongestDistance", ZCL_CC_DIRECTION_LONGEST_DISTANCE },
        { "Up", ZCL_CC_DIRECTION_UP },
        { "Down", ZCL_CC_DIRECTION_DOWN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_CC_DIRECTION_SHORTEST_DISTANCE, "ShortestDistance" },
      { ZCL_CC_DIRECTION_LONGEST_DISTANCE, "LongestDistance" },
      { ZCL_CC_DIRECTION_UP, "Up" },
      { ZCL_CC_DIRECTION_DOWN, "Down" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct CCMoveModeTranslator {
  typedef std::string internal_type;
  typedef CCMoveMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Stop", ZCL_CC_MOVE_MODE_STOP },
        { "Up", ZCL_CC_MOVE_MODE_UP },
        { "Down", ZCL_CC_MOVE_MODE_DOWN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_CC_MOVE_MODE_STOP, "Stop" },
      { ZCL_CC_MOVE_MODE_UP, "Up" },
      { ZCL_CC_MOVE_MODE_DOWN, "Down" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct CCStepModeTranslator {
  typedef std::string internal_type;
  typedef CCStepMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Up", ZCL_CC_STEP_MODE_UP },
        { "Down", ZCL_CC_STEP_MODE_DOWN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_CC_STEP_MODE_UP, "Up" },
      { ZCL_CC_STEP_MODE_DOWN, "Down" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ColorControlColorLoopActiveTranslator {
  typedef std::string internal_type;
  typedef ColorControlColorLoopActive   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "ColorLoopInactive", ZCL_COLOR_CONTROL_COLOR_LOOP_ACTIVE_COLOR_LOOP_INACTIVE },
        { "ColorLoopActive", ZCL_COLOR_CONTROL_COLOR_LOOP_ACTIVE_COLOR_LOOP_ACTIVE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COLOR_CONTROL_COLOR_LOOP_ACTIVE_COLOR_LOOP_INACTIVE, "ColorLoopInactive" },
      { ZCL_COLOR_CONTROL_COLOR_LOOP_ACTIVE_COLOR_LOOP_ACTIVE, "ColorLoopActive" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ColorControlColorModeTranslator {
  typedef std::string internal_type;
  typedef ColorControlColorMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "CurrentHueAndCurrentSaturation", ZCL_COLOR_CONTROL_COLOR_MODE_CURRENT_HUE_AND_CURRENT_SATURATION },
        { "CurrentXAndCurrentY", ZCL_COLOR_CONTROL_COLOR_MODE_CURRENT_X_AND_CURRENT_Y },
        { "ColorTemperatureMireds", ZCL_COLOR_CONTROL_COLOR_MODE_COLOR_TEMPERATURE_MIREDS }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COLOR_CONTROL_COLOR_MODE_CURRENT_HUE_AND_CURRENT_SATURATION, "CurrentHueAndCurrentSaturation" },
      { ZCL_COLOR_CONTROL_COLOR_MODE_CURRENT_X_AND_CURRENT_Y, "CurrentXAndCurrentY" },
      { ZCL_COLOR_CONTROL_COLOR_MODE_COLOR_TEMPERATURE_MIREDS, "ColorTemperatureMireds" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ColorControlDriftCompensationTranslator {
  typedef std::string internal_type;
  typedef ColorControlDriftCompensation   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "None", ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_NONE },
        { "OtherOrUnknown", ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_OTHER_OR_UNKNOWN },
        { "TemperatureMonitoring", ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_TEMPERATURE_MONITORING },
        { "OpticalLuminanceMonitoringAndFeedback", ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_OPTICAL_LUMINANCE_MONITORING_AND_FEEDBACK },
        { "OpticalColorMonitoringAndFeedback", ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_OPTICAL_COLOR_MONITORING_AND_FEEDBACK }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_NONE, "None" },
      { ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_OTHER_OR_UNKNOWN, "OtherOrUnknown" },
      { ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_TEMPERATURE_MONITORING, "TemperatureMonitoring" },
      { ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_OPTICAL_LUMINANCE_MONITORING_AND_FEEDBACK, "OpticalLuminanceMonitoringAndFeedback" },
      { ZCL_COLOR_CONTROL_DRIFT_COMPENSATION_OPTICAL_COLOR_MONITORING_AND_FEEDBACK, "OpticalColorMonitoringAndFeedback" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ColorControlEnhancedColorModeTranslator {
  typedef std::string internal_type;
  typedef ColorControlEnhancedColorMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "CurrentHueAndCurrentSaturation", ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_CURRENT_HUE_AND_CURRENT_SATURATION },
        { "CurrentXAndCurrentY", ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_CURRENT_X_AND_CURRENT_Y },
        { "ColorTemperatureMireds", ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_COLOR_TEMPERATURE_MIREDS },
        { "EnhancedCurrentHueAndCurrentSaturation", ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_ENHANCED_CURRENT_HUE_AND_CURRENT_SATURATION }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_CURRENT_HUE_AND_CURRENT_SATURATION, "CurrentHueAndCurrentSaturation" },
      { ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_CURRENT_X_AND_CURRENT_Y, "CurrentXAndCurrentY" },
      { ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_COLOR_TEMPERATURE_MIREDS, "ColorTemperatureMireds" },
      { ZCL_COLOR_CONTROL_ENHANCED_COLOR_MODE_ENHANCED_CURRENT_HUE_AND_CURRENT_SATURATION, "EnhancedCurrentHueAndCurrentSaturation" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ColorLoopSetActionTranslator {
  typedef std::string internal_type;
  typedef ColorLoopSetAction   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "DeactivateColorLoop", ZCL_COLOR_LOOP_SET_ACTION_DEACTIVATE_COLOR_LOOP },
        { "ActivateColorLoopFromColorLoopStartEnhancedHue", ZCL_COLOR_LOOP_SET_ACTION_ACTIVATE_COLOR_LOOP_FROM_COLOR_LOOP_START_ENHANCED_HUE },
        { "ActivateColorLoopFromEnhancedCurrentHue", ZCL_COLOR_LOOP_SET_ACTION_ACTIVATE_COLOR_LOOP_FROM_ENHANCED_CURRENT_HUE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COLOR_LOOP_SET_ACTION_DEACTIVATE_COLOR_LOOP, "DeactivateColorLoop" },
      { ZCL_COLOR_LOOP_SET_ACTION_ACTIVATE_COLOR_LOOP_FROM_COLOR_LOOP_START_ENHANCED_HUE, "ActivateColorLoopFromColorLoopStartEnhancedHue" },
      { ZCL_COLOR_LOOP_SET_ACTION_ACTIVATE_COLOR_LOOP_FROM_ENHANCED_CURRENT_HUE, "ActivateColorLoopFromEnhancedCurrentHue" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct CommissioningNetworkKeyTypeTranslator {
  typedef std::string internal_type;
  typedef CommissioningNetworkKeyType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "StandardKey", ZCL_COMMISSIONING_NETWORK_KEY_TYPE_STANDARD_KEY }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COMMISSIONING_NETWORK_KEY_TYPE_STANDARD_KEY, "StandardKey" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct CommissioningProtocolVersionTranslator {
  typedef std::string internal_type;
  typedef CommissioningProtocolVersion   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Zigbee2006OrLater", ZCL_COMMISSIONING_PROTOCOL_VERSION_ZIGBEE2006_OR_LATER }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COMMISSIONING_PROTOCOL_VERSION_ZIGBEE2006_OR_LATER, "Zigbee2006OrLater" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct CommissioningStackProfileTranslator {
  typedef std::string internal_type;
  typedef CommissioningStackProfile   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "ZigbeeStackProfile", ZCL_COMMISSIONING_STACK_PROFILE_ZIGBEE_STACK_PROFILE },
        { "ZigbeeProStackProfile", ZCL_COMMISSIONING_STACK_PROFILE_ZIGBEE_PRO_STACK_PROFILE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COMMISSIONING_STACK_PROFILE_ZIGBEE_STACK_PROFILE, "ZigbeeStackProfile" },
      { ZCL_COMMISSIONING_STACK_PROFILE_ZIGBEE_PRO_STACK_PROFILE, "ZigbeeProStackProfile" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct CommissioningStartupControlTranslator {
  typedef std::string internal_type;
  typedef CommissioningStartupControl   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "OnANetwork", ZCL_COMMISSIONING_STARTUP_CONTROL_ON_A_NETWORK },
        { "FormNetwork", ZCL_COMMISSIONING_STARTUP_CONTROL_FORM_NETWORK },
        { "RejoinNetwork", ZCL_COMMISSIONING_STARTUP_CONTROL_REJOIN_NETWORK },
        { "JoinUsingMACAssociation", ZCL_COMMISSIONING_STARTUP_CONTROL_JOIN_USING_MAC_ASSOCIATION }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_COMMISSIONING_STARTUP_CONTROL_ON_A_NETWORK, "OnANetwork" },
      { ZCL_COMMISSIONING_STARTUP_CONTROL_FORM_NETWORK, "FormNetwork" },
      { ZCL_COMMISSIONING_STARTUP_CONTROL_REJOIN_NETWORK, "RejoinNetwork" },
      { ZCL_COMMISSIONING_STARTUP_CONTROL_JOIN_USING_MAC_ASSOCIATION, "JoinUsingMACAssociation" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DehumidificationControlDehumidificationLockoutTranslator {
  typedef std::string internal_type;
  typedef DehumidificationControlDehumidificationLockout   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "DehumidificationNotAllowed.", ZCL_DEHUMIDIFICATION_CONTROL_DEHUMIDIFICATION_LOCKOUT_DEHUMIDIFICATION_NOT_ALLOWED_ },
        { "DehumidificationAllowed.", ZCL_DEHUMIDIFICATION_CONTROL_DEHUMIDIFICATION_LOCKOUT_DEHUMIDIFICATION_ALLOWED_ }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DEHUMIDIFICATION_CONTROL_DEHUMIDIFICATION_LOCKOUT_DEHUMIDIFICATION_NOT_ALLOWED_, "DehumidificationNotAllowed." },
      { ZCL_DEHUMIDIFICATION_CONTROL_DEHUMIDIFICATION_LOCKOUT_DEHUMIDIFICATION_ALLOWED_, "DehumidificationAllowed." }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DehumidificationControlRelativeHumidityDisplayTranslator {
  typedef std::string internal_type;
  typedef DehumidificationControlRelativeHumidityDisplay   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "NotDisplayed", ZCL_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_DISPLAY_NOT_DISPLAYED },
        { "Displayed", ZCL_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_DISPLAY_DISPLAYED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_DISPLAY_NOT_DISPLAYED, "NotDisplayed" },
      { ZCL_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_DISPLAY_DISPLAYED, "Displayed" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DehumidificationControlRelativeHumidityModeTranslator {
  typedef std::string internal_type;
  typedef DehumidificationControlRelativeHumidityMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "MeasuredLocally", ZCL_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_MODE_MEASURED_LOCALLY },
        { "UpdatedOverTheNetwork", ZCL_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_MODE_UPDATED_OVER_THE_NETWORK }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_MODE_MEASURED_LOCALLY, "MeasuredLocally" },
      { ZCL_DEHUMIDIFICATION_CONTROL_RELATIVE_HUMIDITY_MODE_UPDATED_OVER_THE_NETWORK, "UpdatedOverTheNetwork" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DoorLockDoorStateTranslator {
  typedef std::string internal_type;
  typedef DoorLockDoorState   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Open", ZCL_DOOR_LOCK_DOOR_STATE_OPEN },
        { "Closed", ZCL_DOOR_LOCK_DOOR_STATE_CLOSED },
        { "ErrorJammed", ZCL_DOOR_LOCK_DOOR_STATE_ERROR_JAMMED },
        { "ErrorForcedOpen", ZCL_DOOR_LOCK_DOOR_STATE_ERROR_FORCED_OPEN },
        { "ErrorUnspecified", ZCL_DOOR_LOCK_DOOR_STATE_ERROR_UNSPECIFIED },
        { "Undefined", ZCL_DOOR_LOCK_DOOR_STATE_UNDEFINED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DOOR_LOCK_DOOR_STATE_OPEN, "Open" },
      { ZCL_DOOR_LOCK_DOOR_STATE_CLOSED, "Closed" },
      { ZCL_DOOR_LOCK_DOOR_STATE_ERROR_JAMMED, "ErrorJammed" },
      { ZCL_DOOR_LOCK_DOOR_STATE_ERROR_FORCED_OPEN, "ErrorForcedOpen" },
      { ZCL_DOOR_LOCK_DOOR_STATE_ERROR_UNSPECIFIED, "ErrorUnspecified" },
      { ZCL_DOOR_LOCK_DOOR_STATE_UNDEFINED, "Undefined" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DoorLockLEDSettingsTranslator {
  typedef std::string internal_type;
  typedef DoorLockLEDSettings   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "NeverUseLED", ZCL_DOOR_LOCK_LED_SETTINGS_NEVER_USE_LED },
        { "UseLEDExceptForAccessAllowed", ZCL_DOOR_LOCK_LED_SETTINGS_USE_LED_EXCEPT_FOR_ACCESS_ALLOWED },
        { "UseLEDForAllEvents", ZCL_DOOR_LOCK_LED_SETTINGS_USE_LED_FOR_ALL_EVENTS }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DOOR_LOCK_LED_SETTINGS_NEVER_USE_LED, "NeverUseLED" },
      { ZCL_DOOR_LOCK_LED_SETTINGS_USE_LED_EXCEPT_FOR_ACCESS_ALLOWED, "UseLEDExceptForAccessAllowed" },
      { ZCL_DOOR_LOCK_LED_SETTINGS_USE_LED_FOR_ALL_EVENTS, "UseLEDForAllEvents" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DoorLockLockStateTranslator {
  typedef std::string internal_type;
  typedef DoorLockLockState   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "NotFullyLocked", ZCL_DOOR_LOCK_LOCK_STATE_NOT_FULLY_LOCKED },
        { "Locked", ZCL_DOOR_LOCK_LOCK_STATE_LOCKED },
        { "Unlocked", ZCL_DOOR_LOCK_LOCK_STATE_UNLOCKED },
        { "Undefined", ZCL_DOOR_LOCK_LOCK_STATE_UNDEFINED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DOOR_LOCK_LOCK_STATE_NOT_FULLY_LOCKED, "NotFullyLocked" },
      { ZCL_DOOR_LOCK_LOCK_STATE_LOCKED, "Locked" },
      { ZCL_DOOR_LOCK_LOCK_STATE_UNLOCKED, "Unlocked" },
      { ZCL_DOOR_LOCK_LOCK_STATE_UNDEFINED, "Undefined" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DoorLockLockTypeTranslator {
  typedef std::string internal_type;
  typedef DoorLockLockType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "DeadBolt", ZCL_DOOR_LOCK_LOCK_TYPE_DEAD_BOLT },
        { "Magnetic", ZCL_DOOR_LOCK_LOCK_TYPE_MAGNETIC },
        { "Other", ZCL_DOOR_LOCK_LOCK_TYPE_OTHER },
        { "Mortise", ZCL_DOOR_LOCK_LOCK_TYPE_MORTISE },
        { "Rim", ZCL_DOOR_LOCK_LOCK_TYPE_RIM },
        { "LatchBolt", ZCL_DOOR_LOCK_LOCK_TYPE_LATCH_BOLT },
        { "CylindricalLock", ZCL_DOOR_LOCK_LOCK_TYPE_CYLINDRICAL_LOCK },
        { "TubularLock", ZCL_DOOR_LOCK_LOCK_TYPE_TUBULAR_LOCK },
        { "InterconnectedLock", ZCL_DOOR_LOCK_LOCK_TYPE_INTERCONNECTED_LOCK },
        { "DeadLatch", ZCL_DOOR_LOCK_LOCK_TYPE_DEAD_LATCH },
        { "DoorFurniture", ZCL_DOOR_LOCK_LOCK_TYPE_DOOR_FURNITURE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DOOR_LOCK_LOCK_TYPE_DEAD_BOLT, "DeadBolt" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_MAGNETIC, "Magnetic" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_OTHER, "Other" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_MORTISE, "Mortise" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_RIM, "Rim" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_LATCH_BOLT, "LatchBolt" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_CYLINDRICAL_LOCK, "CylindricalLock" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_TUBULAR_LOCK, "TubularLock" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_INTERCONNECTED_LOCK, "InterconnectedLock" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_DEAD_LATCH, "DeadLatch" },
      { ZCL_DOOR_LOCK_LOCK_TYPE_DOOR_FURNITURE, "DoorFurniture" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DoorLockSecurityLevelTranslator {
  typedef std::string internal_type;
  typedef DoorLockSecurityLevel   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Network", ZCL_DOOR_LOCK_SECURITY_LEVEL_NETWORK },
        { "APS", ZCL_DOOR_LOCK_SECURITY_LEVEL_APS }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DOOR_LOCK_SECURITY_LEVEL_NETWORK, "Network" },
      { ZCL_DOOR_LOCK_SECURITY_LEVEL_APS, "APS" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DoorLockSoundVolumeTranslator {
  typedef std::string internal_type;
  typedef DoorLockSoundVolume   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "SilentMode", ZCL_DOOR_LOCK_SOUND_VOLUME_SILENT_MODE },
        { "LowVolume", ZCL_DOOR_LOCK_SOUND_VOLUME_LOW_VOLUME },
        { "HighVolume", ZCL_DOOR_LOCK_SOUND_VOLUME_HIGH_VOLUME }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DOOR_LOCK_SOUND_VOLUME_SILENT_MODE, "SilentMode" },
      { ZCL_DOOR_LOCK_SOUND_VOLUME_LOW_VOLUME, "LowVolume" },
      { ZCL_DOOR_LOCK_SOUND_VOLUME_HIGH_VOLUME, "HighVolume" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DrlkOperEventSourceTranslator {
  typedef std::string internal_type;
  typedef DrlkOperEventSource   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Keypad", ZCL_DRLK_OPER_EVENT_SOURCE_KEYPAD },
        { "RF", ZCL_DRLK_OPER_EVENT_SOURCE_RF },
        { "Manual", ZCL_DRLK_OPER_EVENT_SOURCE_MANUAL },
        { "RFID", ZCL_DRLK_OPER_EVENT_SOURCE_RFID },
        { "Indeterminate", ZCL_DRLK_OPER_EVENT_SOURCE_INDETERMINATE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DRLK_OPER_EVENT_SOURCE_KEYPAD, "Keypad" },
      { ZCL_DRLK_OPER_EVENT_SOURCE_RF, "RF" },
      { ZCL_DRLK_OPER_EVENT_SOURCE_MANUAL, "Manual" },
      { ZCL_DRLK_OPER_EVENT_SOURCE_RFID, "RFID" },
      { ZCL_DRLK_OPER_EVENT_SOURCE_INDETERMINATE, "Indeterminate" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DrlkOperModeTranslator {
  typedef std::string internal_type;
  typedef DrlkOperMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Normal", ZCL_DRLK_OPER_MODE_NORMAL },
        { "Vacation", ZCL_DRLK_OPER_MODE_VACATION },
        { "Privacy", ZCL_DRLK_OPER_MODE_PRIVACY },
        { "NoRFLockOrUnlock", ZCL_DRLK_OPER_MODE_NO_RF_LOCK_OR_UNLOCK },
        { "Passage", ZCL_DRLK_OPER_MODE_PASSAGE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DRLK_OPER_MODE_NORMAL, "Normal" },
      { ZCL_DRLK_OPER_MODE_VACATION, "Vacation" },
      { ZCL_DRLK_OPER_MODE_PRIVACY, "Privacy" },
      { ZCL_DRLK_OPER_MODE_NO_RF_LOCK_OR_UNLOCK, "NoRFLockOrUnlock" },
      { ZCL_DRLK_OPER_MODE_PASSAGE, "Passage" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DrlkPassFailStatusTranslator {
  typedef std::string internal_type;
  typedef DrlkPassFailStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Pass", ZCL_DRLK_PASS_FAIL_STATUS_PASS },
        { "Fail", ZCL_DRLK_PASS_FAIL_STATUS_FAIL }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DRLK_PASS_FAIL_STATUS_PASS, "Pass" },
      { ZCL_DRLK_PASS_FAIL_STATUS_FAIL, "Fail" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DrlkSetCodeStatusTranslator {
  typedef std::string internal_type;
  typedef DrlkSetCodeStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Success", ZCL_DRLK_SET_CODE_STATUS_SUCCESS },
        { "GeneralFailure", ZCL_DRLK_SET_CODE_STATUS_GENERAL_FAILURE },
        { "MemoryFull", ZCL_DRLK_SET_CODE_STATUS_MEMORY_FULL },
        { "DuplicateCode", ZCL_DRLK_SET_CODE_STATUS_DUPLICATE_CODE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DRLK_SET_CODE_STATUS_SUCCESS, "Success" },
      { ZCL_DRLK_SET_CODE_STATUS_GENERAL_FAILURE, "GeneralFailure" },
      { ZCL_DRLK_SET_CODE_STATUS_MEMORY_FULL, "MemoryFull" },
      { ZCL_DRLK_SET_CODE_STATUS_DUPLICATE_CODE, "DuplicateCode" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DrlkSettableUserStatusTranslator {
  typedef std::string internal_type;
  typedef DrlkSettableUserStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "OccupiedEnabled", ZCL_DRLK_SETTABLE_USER_STATUS_OCCUPIED_ENABLED },
        { "OccupiedDisabled", ZCL_DRLK_SETTABLE_USER_STATUS_OCCUPIED_DISABLED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DRLK_SETTABLE_USER_STATUS_OCCUPIED_ENABLED, "OccupiedEnabled" },
      { ZCL_DRLK_SETTABLE_USER_STATUS_OCCUPIED_DISABLED, "OccupiedDisabled" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DrlkUserStatusTranslator {
  typedef std::string internal_type;
  typedef DrlkUserStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Available", ZCL_DRLK_USER_STATUS_AVAILABLE },
        { "OccupiedEnabled", ZCL_DRLK_USER_STATUS_OCCUPIED_ENABLED },
        { "OccupiedDisabled", ZCL_DRLK_USER_STATUS_OCCUPIED_DISABLED },
        { "NotSupported", ZCL_DRLK_USER_STATUS_NOT_SUPPORTED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DRLK_USER_STATUS_AVAILABLE, "Available" },
      { ZCL_DRLK_USER_STATUS_OCCUPIED_ENABLED, "OccupiedEnabled" },
      { ZCL_DRLK_USER_STATUS_OCCUPIED_DISABLED, "OccupiedDisabled" },
      { ZCL_DRLK_USER_STATUS_NOT_SUPPORTED, "NotSupported" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct DrlkUserTypeTranslator {
  typedef std::string internal_type;
  typedef DrlkUserType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "UnrestrictedUser", ZCL_DRLK_USER_TYPE_UNRESTRICTED_USER },
        { "YearDayScheduleUser", ZCL_DRLK_USER_TYPE_YEAR_DAY_SCHEDULE_USER },
        { "WeekDayScheduleUser", ZCL_DRLK_USER_TYPE_WEEK_DAY_SCHEDULE_USER },
        { "MasterUser", ZCL_DRLK_USER_TYPE_MASTER_USER },
        { "NonAccessUser", ZCL_DRLK_USER_TYPE_NON_ACCESS_USER },
        { "NotSupported", ZCL_DRLK_USER_TYPE_NOT_SUPPORTED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_DRLK_USER_TYPE_UNRESTRICTED_USER, "UnrestrictedUser" },
      { ZCL_DRLK_USER_TYPE_YEAR_DAY_SCHEDULE_USER, "YearDayScheduleUser" },
      { ZCL_DRLK_USER_TYPE_WEEK_DAY_SCHEDULE_USER, "WeekDayScheduleUser" },
      { ZCL_DRLK_USER_TYPE_MASTER_USER, "MasterUser" },
      { ZCL_DRLK_USER_TYPE_NON_ACCESS_USER, "NonAccessUser" },
      { ZCL_DRLK_USER_TYPE_NOT_SUPPORTED, "NotSupported" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct FanControlFanModeTranslator {
  typedef std::string internal_type;
  typedef FanControlFanMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Off", ZCL_FAN_CONTROL_FAN_MODE_OFF },
        { "Low", ZCL_FAN_CONTROL_FAN_MODE_LOW },
        { "Medium", ZCL_FAN_CONTROL_FAN_MODE_MEDIUM },
        { "High", ZCL_FAN_CONTROL_FAN_MODE_HIGH },
        { "On", ZCL_FAN_CONTROL_FAN_MODE_ON },
        { "Auto", ZCL_FAN_CONTROL_FAN_MODE_AUTO },
        { "Smart", ZCL_FAN_CONTROL_FAN_MODE_SMART }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_FAN_CONTROL_FAN_MODE_OFF, "Off" },
      { ZCL_FAN_CONTROL_FAN_MODE_LOW, "Low" },
      { ZCL_FAN_CONTROL_FAN_MODE_MEDIUM, "Medium" },
      { ZCL_FAN_CONTROL_FAN_MODE_HIGH, "High" },
      { ZCL_FAN_CONTROL_FAN_MODE_ON, "On" },
      { ZCL_FAN_CONTROL_FAN_MODE_AUTO, "Auto" },
      { ZCL_FAN_CONTROL_FAN_MODE_SMART, "Smart" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct FanControlFanModeSequenceTranslator {
  typedef std::string internal_type;
  typedef FanControlFanModeSequence   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "LowMedHigh", ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_LOW_MED_HIGH },
        { "LowHigh", ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_LOW_HIGH },
        { "LowMedHighAuto", ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_LOW_MED_HIGH_AUTO },
        { "LowHighAuto", ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_LOW_HIGH_AUTO },
        { "OnAuto", ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_ON_AUTO }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_LOW_MED_HIGH, "LowMedHigh" },
      { ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_LOW_HIGH, "LowHigh" },
      { ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_LOW_MED_HIGH_AUTO, "LowMedHighAuto" },
      { ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_LOW_HIGH_AUTO, "LowHighAuto" },
      { ZCL_FAN_CONTROL_FAN_MODE_SEQUENCE_ON_AUTO, "OnAuto" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct GetLogRecordResponseEventTypeTranslator {
  typedef std::string internal_type;
  typedef GetLogRecordResponseEventType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Operation", ZCL_GET_LOG_RECORD_RESPONSE_EVENT_TYPE_OPERATION },
        { "Programming", ZCL_GET_LOG_RECORD_RESPONSE_EVENT_TYPE_PROGRAMMING },
        { "Alarm", ZCL_GET_LOG_RECORD_RESPONSE_EVENT_TYPE_ALARM }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_GET_LOG_RECORD_RESPONSE_EVENT_TYPE_OPERATION, "Operation" },
      { ZCL_GET_LOG_RECORD_RESPONSE_EVENT_TYPE_PROGRAMMING, "Programming" },
      { ZCL_GET_LOG_RECORD_RESPONSE_EVENT_TYPE_ALARM, "Alarm" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct GetMeasurementProfileResponseStatusTranslator {
  typedef std::string internal_type;
  typedef GetMeasurementProfileResponseStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Success", ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_SUCCESS },
        { "AttributeProfileNotSupported", ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_ATTRIBUTE_PROFILE_NOT_SUPPORTED },
        { "InvalidStartTime", ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_INVALID_START_TIME },
        { "MoreIntervalsRequestedThanCanBeReturned", ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_MORE_INTERVALS_REQUESTED_THAN_CAN_BE_RETURNED },
        { "NoIntervalsAvailableForTheRequestedTime", ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_NO_INTERVALS_AVAILABLE_FOR_THE_REQUESTED_TIME }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_SUCCESS, "Success" },
      { ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_ATTRIBUTE_PROFILE_NOT_SUPPORTED, "AttributeProfileNotSupported" },
      { ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_INVALID_START_TIME, "InvalidStartTime" },
      { ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_MORE_INTERVALS_REQUESTED_THAN_CAN_BE_RETURNED, "MoreIntervalsRequestedThanCanBeReturned" },
      { ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_STATUS_NO_INTERVALS_AVAILABLE_FOR_THE_REQUESTED_TIME, "NoIntervalsAvailableForTheRequestedTime" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct HVACSystemTypeConfigurationCoolingSystemStageTranslator {
  typedef std::string internal_type;
  typedef HVACSystemTypeConfigurationCoolingSystemStage   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "CoolStage1", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_COOLING_SYSTEM_STAGE_COOL_STAGE1 },
        { "CoolStage2", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_COOLING_SYSTEM_STAGE_COOL_STAGE2 },
        { "CoolStage3", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_COOLING_SYSTEM_STAGE_COOL_STAGE3 }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_COOLING_SYSTEM_STAGE_COOL_STAGE1, "CoolStage1" },
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_COOLING_SYSTEM_STAGE_COOL_STAGE2, "CoolStage2" },
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_COOLING_SYSTEM_STAGE_COOL_STAGE3, "CoolStage3" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct HVACSystemTypeConfigurationHeatingFuelSourceTranslator {
  typedef std::string internal_type;
  typedef HVACSystemTypeConfigurationHeatingFuelSource   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "ElectricOrB", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_FUEL_SOURCE_ELECTRIC_OR_B },
        { "GasOrO", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_FUEL_SOURCE_GAS_OR_O }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_FUEL_SOURCE_ELECTRIC_OR_B, "ElectricOrB" },
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_FUEL_SOURCE_GAS_OR_O, "GasOrO" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct HVACSystemTypeConfigurationHeatingSystemStageTranslator {
  typedef std::string internal_type;
  typedef HVACSystemTypeConfigurationHeatingSystemStage   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "HeatStage1", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_STAGE_HEAT_STAGE1 },
        { "HeatStage2", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_STAGE_HEAT_STAGE2 },
        { "HeatStage3", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_STAGE_HEAT_STAGE3 }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_STAGE_HEAT_STAGE1, "HeatStage1" },
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_STAGE_HEAT_STAGE2, "HeatStage2" },
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_STAGE_HEAT_STAGE3, "HeatStage3" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct HVACSystemTypeConfigurationHeatingSystemTypeTranslator {
  typedef std::string internal_type;
  typedef HVACSystemTypeConfigurationHeatingSystemType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Conventional", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_TYPE_CONVENTIONAL },
        { "HeatPump", ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_TYPE_HEAT_PUMP }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_TYPE_CONVENTIONAL, "Conventional" },
      { ZCL_HVAC_SYSTEM_TYPE_CONFIGURATION_HEATING_SYSTEM_TYPE_HEAT_PUMP, "HeatPump" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IASZoneZoneStateTranslator {
  typedef std::string internal_type;
  typedef IASZoneZoneState   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "NotEnrolled", ZCL_IAS_ZONE_ZONE_STATE_NOT_ENROLLED },
        { "Enrolled", ZCL_IAS_ZONE_ZONE_STATE_ENROLLED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_IAS_ZONE_ZONE_STATE_NOT_ENROLLED, "NotEnrolled" },
      { ZCL_IAS_ZONE_ZONE_STATE_ENROLLED, "Enrolled" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IasZoneTypeTranslator {
  typedef std::string internal_type;
  typedef IasZoneType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "StandardCIE", ZCL_IAS_ZONE_TYPE_STANDARD_CIE },
        { "MotionSensor", ZCL_IAS_ZONE_TYPE_MOTION_SENSOR },
        { "ContactSwitch", ZCL_IAS_ZONE_TYPE_CONTACT_SWITCH },
        { "DoorOrWindowHandle", ZCL_IAS_ZONE_TYPE_DOOR_OR_WINDOW_HANDLE },
        { "FireSensor", ZCL_IAS_ZONE_TYPE_FIRE_SENSOR },
        { "WaterSensor", ZCL_IAS_ZONE_TYPE_WATER_SENSOR },
        { "CarbonMonoxideSensor", ZCL_IAS_ZONE_TYPE_CARBON_MONOXIDE_SENSOR },
        { "PersonalEmergencyDevice", ZCL_IAS_ZONE_TYPE_PERSONAL_EMERGENCY_DEVICE },
        { "VibrationOrMovementSensor", ZCL_IAS_ZONE_TYPE_VIBRATION_OR_MOVEMENT_SENSOR },
        { "RemoteControl", ZCL_IAS_ZONE_TYPE_REMOTE_CONTROL },
        { "KeyFob", ZCL_IAS_ZONE_TYPE_KEY_FOB },
        { "Keypad", ZCL_IAS_ZONE_TYPE_KEYPAD },
        { "StandardWarningDevice", ZCL_IAS_ZONE_TYPE_STANDARD_WARNING_DEVICE },
        { "GlassBreakSensor", ZCL_IAS_ZONE_TYPE_GLASS_BREAK_SENSOR },
        { "SecurityRepeater", ZCL_IAS_ZONE_TYPE_SECURITY_REPEATER },
        { "Invalid", ZCL_IAS_ZONE_TYPE_INVALID }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_IAS_ZONE_TYPE_STANDARD_CIE, "StandardCIE" },
      { ZCL_IAS_ZONE_TYPE_MOTION_SENSOR, "MotionSensor" },
      { ZCL_IAS_ZONE_TYPE_CONTACT_SWITCH, "ContactSwitch" },
      { ZCL_IAS_ZONE_TYPE_DOOR_OR_WINDOW_HANDLE, "DoorOrWindowHandle" },
      { ZCL_IAS_ZONE_TYPE_FIRE_SENSOR, "FireSensor" },
      { ZCL_IAS_ZONE_TYPE_WATER_SENSOR, "WaterSensor" },
      { ZCL_IAS_ZONE_TYPE_CARBON_MONOXIDE_SENSOR, "CarbonMonoxideSensor" },
      { ZCL_IAS_ZONE_TYPE_PERSONAL_EMERGENCY_DEVICE, "PersonalEmergencyDevice" },
      { ZCL_IAS_ZONE_TYPE_VIBRATION_OR_MOVEMENT_SENSOR, "VibrationOrMovementSensor" },
      { ZCL_IAS_ZONE_TYPE_REMOTE_CONTROL, "RemoteControl" },
      { ZCL_IAS_ZONE_TYPE_KEY_FOB, "KeyFob" },
      { ZCL_IAS_ZONE_TYPE_KEYPAD, "Keypad" },
      { ZCL_IAS_ZONE_TYPE_STANDARD_WARNING_DEVICE, "StandardWarningDevice" },
      { ZCL_IAS_ZONE_TYPE_GLASS_BREAK_SENSOR, "GlassBreakSensor" },
      { ZCL_IAS_ZONE_TYPE_SECURITY_REPEATER, "SecurityRepeater" },
      { ZCL_IAS_ZONE_TYPE_INVALID, "Invalid" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IasacPanelStatusTranslator {
  typedef std::string internal_type;
  typedef IasacPanelStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "PanelDisarmedReadyToArm", ZCL_IASAC_PANEL_STATUS_PANEL_DISARMED_READY_TO_ARM },
        { "ArmedStay", ZCL_IASAC_PANEL_STATUS_ARMED_STAY },
        { "ArmedNight", ZCL_IASAC_PANEL_STATUS_ARMED_NIGHT },
        { "ArmedAway", ZCL_IASAC_PANEL_STATUS_ARMED_AWAY },
        { "ExitDelay", ZCL_IASAC_PANEL_STATUS_EXIT_DELAY },
        { "EntryDelay", ZCL_IASAC_PANEL_STATUS_ENTRY_DELAY },
        { "NotReadyToArm", ZCL_IASAC_PANEL_STATUS_NOT_READY_TO_ARM },
        { "InAlarm", ZCL_IASAC_PANEL_STATUS_IN_ALARM },
        { "ArmingStay", ZCL_IASAC_PANEL_STATUS_ARMING_STAY },
        { "ArmingNight", ZCL_IASAC_PANEL_STATUS_ARMING_NIGHT },
        { "ArmingAway", ZCL_IASAC_PANEL_STATUS_ARMING_AWAY }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_IASAC_PANEL_STATUS_PANEL_DISARMED_READY_TO_ARM, "PanelDisarmedReadyToArm" },
      { ZCL_IASAC_PANEL_STATUS_ARMED_STAY, "ArmedStay" },
      { ZCL_IASAC_PANEL_STATUS_ARMED_NIGHT, "ArmedNight" },
      { ZCL_IASAC_PANEL_STATUS_ARMED_AWAY, "ArmedAway" },
      { ZCL_IASAC_PANEL_STATUS_EXIT_DELAY, "ExitDelay" },
      { ZCL_IASAC_PANEL_STATUS_ENTRY_DELAY, "EntryDelay" },
      { ZCL_IASAC_PANEL_STATUS_NOT_READY_TO_ARM, "NotReadyToArm" },
      { ZCL_IASAC_PANEL_STATUS_IN_ALARM, "InAlarm" },
      { ZCL_IASAC_PANEL_STATUS_ARMING_STAY, "ArmingStay" },
      { ZCL_IASAC_PANEL_STATUS_ARMING_NIGHT, "ArmingNight" },
      { ZCL_IASAC_PANEL_STATUS_ARMING_AWAY, "ArmingAway" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IasaceAlarmStatusTranslator {
  typedef std::string internal_type;
  typedef IasaceAlarmStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "NoAlarm", ZCL_IASACE_ALARM_STATUS_NO_ALARM },
        { "Burgler", ZCL_IASACE_ALARM_STATUS_BURGLER },
        { "Fire", ZCL_IASACE_ALARM_STATUS_FIRE },
        { "Emergency", ZCL_IASACE_ALARM_STATUS_EMERGENCY },
        { "PolicePanic", ZCL_IASACE_ALARM_STATUS_POLICE_PANIC },
        { "FirePanic", ZCL_IASACE_ALARM_STATUS_FIRE_PANIC },
        { "EmergencyPanic", ZCL_IASACE_ALARM_STATUS_EMERGENCY_PANIC }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_IASACE_ALARM_STATUS_NO_ALARM, "NoAlarm" },
      { ZCL_IASACE_ALARM_STATUS_BURGLER, "Burgler" },
      { ZCL_IASACE_ALARM_STATUS_FIRE, "Fire" },
      { ZCL_IASACE_ALARM_STATUS_EMERGENCY, "Emergency" },
      { ZCL_IASACE_ALARM_STATUS_POLICE_PANIC, "PolicePanic" },
      { ZCL_IASACE_ALARM_STATUS_FIRE_PANIC, "FirePanic" },
      { ZCL_IASACE_ALARM_STATUS_EMERGENCY_PANIC, "EmergencyPanic" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IasaceAudibleNotificationTranslator {
  typedef std::string internal_type;
  typedef IasaceAudibleNotification   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Mute", ZCL_IASACE_AUDIBLE_NOTIFICATION_MUTE },
        { "DefaultSound", ZCL_IASACE_AUDIBLE_NOTIFICATION_DEFAULT_SOUND }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_IASACE_AUDIBLE_NOTIFICATION_MUTE, "Mute" },
      { ZCL_IASACE_AUDIBLE_NOTIFICATION_DEFAULT_SOUND, "DefaultSound" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IaswdLevelTranslator {
  typedef std::string internal_type;
  typedef IaswdLevel   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "LowLevel", ZCL_IASWD_LEVEL_LOW_LEVEL },
        { "MediumLevel", ZCL_IASWD_LEVEL_MEDIUM_LEVEL },
        { "HighLevel", ZCL_IASWD_LEVEL_HIGH_LEVEL },
        { "VeryHighLevel", ZCL_IASWD_LEVEL_VERY_HIGH_LEVEL }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_IASWD_LEVEL_LOW_LEVEL, "LowLevel" },
      { ZCL_IASWD_LEVEL_MEDIUM_LEVEL, "MediumLevel" },
      { ZCL_IASWD_LEVEL_HIGH_LEVEL, "HighLevel" },
      { ZCL_IASWD_LEVEL_VERY_HIGH_LEVEL, "VeryHighLevel" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IlluminanceLevelSensingLevelStatusTranslator {
  typedef std::string internal_type;
  typedef IlluminanceLevelSensingLevelStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "IlluminanceOnTarget", ZCL_ILLUMINANCE_LEVEL_SENSING_LEVEL_STATUS_ILLUMINANCE_ON_TARGET },
        { "IlluminanceBelowTarget", ZCL_ILLUMINANCE_LEVEL_SENSING_LEVEL_STATUS_ILLUMINANCE_BELOW_TARGET },
        { "IlluminanceAboveTarget", ZCL_ILLUMINANCE_LEVEL_SENSING_LEVEL_STATUS_ILLUMINANCE_ABOVE_TARGET }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ILLUMINANCE_LEVEL_SENSING_LEVEL_STATUS_ILLUMINANCE_ON_TARGET, "IlluminanceOnTarget" },
      { ZCL_ILLUMINANCE_LEVEL_SENSING_LEVEL_STATUS_ILLUMINANCE_BELOW_TARGET, "IlluminanceBelowTarget" },
      { ZCL_ILLUMINANCE_LEVEL_SENSING_LEVEL_STATUS_ILLUMINANCE_ABOVE_TARGET, "IlluminanceAboveTarget" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IlluminanceLevelSensingLightSensorTypeTranslator {
  typedef std::string internal_type;
  typedef IlluminanceLevelSensingLightSensorType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Photodiode", ZCL_ILLUMINANCE_LEVEL_SENSING_LIGHT_SENSOR_TYPE_PHOTODIODE },
        { "CMOS", ZCL_ILLUMINANCE_LEVEL_SENSING_LIGHT_SENSOR_TYPE_CMOS },
        { "Unknown", ZCL_ILLUMINANCE_LEVEL_SENSING_LIGHT_SENSOR_TYPE_UNKNOWN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ILLUMINANCE_LEVEL_SENSING_LIGHT_SENSOR_TYPE_PHOTODIODE, "Photodiode" },
      { ZCL_ILLUMINANCE_LEVEL_SENSING_LIGHT_SENSOR_TYPE_CMOS, "CMOS" },
      { ZCL_ILLUMINANCE_LEVEL_SENSING_LIGHT_SENSOR_TYPE_UNKNOWN, "Unknown" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct IlluminanceMeasurementLightSensorTypeTranslator {
  typedef std::string internal_type;
  typedef IlluminanceMeasurementLightSensorType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Photodiode", ZCL_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_PHOTODIODE },
        { "CMOS", ZCL_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_CMOS },
        { "Unknown", ZCL_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_UNKNOWN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_PHOTODIODE, "Photodiode" },
      { ZCL_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_CMOS, "CMOS" },
      { ZCL_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_UNKNOWN, "Unknown" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ImageNotifyPayloadTypeTranslator {
  typedef std::string internal_type;
  typedef ImageNotifyPayloadType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "QueryJitter", ZCL_IMAGE_NOTIFY_PAYLOAD_TYPE_QUERY_JITTER },
        { "QueryJitterAndManufacturerCode", ZCL_IMAGE_NOTIFY_PAYLOAD_TYPE_QUERY_JITTER_AND_MANUFACTURER_CODE },
        { "QueryJitterManufacturerCodeAndImageType", ZCL_IMAGE_NOTIFY_PAYLOAD_TYPE_QUERY_JITTER_MANUFACTURER_CODE_AND_IMAGE_TYPE },
        { "QueryJitterManufacturerCodeImageTypeAndNewFileVersion", ZCL_IMAGE_NOTIFY_PAYLOAD_TYPE_QUERY_JITTER_MANUFACTURER_CODE_IMAGE_TYPE_AND_NEW_FILE_VERSION }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_IMAGE_NOTIFY_PAYLOAD_TYPE_QUERY_JITTER, "QueryJitter" },
      { ZCL_IMAGE_NOTIFY_PAYLOAD_TYPE_QUERY_JITTER_AND_MANUFACTURER_CODE, "QueryJitterAndManufacturerCode" },
      { ZCL_IMAGE_NOTIFY_PAYLOAD_TYPE_QUERY_JITTER_MANUFACTURER_CODE_AND_IMAGE_TYPE, "QueryJitterManufacturerCodeAndImageType" },
      { ZCL_IMAGE_NOTIFY_PAYLOAD_TYPE_QUERY_JITTER_MANUFACTURER_CODE_IMAGE_TYPE_AND_NEW_FILE_VERSION, "QueryJitterManufacturerCodeImageTypeAndNewFileVersion" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct MoveStepModeTranslator {
  typedef std::string internal_type;
  typedef MoveStepMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Up", ZCL_MOVE_STEP_MODE_UP },
        { "Down", ZCL_MOVE_STEP_MODE_DOWN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_MOVE_STEP_MODE_UP, "Up" },
      { ZCL_MOVE_STEP_MODE_DOWN, "Down" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OTADeviceSpecificImageTypeTranslator {
  typedef std::string internal_type;
  typedef OTADeviceSpecificImageType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "ClientSecurityCredentials", ZCL_OTA_DEVICE_SPECIFIC_IMAGE_TYPE_CLIENT_SECURITY_CREDENTIALS },
        { "ClientConfiguration", ZCL_OTA_DEVICE_SPECIFIC_IMAGE_TYPE_CLIENT_CONFIGURATION },
        { "ServerLog", ZCL_OTA_DEVICE_SPECIFIC_IMAGE_TYPE_SERVER_LOG },
        { "Picture", ZCL_OTA_DEVICE_SPECIFIC_IMAGE_TYPE_PICTURE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_OTA_DEVICE_SPECIFIC_IMAGE_TYPE_CLIENT_SECURITY_CREDENTIALS, "ClientSecurityCredentials" },
      { ZCL_OTA_DEVICE_SPECIFIC_IMAGE_TYPE_CLIENT_CONFIGURATION, "ClientConfiguration" },
      { ZCL_OTA_DEVICE_SPECIFIC_IMAGE_TYPE_SERVER_LOG, "ServerLog" },
      { ZCL_OTA_DEVICE_SPECIFIC_IMAGE_TYPE_PICTURE, "Picture" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OTAUpgradeImageUpgradeStatusTranslator {
  typedef std::string internal_type;
  typedef OTAUpgradeImageUpgradeStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Normal", ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_NORMAL },
        { "DownloadInProgress", ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_DOWNLOAD_IN_PROGRESS },
        { "DownloadComplete", ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_DOWNLOAD_COMPLETE },
        { "WaitingToUpgrade", ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_WAITING_TO_UPGRADE },
        { "CountDown", ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_COUNT_DOWN },
        { "WaitForMore", ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_WAIT_FOR_MORE },
        { "WaitingToUpgradeViaExternalEvent", ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_WAITING_TO_UPGRADE_VIA_EXTERNAL_EVENT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_NORMAL, "Normal" },
      { ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_DOWNLOAD_IN_PROGRESS, "DownloadInProgress" },
      { ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_DOWNLOAD_COMPLETE, "DownloadComplete" },
      { ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_WAITING_TO_UPGRADE, "WaitingToUpgrade" },
      { ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_COUNT_DOWN, "CountDown" },
      { ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_WAIT_FOR_MORE, "WaitForMore" },
      { ZCL_OTA_UPGRADE_IMAGE_UPGRADE_STATUS_WAITING_TO_UPGRADE_VIA_EXTERNAL_EVENT, "WaitingToUpgradeViaExternalEvent" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OTAUpgradeUpgradeActivationPolicyTranslator {
  typedef std::string internal_type;
  typedef OTAUpgradeUpgradeActivationPolicy   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "OTAServerActivationAllowed", ZCL_OTA_UPGRADE_UPGRADE_ACTIVATION_POLICY_OTA_SERVER_ACTIVATION_ALLOWED },
        { "OutOfBandActivationOnly", ZCL_OTA_UPGRADE_UPGRADE_ACTIVATION_POLICY_OUT_OF_BAND_ACTIVATION_ONLY }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_OTA_UPGRADE_UPGRADE_ACTIVATION_POLICY_OTA_SERVER_ACTIVATION_ALLOWED, "OTAServerActivationAllowed" },
      { ZCL_OTA_UPGRADE_UPGRADE_ACTIVATION_POLICY_OUT_OF_BAND_ACTIVATION_ONLY, "OutOfBandActivationOnly" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OTAUpgradeUpgradeTimeoutPolicyTranslator {
  typedef std::string internal_type;
  typedef OTAUpgradeUpgradeTimeoutPolicy   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "ApplyUpgradeAfterTimeout", ZCL_OTA_UPGRADE_UPGRADE_TIMEOUT_POLICY_APPLY_UPGRADE_AFTER_TIMEOUT },
        { "DoNotApplyUpgradeAfterTimeout", ZCL_OTA_UPGRADE_UPGRADE_TIMEOUT_POLICY_DO_NOT_APPLY_UPGRADE_AFTER_TIMEOUT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_OTA_UPGRADE_UPGRADE_TIMEOUT_POLICY_APPLY_UPGRADE_AFTER_TIMEOUT, "ApplyUpgradeAfterTimeout" },
      { ZCL_OTA_UPGRADE_UPGRADE_TIMEOUT_POLICY_DO_NOT_APPLY_UPGRADE_AFTER_TIMEOUT, "DoNotApplyUpgradeAfterTimeout" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OccupancySensingOccupancySensorTypeTranslator {
  typedef std::string internal_type;
  typedef OccupancySensingOccupancySensorType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "PIR", ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_PIR },
        { "Ultrasonic", ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_ULTRASONIC },
        { "PIRAndUltrasonic", ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_PIR_AND_ULTRASONIC },
        { "PhysicalContact", ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_PHYSICAL_CONTACT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_PIR, "PIR" },
      { ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_ULTRASONIC, "Ultrasonic" },
      { ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_PIR_AND_ULTRASONIC, "PIRAndUltrasonic" },
      { ZCL_OCCUPANCY_SENSING_OCCUPANCY_SENSOR_TYPE_PHYSICAL_CONTACT, "PhysicalContact" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OffWithEffectEffectIdentifierTranslator {
  typedef std::string internal_type;
  typedef OffWithEffectEffectIdentifier   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "DelayedAllOff", ZCL_OFF_WITH_EFFECT_EFFECT_IDENTIFIER_DELAYED_ALL_OFF },
        { "DyingLight", ZCL_OFF_WITH_EFFECT_EFFECT_IDENTIFIER_DYING_LIGHT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_OFF_WITH_EFFECT_EFFECT_IDENTIFIER_DELAYED_ALL_OFF, "DelayedAllOff" },
      { ZCL_OFF_WITH_EFFECT_EFFECT_IDENTIFIER_DYING_LIGHT, "DyingLight" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OnOffStartUpOnOffTranslator {
  typedef std::string internal_type;
  typedef OnOffStartUpOnOff   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "SetOnOffTo0", ZCL_ON_OFF_START_UP_ON_OFF_SET_ON_OFF_TO0 },
        { "SetOnOffTo1", ZCL_ON_OFF_START_UP_ON_OFF_SET_ON_OFF_TO1 },
        { "TogglePreviousOnOff", ZCL_ON_OFF_START_UP_ON_OFF_TOGGLE_PREVIOUS_ON_OFF },
        { "SetPreviousOnOff", ZCL_ON_OFF_START_UP_ON_OFF_SET_PREVIOUS_ON_OFF }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ON_OFF_START_UP_ON_OFF_SET_ON_OFF_TO0, "SetOnOffTo0" },
      { ZCL_ON_OFF_START_UP_ON_OFF_SET_ON_OFF_TO1, "SetOnOffTo1" },
      { ZCL_ON_OFF_START_UP_ON_OFF_TOGGLE_PREVIOUS_ON_OFF, "TogglePreviousOnOff" },
      { ZCL_ON_OFF_START_UP_ON_OFF_SET_PREVIOUS_ON_OFF, "SetPreviousOnOff" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OperatingEventNotificationOperationEventCodeTranslator {
  typedef std::string internal_type;
  typedef OperatingEventNotificationOperationEventCode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "UnknownOrMS", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_UNKNOWN_OR_MS },
        { "Lock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_LOCK },
        { "Unlock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_UNLOCK },
        { "LockFailureInvalidPINOrID", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_LOCK_FAILURE_INVALID_PIN_OR_ID },
        { "LockFailureInvalidSchedule", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_LOCK_FAILURE_INVALID_SCHEDULE },
        { "UnlockFailureInvalidPINOrID", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_UNLOCK_FAILURE_INVALID_PIN_OR_ID },
        { "UnlockFailureInvalidSchedule", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_UNLOCK_FAILURE_INVALID_SCHEDULE },
        { "OneTouchLock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_ONE_TOUCH_LOCK },
        { "KeyLock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_KEY_LOCK },
        { "KeyUnlock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_KEY_UNLOCK },
        { "AutoLock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_AUTO_LOCK },
        { "ScheduleLock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_SCHEDULE_LOCK },
        { "ScheduleUnlock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_SCHEDULE_UNLOCK },
        { "ManualLock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_MANUAL_LOCK },
        { "ManualUnlock", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_MANUAL_UNLOCK },
        { "NonAccessUserOperationalEvent", ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_NON_ACCESS_USER_OPERATIONAL_EVENT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_UNKNOWN_OR_MS, "UnknownOrMS" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_LOCK, "Lock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_UNLOCK, "Unlock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_LOCK_FAILURE_INVALID_PIN_OR_ID, "LockFailureInvalidPINOrID" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_LOCK_FAILURE_INVALID_SCHEDULE, "LockFailureInvalidSchedule" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_UNLOCK_FAILURE_INVALID_PIN_OR_ID, "UnlockFailureInvalidPINOrID" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_UNLOCK_FAILURE_INVALID_SCHEDULE, "UnlockFailureInvalidSchedule" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_ONE_TOUCH_LOCK, "OneTouchLock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_KEY_LOCK, "KeyLock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_KEY_UNLOCK, "KeyUnlock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_AUTO_LOCK, "AutoLock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_SCHEDULE_LOCK, "ScheduleLock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_SCHEDULE_UNLOCK, "ScheduleUnlock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_MANUAL_LOCK, "ManualLock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_MANUAL_UNLOCK, "ManualUnlock" },
      { ZCL_OPERATING_EVENT_NOTIFICATION_OPERATION_EVENT_CODE_NON_ACCESS_USER_OPERATIONAL_EVENT, "NonAccessUserOperationalEvent" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct OptionsStartupModeTranslator {
  typedef std::string internal_type;
  typedef OptionsStartupMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "RestartUsingStartupParameters", ZCL_OPTIONS_STARTUP_MODE_RESTART_USING_STARTUP_PARAMETERS },
        { "RestartUsingCurrentState", ZCL_OPTIONS_STARTUP_MODE_RESTART_USING_CURRENT_STATE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_OPTIONS_STARTUP_MODE_RESTART_USING_STARTUP_PARAMETERS, "RestartUsingStartupParameters" },
      { ZCL_OPTIONS_STARTUP_MODE_RESTART_USING_CURRENT_STATE, "RestartUsingCurrentState" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ProfileIntervalPeriodTranslator {
  typedef std::string internal_type;
  typedef ProfileIntervalPeriod   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Daily", ZCL_PROFILE_INTERVAL_PERIOD_DAILY },
        { "60Minutes", ZCL_PROFILE_INTERVAL_PERIOD_60_MINUTES },
        { "30Minutes", ZCL_PROFILE_INTERVAL_PERIOD_30_MINUTES },
        { "15Minutes", ZCL_PROFILE_INTERVAL_PERIOD_15_MINUTES },
        { "10Minutes", ZCL_PROFILE_INTERVAL_PERIOD_10_MINUTES },
        { "7dot5Minutes", ZCL_PROFILE_INTERVAL_PERIOD_7DOT5_MINUTES },
        { "5Minutes", ZCL_PROFILE_INTERVAL_PERIOD_5_MINUTES },
        { "2dot5Minutes", ZCL_PROFILE_INTERVAL_PERIOD_2DOT5_MINUTES }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_PROFILE_INTERVAL_PERIOD_DAILY, "Daily" },
      { ZCL_PROFILE_INTERVAL_PERIOD_60_MINUTES, "60Minutes" },
      { ZCL_PROFILE_INTERVAL_PERIOD_30_MINUTES, "30Minutes" },
      { ZCL_PROFILE_INTERVAL_PERIOD_15_MINUTES, "15Minutes" },
      { ZCL_PROFILE_INTERVAL_PERIOD_10_MINUTES, "10Minutes" },
      { ZCL_PROFILE_INTERVAL_PERIOD_7DOT5_MINUTES, "7dot5Minutes" },
      { ZCL_PROFILE_INTERVAL_PERIOD_5_MINUTES, "5Minutes" },
      { ZCL_PROFILE_INTERVAL_PERIOD_2DOT5_MINUTES, "2dot5Minutes" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ProgrammingEventNotificationProgramEventCodeTranslator {
  typedef std::string internal_type;
  typedef ProgrammingEventNotificationProgramEventCode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "UnknownOrMS", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_UNKNOWN_OR_MS },
        { "MasterCodeChanged", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_MASTER_CODE_CHANGED },
        { "PINCodeAdded", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_PIN_CODE_ADDED },
        { "PINCodeDeleted", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_PIN_CODE_DELETED },
        { "PINCodeChanged", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_PIN_CODE_CHANGED },
        { "RFIDCodeAdded", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_RFID_CODE_ADDED },
        { "RFIDCodeDeleted", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_RFID_CODE_DELETED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_UNKNOWN_OR_MS, "UnknownOrMS" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_MASTER_CODE_CHANGED, "MasterCodeChanged" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_PIN_CODE_ADDED, "PINCodeAdded" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_PIN_CODE_DELETED, "PINCodeDeleted" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_PIN_CODE_CHANGED, "PINCodeChanged" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_RFID_CODE_ADDED, "RFIDCodeAdded" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_CODE_RFID_CODE_DELETED, "RFIDCodeDeleted" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ProgrammingEventNotificationProgramEventSourceTranslator {
  typedef std::string internal_type;
  typedef ProgrammingEventNotificationProgramEventSource   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Keypad", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_SOURCE_KEYPAD },
        { "RF", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_SOURCE_RF },
        { "RFID", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_SOURCE_RFID },
        { "Indeterminate", ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_SOURCE_INDETERMINATE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_SOURCE_KEYPAD, "Keypad" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_SOURCE_RF, "RF" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_SOURCE_RFID, "RFID" },
      { ZCL_PROGRAMMING_EVENT_NOTIFICATION_PROGRAM_EVENT_SOURCE_INDETERMINATE, "Indeterminate" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct PumpControlModeTranslator {
  typedef std::string internal_type;
  typedef PumpControlMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "ConstantSpeed", ZCL_PUMP_CONTROL_MODE_CONSTANT_SPEED },
        { "ConstantPressure", ZCL_PUMP_CONTROL_MODE_CONSTANT_PRESSURE },
        { "ProportionalPressure", ZCL_PUMP_CONTROL_MODE_PROPORTIONAL_PRESSURE },
        { "ConstantFlow", ZCL_PUMP_CONTROL_MODE_CONSTANT_FLOW },
        { "ConstantTemperature", ZCL_PUMP_CONTROL_MODE_CONSTANT_TEMPERATURE },
        { "Automatic", ZCL_PUMP_CONTROL_MODE_AUTOMATIC }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_PUMP_CONTROL_MODE_CONSTANT_SPEED, "ConstantSpeed" },
      { ZCL_PUMP_CONTROL_MODE_CONSTANT_PRESSURE, "ConstantPressure" },
      { ZCL_PUMP_CONTROL_MODE_PROPORTIONAL_PRESSURE, "ProportionalPressure" },
      { ZCL_PUMP_CONTROL_MODE_CONSTANT_FLOW, "ConstantFlow" },
      { ZCL_PUMP_CONTROL_MODE_CONSTANT_TEMPERATURE, "ConstantTemperature" },
      { ZCL_PUMP_CONTROL_MODE_AUTOMATIC, "Automatic" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct PumpOperationModeTranslator {
  typedef std::string internal_type;
  typedef PumpOperationMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Normal", ZCL_PUMP_OPERATION_MODE_NORMAL },
        { "Minimum", ZCL_PUMP_OPERATION_MODE_MINIMUM },
        { "Maximum", ZCL_PUMP_OPERATION_MODE_MAXIMUM },
        { "Local", ZCL_PUMP_OPERATION_MODE_LOCAL }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_PUMP_OPERATION_MODE_NORMAL, "Normal" },
      { ZCL_PUMP_OPERATION_MODE_MINIMUM, "Minimum" },
      { ZCL_PUMP_OPERATION_MODE_MAXIMUM, "Maximum" },
      { ZCL_PUMP_OPERATION_MODE_LOCAL, "Local" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct SHDCFGDirectionTranslator {
  typedef std::string internal_type;
  typedef SHDCFGDirection   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Closing", ZCL_SHDCFG_DIRECTION_CLOSING },
        { "Opening", ZCL_SHDCFG_DIRECTION_OPENING }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_SHDCFG_DIRECTION_CLOSING, "Closing" },
      { ZCL_SHDCFG_DIRECTION_OPENING, "Opening" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct SetpointRaiseOrLowerModeTranslator {
  typedef std::string internal_type;
  typedef SetpointRaiseOrLowerMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Heat", ZCL_SETPOINT_RAISE_OR_LOWER_MODE_HEAT },
        { "Cool", ZCL_SETPOINT_RAISE_OR_LOWER_MODE_COOL },
        { "Both", ZCL_SETPOINT_RAISE_OR_LOWER_MODE_BOTH }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_SETPOINT_RAISE_OR_LOWER_MODE_HEAT, "Heat" },
      { ZCL_SETPOINT_RAISE_OR_LOWER_MODE_COOL, "Cool" },
      { ZCL_SETPOINT_RAISE_OR_LOWER_MODE_BOTH, "Both" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ShadeConfigurationModeTranslator {
  typedef std::string internal_type;
  typedef ShadeConfigurationMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Normal", ZCL_SHADE_CONFIGURATION_MODE_NORMAL },
        { "Configure", ZCL_SHADE_CONFIGURATION_MODE_CONFIGURE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_SHADE_CONFIGURATION_MODE_NORMAL, "Normal" },
      { ZCL_SHADE_CONFIGURATION_MODE_CONFIGURE, "Configure" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct SirenConfigurationStrobeTranslator {
  typedef std::string internal_type;
  typedef SirenConfigurationStrobe   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "NoStrobe", ZCL_SIREN_CONFIGURATION_STROBE_NO_STROBE },
        { "UseStrobe", ZCL_SIREN_CONFIGURATION_STROBE_USE_STROBE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_SIREN_CONFIGURATION_STROBE_NO_STROBE, "NoStrobe" },
      { ZCL_SIREN_CONFIGURATION_STROBE_USE_STROBE, "UseStrobe" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct SirenConfigurationWarningModeTranslator {
  typedef std::string internal_type;
  typedef SirenConfigurationWarningMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Stop", ZCL_SIREN_CONFIGURATION_WARNING_MODE_STOP },
        { "Burgler", ZCL_SIREN_CONFIGURATION_WARNING_MODE_BURGLER },
        { "Fire", ZCL_SIREN_CONFIGURATION_WARNING_MODE_FIRE },
        { "Emergency", ZCL_SIREN_CONFIGURATION_WARNING_MODE_EMERGENCY },
        { "PolicePanic", ZCL_SIREN_CONFIGURATION_WARNING_MODE_POLICE_PANIC },
        { "FirePanic", ZCL_SIREN_CONFIGURATION_WARNING_MODE_FIRE_PANIC },
        { "EmergencyPanic", ZCL_SIREN_CONFIGURATION_WARNING_MODE_EMERGENCY_PANIC }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_SIREN_CONFIGURATION_WARNING_MODE_STOP, "Stop" },
      { ZCL_SIREN_CONFIGURATION_WARNING_MODE_BURGLER, "Burgler" },
      { ZCL_SIREN_CONFIGURATION_WARNING_MODE_FIRE, "Fire" },
      { ZCL_SIREN_CONFIGURATION_WARNING_MODE_EMERGENCY, "Emergency" },
      { ZCL_SIREN_CONFIGURATION_WARNING_MODE_POLICE_PANIC, "PolicePanic" },
      { ZCL_SIREN_CONFIGURATION_WARNING_MODE_FIRE_PANIC, "FirePanic" },
      { ZCL_SIREN_CONFIGURATION_WARNING_MODE_EMERGENCY_PANIC, "EmergencyPanic" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct SquawkConfigurationSquawkModeTranslator {
  typedef std::string internal_type;
  typedef SquawkConfigurationSquawkMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "SoundForSystemIsArmed", ZCL_SQUAWK_CONFIGURATION_SQUAWK_MODE_SOUND_FOR_SYSTEM_IS_ARMED },
        { "SoundForSystemIsDisarmed", ZCL_SQUAWK_CONFIGURATION_SQUAWK_MODE_SOUND_FOR_SYSTEM_IS_DISARMED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_SQUAWK_CONFIGURATION_SQUAWK_MODE_SOUND_FOR_SYSTEM_IS_ARMED, "SoundForSystemIsArmed" },
      { ZCL_SQUAWK_CONFIGURATION_SQUAWK_MODE_SOUND_FOR_SYSTEM_IS_DISARMED, "SoundForSystemIsDisarmed" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct TLKeyIndexTranslator {
  typedef std::string internal_type;
  typedef TLKeyIndex   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "DevelopmentKey", ZCL_TL_KEY_INDEX_DEVELOPMENT_KEY },
        { "MasterKey", ZCL_TL_KEY_INDEX_MASTER_KEY },
        { "CertificationKey", ZCL_TL_KEY_INDEX_CERTIFICATION_KEY }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_TL_KEY_INDEX_DEVELOPMENT_KEY, "DevelopmentKey" },
      { ZCL_TL_KEY_INDEX_MASTER_KEY, "MasterKey" },
      { ZCL_TL_KEY_INDEX_CERTIFICATION_KEY, "CertificationKey" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct TLStatusTranslator {
  typedef std::string internal_type;
  typedef TLStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Success", ZCL_TL_STATUS_SUCCESS },
        { "Failure", ZCL_TL_STATUS_FAILURE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_TL_STATUS_SUCCESS, "Success" },
      { ZCL_TL_STATUS_FAILURE, "Failure" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct TLZigbeeInformationLogicalTypeTranslator {
  typedef std::string internal_type;
  typedef TLZigbeeInformationLogicalType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Coordinator", ZCL_TL_ZIGBEE_INFORMATION_LOGICAL_TYPE_COORDINATOR },
        { "Router", ZCL_TL_ZIGBEE_INFORMATION_LOGICAL_TYPE_ROUTER },
        { "EndDevice", ZCL_TL_ZIGBEE_INFORMATION_LOGICAL_TYPE_END_DEVICE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_TL_ZIGBEE_INFORMATION_LOGICAL_TYPE_COORDINATOR, "Coordinator" },
      { ZCL_TL_ZIGBEE_INFORMATION_LOGICAL_TYPE_ROUTER, "Router" },
      { ZCL_TL_ZIGBEE_INFORMATION_LOGICAL_TYPE_END_DEVICE, "EndDevice" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatACCapacityFormatTranslator {
  typedef std::string internal_type;
  typedef ThermostatACCapacityFormat   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "BTUh", ZCL_THERMOSTAT_AC_CAPACITY_FORMAT_BT_UH }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_AC_CAPACITY_FORMAT_BT_UH, "BTUh" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatACCompressorTypeTranslator {
  typedef std::string internal_type;
  typedef ThermostatACCompressorType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "T1", ZCL_THERMOSTAT_AC_COMPRESSOR_TYPE_T1 },
        { "T2", ZCL_THERMOSTAT_AC_COMPRESSOR_TYPE_T2 },
        { "T3", ZCL_THERMOSTAT_AC_COMPRESSOR_TYPE_T3 }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_AC_COMPRESSOR_TYPE_T1, "T1" },
      { ZCL_THERMOSTAT_AC_COMPRESSOR_TYPE_T2, "T2" },
      { ZCL_THERMOSTAT_AC_COMPRESSOR_TYPE_T3, "T3" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatACLouverPositionTranslator {
  typedef std::string internal_type;
  typedef ThermostatACLouverPosition   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "FullyClosed", ZCL_THERMOSTAT_AC_LOUVER_POSITION_FULLY_CLOSED },
        { "FullyOpen", ZCL_THERMOSTAT_AC_LOUVER_POSITION_FULLY_OPEN },
        { "QuarterOpen", ZCL_THERMOSTAT_AC_LOUVER_POSITION_QUARTER_OPEN },
        { "HalfOpen", ZCL_THERMOSTAT_AC_LOUVER_POSITION_HALF_OPEN },
        { "ThreeQuartersOpen", ZCL_THERMOSTAT_AC_LOUVER_POSITION_THREE_QUARTERS_OPEN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_AC_LOUVER_POSITION_FULLY_CLOSED, "FullyClosed" },
      { ZCL_THERMOSTAT_AC_LOUVER_POSITION_FULLY_OPEN, "FullyOpen" },
      { ZCL_THERMOSTAT_AC_LOUVER_POSITION_QUARTER_OPEN, "QuarterOpen" },
      { ZCL_THERMOSTAT_AC_LOUVER_POSITION_HALF_OPEN, "HalfOpen" },
      { ZCL_THERMOSTAT_AC_LOUVER_POSITION_THREE_QUARTERS_OPEN, "ThreeQuartersOpen" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatACRefrigerantTypeTranslator {
  typedef std::string internal_type;
  typedef ThermostatACRefrigerantType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "R22", ZCL_THERMOSTAT_AC_REFRIGERANT_TYPE_R22 },
        { "R410a", ZCL_THERMOSTAT_AC_REFRIGERANT_TYPE_R410A },
        { "R407c", ZCL_THERMOSTAT_AC_REFRIGERANT_TYPE_R407C }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_AC_REFRIGERANT_TYPE_R22, "R22" },
      { ZCL_THERMOSTAT_AC_REFRIGERANT_TYPE_R410A, "R410a" },
      { ZCL_THERMOSTAT_AC_REFRIGERANT_TYPE_R407C, "R407c" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatACTypeTranslator {
  typedef std::string internal_type;
  typedef ThermostatACType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "CoolingAndFixedSpeed", ZCL_THERMOSTAT_AC_TYPE_COOLING_AND_FIXED_SPEED },
        { "HeatPumpAndFixedSpeed", ZCL_THERMOSTAT_AC_TYPE_HEAT_PUMP_AND_FIXED_SPEED },
        { "CoolingAndInverter", ZCL_THERMOSTAT_AC_TYPE_COOLING_AND_INVERTER },
        { "HeatPumpAndInverter", ZCL_THERMOSTAT_AC_TYPE_HEAT_PUMP_AND_INVERTER }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_AC_TYPE_COOLING_AND_FIXED_SPEED, "CoolingAndFixedSpeed" },
      { ZCL_THERMOSTAT_AC_TYPE_HEAT_PUMP_AND_FIXED_SPEED, "HeatPumpAndFixedSpeed" },
      { ZCL_THERMOSTAT_AC_TYPE_COOLING_AND_INVERTER, "CoolingAndInverter" },
      { ZCL_THERMOSTAT_AC_TYPE_HEAT_PUMP_AND_INVERTER, "HeatPumpAndInverter" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatControlSequenceOfOperationTranslator {
  typedef std::string internal_type;
  typedef ThermostatControlSequenceOfOperation   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "CoolingOnly", ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_COOLING_ONLY },
        { "CoolingWithReheat", ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_COOLING_WITH_REHEAT },
        { "HeatingOnly", ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_HEATING_ONLY },
        { "HeatingWithReheat", ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_HEATING_WITH_REHEAT },
        { "CoolingAndHeating4Pipes", ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_COOLING_AND_HEATING4_PIPES },
        { "CoolingAndHeating4PipesWithReheat", ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_COOLING_AND_HEATING4_PIPES_WITH_REHEAT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_COOLING_ONLY, "CoolingOnly" },
      { ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_COOLING_WITH_REHEAT, "CoolingWithReheat" },
      { ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_HEATING_ONLY, "HeatingOnly" },
      { ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_HEATING_WITH_REHEAT, "HeatingWithReheat" },
      { ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_COOLING_AND_HEATING4_PIPES, "CoolingAndHeating4Pipes" },
      { ZCL_THERMOSTAT_CONTROL_SEQUENCE_OF_OPERATION_COOLING_AND_HEATING4_PIPES_WITH_REHEAT, "CoolingAndHeating4PipesWithReheat" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatProgrammingOperationModeProgrammingModeTranslator {
  typedef std::string internal_type;
  typedef ThermostatProgrammingOperationModeProgrammingMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "SimpleOrSetpoint", ZCL_THERMOSTAT_PROGRAMMING_OPERATION_MODE_PROGRAMMING_MODE_SIMPLE_OR_SETPOINT },
        { "Schedule", ZCL_THERMOSTAT_PROGRAMMING_OPERATION_MODE_PROGRAMMING_MODE_SCHEDULE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_PROGRAMMING_OPERATION_MODE_PROGRAMMING_MODE_SIMPLE_OR_SETPOINT, "SimpleOrSetpoint" },
      { ZCL_THERMOSTAT_PROGRAMMING_OPERATION_MODE_PROGRAMMING_MODE_SCHEDULE, "Schedule" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatSetpointChangeSourceTranslator {
  typedef std::string internal_type;
  typedef ThermostatSetpointChangeSource   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Manual", ZCL_THERMOSTAT_SETPOINT_CHANGE_SOURCE_MANUAL },
        { "ScheduleOrInternalProgramming", ZCL_THERMOSTAT_SETPOINT_CHANGE_SOURCE_SCHEDULE_OR_INTERNAL_PROGRAMMING },
        { "External", ZCL_THERMOSTAT_SETPOINT_CHANGE_SOURCE_EXTERNAL }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_SETPOINT_CHANGE_SOURCE_MANUAL, "Manual" },
      { ZCL_THERMOSTAT_SETPOINT_CHANGE_SOURCE_SCHEDULE_OR_INTERNAL_PROGRAMMING, "ScheduleOrInternalProgramming" },
      { ZCL_THERMOSTAT_SETPOINT_CHANGE_SOURCE_EXTERNAL, "External" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatStartOfWeekTranslator {
  typedef std::string internal_type;
  typedef ThermostatStartOfWeek   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Sunday", ZCL_THERMOSTAT_START_OF_WEEK_SUNDAY },
        { "Monday", ZCL_THERMOSTAT_START_OF_WEEK_MONDAY },
        { "Tuesday", ZCL_THERMOSTAT_START_OF_WEEK_TUESDAY },
        { "Wednesday", ZCL_THERMOSTAT_START_OF_WEEK_WEDNESDAY },
        { "Thursday", ZCL_THERMOSTAT_START_OF_WEEK_THURSDAY },
        { "Friday", ZCL_THERMOSTAT_START_OF_WEEK_FRIDAY },
        { "Saturday", ZCL_THERMOSTAT_START_OF_WEEK_SATURDAY }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_START_OF_WEEK_SUNDAY, "Sunday" },
      { ZCL_THERMOSTAT_START_OF_WEEK_MONDAY, "Monday" },
      { ZCL_THERMOSTAT_START_OF_WEEK_TUESDAY, "Tuesday" },
      { ZCL_THERMOSTAT_START_OF_WEEK_WEDNESDAY, "Wednesday" },
      { ZCL_THERMOSTAT_START_OF_WEEK_THURSDAY, "Thursday" },
      { ZCL_THERMOSTAT_START_OF_WEEK_FRIDAY, "Friday" },
      { ZCL_THERMOSTAT_START_OF_WEEK_SATURDAY, "Saturday" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatSystemModeTranslator {
  typedef std::string internal_type;
  typedef ThermostatSystemMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Off", ZCL_THERMOSTAT_SYSTEM_MODE_OFF },
        { "Auto", ZCL_THERMOSTAT_SYSTEM_MODE_AUTO },
        { "Cool", ZCL_THERMOSTAT_SYSTEM_MODE_COOL },
        { "Heat", ZCL_THERMOSTAT_SYSTEM_MODE_HEAT },
        { "EmergencyHeating", ZCL_THERMOSTAT_SYSTEM_MODE_EMERGENCY_HEATING },
        { "Precooling", ZCL_THERMOSTAT_SYSTEM_MODE_PRECOOLING },
        { "FanOnly", ZCL_THERMOSTAT_SYSTEM_MODE_FAN_ONLY },
        { "Dry", ZCL_THERMOSTAT_SYSTEM_MODE_DRY },
        { "Sleep", ZCL_THERMOSTAT_SYSTEM_MODE_SLEEP }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_SYSTEM_MODE_OFF, "Off" },
      { ZCL_THERMOSTAT_SYSTEM_MODE_AUTO, "Auto" },
      { ZCL_THERMOSTAT_SYSTEM_MODE_COOL, "Cool" },
      { ZCL_THERMOSTAT_SYSTEM_MODE_HEAT, "Heat" },
      { ZCL_THERMOSTAT_SYSTEM_MODE_EMERGENCY_HEATING, "EmergencyHeating" },
      { ZCL_THERMOSTAT_SYSTEM_MODE_PRECOOLING, "Precooling" },
      { ZCL_THERMOSTAT_SYSTEM_MODE_FAN_ONLY, "FanOnly" },
      { ZCL_THERMOSTAT_SYSTEM_MODE_DRY, "Dry" },
      { ZCL_THERMOSTAT_SYSTEM_MODE_SLEEP, "Sleep" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatTemperatureSetpointHoldTranslator {
  typedef std::string internal_type;
  typedef ThermostatTemperatureSetpointHold   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "SetpointHoldOff", ZCL_THERMOSTAT_TEMPERATURE_SETPOINT_HOLD_SETPOINT_HOLD_OFF },
        { "SetpointHoldOn", ZCL_THERMOSTAT_TEMPERATURE_SETPOINT_HOLD_SETPOINT_HOLD_ON }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_TEMPERATURE_SETPOINT_HOLD_SETPOINT_HOLD_OFF, "SetpointHoldOff" },
      { ZCL_THERMOSTAT_TEMPERATURE_SETPOINT_HOLD_SETPOINT_HOLD_ON, "SetpointHoldOn" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatThermostatRunningModeTranslator {
  typedef std::string internal_type;
  typedef ThermostatThermostatRunningMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Off", ZCL_THERMOSTAT_THERMOSTAT_RUNNING_MODE_OFF },
        { "Cool", ZCL_THERMOSTAT_THERMOSTAT_RUNNING_MODE_COOL },
        { "Heat", ZCL_THERMOSTAT_THERMOSTAT_RUNNING_MODE_HEAT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_THERMOSTAT_RUNNING_MODE_OFF, "Off" },
      { ZCL_THERMOSTAT_THERMOSTAT_RUNNING_MODE_COOL, "Cool" },
      { ZCL_THERMOSTAT_THERMOSTAT_RUNNING_MODE_HEAT, "Heat" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatUserInterfaceConfigurationKeypadLockoutTranslator {
  typedef std::string internal_type;
  typedef ThermostatUserInterfaceConfigurationKeypadLockout   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "None", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_NONE },
        { "Level1", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL1 },
        { "Level2", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL2 },
        { "Level3", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL3 },
        { "Level4", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL4 },
        { "Level5", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL5 }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_NONE, "None" },
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL1, "Level1" },
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL2, "Level2" },
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL3, "Level3" },
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL4, "Level4" },
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_KEYPAD_LOCKOUT_LEVEL5, "Level5" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatUserInterfaceConfigurationScheduleProgrammingVisibilityTranslator {
  typedef std::string internal_type;
  typedef ThermostatUserInterfaceConfigurationScheduleProgrammingVisibility   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "LocalEnabled", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_SCHEDULE_PROGRAMMING_VISIBILITY_LOCAL_ENABLED },
        { "LocalDisabled", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_SCHEDULE_PROGRAMMING_VISIBILITY_LOCAL_DISABLED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_SCHEDULE_PROGRAMMING_VISIBILITY_LOCAL_ENABLED, "LocalEnabled" },
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_SCHEDULE_PROGRAMMING_VISIBILITY_LOCAL_DISABLED, "LocalDisabled" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ThermostatUserInterfaceConfigurationTemperatureDisplayModeTranslator {
  typedef std::string internal_type;
  typedef ThermostatUserInterfaceConfigurationTemperatureDisplayMode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Celsius", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_TEMPERATURE_DISPLAY_MODE_CELSIUS },
        { "Fahrenheit", ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_TEMPERATURE_DISPLAY_MODE_FAHRENHEIT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_TEMPERATURE_DISPLAY_MODE_CELSIUS, "Celsius" },
      { ZCL_THERMOSTAT_USER_INTERFACE_CONFIGURATION_TEMPERATURE_DISPLAY_MODE_FAHRENHEIT, "Fahrenheit" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct TriggerEffectEffectIdentifierTranslator {
  typedef std::string internal_type;
  typedef TriggerEffectEffectIdentifier   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Blink", ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_BLINK },
        { "Breathe", ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_BREATHE },
        { "Okay", ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_OKAY },
        { "ChannelChange", ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_CHANNEL_CHANGE },
        { "FinishEffect", ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_FINISH_EFFECT },
        { "StopEffect", ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_STOP_EFFECT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_BLINK, "Blink" },
      { ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_BREATHE, "Breathe" },
      { ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_OKAY, "Okay" },
      { ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_CHANNEL_CHANGE, "ChannelChange" },
      { ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_FINISH_EFFECT, "FinishEffect" },
      { ZCL_TRIGGER_EFFECT_EFFECT_IDENTIFIER_STOP_EFFECT, "StopEffect" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct TriggerEffectEffectVariantTranslator {
  typedef std::string internal_type;
  typedef TriggerEffectEffectVariant   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Default", ZCL_TRIGGER_EFFECT_EFFECT_VARIANT_DEFAULT }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_TRIGGER_EFFECT_EFFECT_VARIANT_DEFAULT, "Default" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct WindowCoveringWindowCoveringTypeTranslator {
  typedef std::string internal_type;
  typedef WindowCoveringWindowCoveringType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Rollershade", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_ROLLERSHADE },
        { "Rollershade2Motor", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_ROLLERSHADE2_MOTOR },
        { "RollershadeExterior", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_ROLLERSHADE_EXTERIOR },
        { "RollershadeExterior2Motor", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_ROLLERSHADE_EXTERIOR2_MOTOR },
        { "Drapery", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_DRAPERY },
        { "Awning", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_AWNING },
        { "Shutter", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_SHUTTER },
        { "TiltBlindTiltOnly", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_TILT_BLIND_TILT_ONLY },
        { "TiltBlindLiftAndTilt", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_TILT_BLIND_LIFT_AND_TILT },
        { "ProjectorScreen", ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_PROJECTOR_SCREEN }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_ROLLERSHADE, "Rollershade" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_ROLLERSHADE2_MOTOR, "Rollershade2Motor" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_ROLLERSHADE_EXTERIOR, "RollershadeExterior" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_ROLLERSHADE_EXTERIOR2_MOTOR, "RollershadeExterior2Motor" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_DRAPERY, "Drapery" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_AWNING, "Awning" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_SHUTTER, "Shutter" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_TILT_BLIND_TILT_ONLY, "TiltBlindTiltOnly" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_TILT_BLIND_LIFT_AND_TILT, "TiltBlindLiftAndTilt" },
      { ZCL_WINDOW_COVERING_WINDOW_COVERING_TYPE_PROJECTOR_SCREEN, "ProjectorScreen" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct ZoneEnrollResponseEnrollResponseCodeTranslator {
  typedef std::string internal_type;
  typedef ZoneEnrollResponseEnrollResponseCode   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Success", ZCL_ZONE_ENROLL_RESPONSE_ENROLL_RESPONSE_CODE_SUCCESS },
        { "NotSupported", ZCL_ZONE_ENROLL_RESPONSE_ENROLL_RESPONSE_CODE_NOT_SUPPORTED },
        { "NoEnrollPermit", ZCL_ZONE_ENROLL_RESPONSE_ENROLL_RESPONSE_CODE_NO_ENROLL_PERMIT },
        { "TooManyZones", ZCL_ZONE_ENROLL_RESPONSE_ENROLL_RESPONSE_CODE_TOO_MANY_ZONES }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ZONE_ENROLL_RESPONSE_ENROLL_RESPONSE_CODE_SUCCESS, "Success" },
      { ZCL_ZONE_ENROLL_RESPONSE_ENROLL_RESPONSE_CODE_NOT_SUPPORTED, "NotSupported" },
      { ZCL_ZONE_ENROLL_RESPONSE_ENROLL_RESPONSE_CODE_NO_ENROLL_PERMIT, "NoEnrollPermit" },
      { ZCL_ZONE_ENROLL_RESPONSE_ENROLL_RESPONSE_CODE_TOO_MANY_ZONES, "TooManyZones" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct attributeReportingStatusTranslator {
  typedef std::string internal_type;
  typedef attributeReportingStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "Pending", ZCL_ATTRIBUTE_REPORTING_STATUS_PENDING },
        { "Complete", ZCL_ATTRIBUTE_REPORTING_STATUS_COMPLETE }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ATTRIBUTE_REPORTING_STATUS_PENDING, "Pending" },
      { ZCL_ATTRIBUTE_REPORTING_STATUS_COMPLETE, "Complete" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct zclStatusTranslator {
  typedef std::string internal_type;
  typedef zclStatus   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "SUCCESS", ZCL_ZCL_STATUS_SUCCESS },
        { "FAILURE", ZCL_ZCL_STATUS_FAILURE },
        { "NOT_AUTHORIZED", ZCL_ZCL_STATUS_NOT_AUTHORIZED },
        { "MALFORMED_COMMAND", ZCL_ZCL_STATUS_MALFORMED_COMMAND },
        { "UNSUP_CLUSTER_COMMAND", ZCL_ZCL_STATUS_UNSUP_CLUSTER_COMMAND },
        { "UNSUP_GENERAL_COMMAND", ZCL_ZCL_STATUS_UNSUP_GENERAL_COMMAND },
        { "UNSUP_MANUF_CLUSTER_COMMAND", ZCL_ZCL_STATUS_UNSUP_MANUF_CLUSTER_COMMAND },
        { "UNSUP_MANUF_GENERAL_COMMAND", ZCL_ZCL_STATUS_UNSUP_MANUF_GENERAL_COMMAND },
        { "INVALID_FIELD", ZCL_ZCL_STATUS_INVALID_FIELD },
        { "UNSUPPORTED_ATTRIBUTE", ZCL_ZCL_STATUS_UNSUPPORTED_ATTRIBUTE },
        { "INVALID_VALUE", ZCL_ZCL_STATUS_INVALID_VALUE },
        { "READ_ONLY", ZCL_ZCL_STATUS_READ_ONLY },
        { "INSUFFICIENT_SPACE", ZCL_ZCL_STATUS_INSUFFICIENT_SPACE },
        { "DUPLICATE_EXISTS", ZCL_ZCL_STATUS_DUPLICATE_EXISTS },
        { "NOT_FOUND", ZCL_ZCL_STATUS_NOT_FOUND },
        { "UNREPORTABLE_ATTRIBUTE", ZCL_ZCL_STATUS_UNREPORTABLE_ATTRIBUTE },
        { "INVALID_DATA_TYPE", ZCL_ZCL_STATUS_INVALID_DATA_TYPE },
        { "INVALID_SELECTOR", ZCL_ZCL_STATUS_INVALID_SELECTOR },
        { "WRITE_ONLY", ZCL_ZCL_STATUS_WRITE_ONLY },
        { "INCONSISTENT_STARTUP_STATE", ZCL_ZCL_STATUS_INCONSISTENT_STARTUP_STATE },
        { "DEFINED_OUT_OF_BAND", ZCL_ZCL_STATUS_DEFINED_OUT_OF_BAND },
        { "INCONSISTENT", ZCL_ZCL_STATUS_INCONSISTENT },
        { "ACTION_DENIED", ZCL_ZCL_STATUS_ACTION_DENIED },
        { "TIMEOUT", ZCL_ZCL_STATUS_TIMEOUT },
        { "ABORT", ZCL_ZCL_STATUS_ABORT },
        { "INVALID_IMAGE", ZCL_ZCL_STATUS_INVALID_IMAGE },
        { "WAIT_FOR_DATA", ZCL_ZCL_STATUS_WAIT_FOR_DATA },
        { "NO_IMAGE_AVAILABLE", ZCL_ZCL_STATUS_NO_IMAGE_AVAILABLE },
        { "REQUIRE_MORE_IMAGE", ZCL_ZCL_STATUS_REQUIRE_MORE_IMAGE },
        { "NOTIFICATION_PENDING", ZCL_ZCL_STATUS_NOTIFICATION_PENDING },
        { "HARDWARE_FAILURE", ZCL_ZCL_STATUS_HARDWARE_FAILURE },
        { "SOFTWARE_FAILURE", ZCL_ZCL_STATUS_SOFTWARE_FAILURE },
        { "CALIBRATION_ERROR", ZCL_ZCL_STATUS_CALIBRATION_ERROR },
        { "UNSUPPORTED_CLUSTER", ZCL_ZCL_STATUS_UNSUPPORTED_CLUSTER },
        { "LIMIT_REACHED", ZCL_ZCL_STATUS_LIMIT_REACHED }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ZCL_STATUS_SUCCESS, "SUCCESS" },
      { ZCL_ZCL_STATUS_FAILURE, "FAILURE" },
      { ZCL_ZCL_STATUS_NOT_AUTHORIZED, "NOT_AUTHORIZED" },
      { ZCL_ZCL_STATUS_MALFORMED_COMMAND, "MALFORMED_COMMAND" },
      { ZCL_ZCL_STATUS_UNSUP_CLUSTER_COMMAND, "UNSUP_CLUSTER_COMMAND" },
      { ZCL_ZCL_STATUS_UNSUP_GENERAL_COMMAND, "UNSUP_GENERAL_COMMAND" },
      { ZCL_ZCL_STATUS_UNSUP_MANUF_CLUSTER_COMMAND, "UNSUP_MANUF_CLUSTER_COMMAND" },
      { ZCL_ZCL_STATUS_UNSUP_MANUF_GENERAL_COMMAND, "UNSUP_MANUF_GENERAL_COMMAND" },
      { ZCL_ZCL_STATUS_INVALID_FIELD, "INVALID_FIELD" },
      { ZCL_ZCL_STATUS_UNSUPPORTED_ATTRIBUTE, "UNSUPPORTED_ATTRIBUTE" },
      { ZCL_ZCL_STATUS_INVALID_VALUE, "INVALID_VALUE" },
      { ZCL_ZCL_STATUS_READ_ONLY, "READ_ONLY" },
      { ZCL_ZCL_STATUS_INSUFFICIENT_SPACE, "INSUFFICIENT_SPACE" },
      { ZCL_ZCL_STATUS_DUPLICATE_EXISTS, "DUPLICATE_EXISTS" },
      { ZCL_ZCL_STATUS_NOT_FOUND, "NOT_FOUND" },
      { ZCL_ZCL_STATUS_UNREPORTABLE_ATTRIBUTE, "UNREPORTABLE_ATTRIBUTE" },
      { ZCL_ZCL_STATUS_INVALID_DATA_TYPE, "INVALID_DATA_TYPE" },
      { ZCL_ZCL_STATUS_INVALID_SELECTOR, "INVALID_SELECTOR" },
      { ZCL_ZCL_STATUS_WRITE_ONLY, "WRITE_ONLY" },
      { ZCL_ZCL_STATUS_INCONSISTENT_STARTUP_STATE, "INCONSISTENT_STARTUP_STATE" },
      { ZCL_ZCL_STATUS_DEFINED_OUT_OF_BAND, "DEFINED_OUT_OF_BAND" },
      { ZCL_ZCL_STATUS_INCONSISTENT, "INCONSISTENT" },
      { ZCL_ZCL_STATUS_ACTION_DENIED, "ACTION_DENIED" },
      { ZCL_ZCL_STATUS_TIMEOUT, "TIMEOUT" },
      { ZCL_ZCL_STATUS_ABORT, "ABORT" },
      { ZCL_ZCL_STATUS_INVALID_IMAGE, "INVALID_IMAGE" },
      { ZCL_ZCL_STATUS_WAIT_FOR_DATA, "WAIT_FOR_DATA" },
      { ZCL_ZCL_STATUS_NO_IMAGE_AVAILABLE, "NO_IMAGE_AVAILABLE" },
      { ZCL_ZCL_STATUS_REQUIRE_MORE_IMAGE, "REQUIRE_MORE_IMAGE" },
      { ZCL_ZCL_STATUS_NOTIFICATION_PENDING, "NOTIFICATION_PENDING" },
      { ZCL_ZCL_STATUS_HARDWARE_FAILURE, "HARDWARE_FAILURE" },
      { ZCL_ZCL_STATUS_SOFTWARE_FAILURE, "SOFTWARE_FAILURE" },
      { ZCL_ZCL_STATUS_CALIBRATION_ERROR, "CALIBRATION_ERROR" },
      { ZCL_ZCL_STATUS_UNSUPPORTED_CLUSTER, "UNSUPPORTED_CLUSTER" },
      { ZCL_ZCL_STATUS_LIMIT_REACHED, "LIMIT_REACHED" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};

struct zclTypeTranslator {
  typedef std::string internal_type;
  typedef zclType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      std::map<internal_type, external_type> enum_map = {
        { "nodata", ZCL_ZCL_TYPE_NODATA },
        { "data8", ZCL_ZCL_TYPE_DATA8 },
        { "data16", ZCL_ZCL_TYPE_DATA16 },
        { "data24", ZCL_ZCL_TYPE_DATA24 },
        { "data32", ZCL_ZCL_TYPE_DATA32 },
        { "data40", ZCL_ZCL_TYPE_DATA40 },
        { "data48", ZCL_ZCL_TYPE_DATA48 },
        { "data56", ZCL_ZCL_TYPE_DATA56 },
        { "data64", ZCL_ZCL_TYPE_DATA64 },
        { "bool", ZCL_ZCL_TYPE_BOOL },
        { "map8", ZCL_ZCL_TYPE_MAP8 },
        { "map16", ZCL_ZCL_TYPE_MAP16 },
        { "map24", ZCL_ZCL_TYPE_MAP24 },
        { "map32", ZCL_ZCL_TYPE_MAP32 },
        { "map40", ZCL_ZCL_TYPE_MAP40 },
        { "map48", ZCL_ZCL_TYPE_MAP48 },
        { "map56", ZCL_ZCL_TYPE_MAP56 },
        { "map64", ZCL_ZCL_TYPE_MAP64 },
        { "uint8", ZCL_ZCL_TYPE_UINT8 },
        { "uint16", ZCL_ZCL_TYPE_UINT16 },
        { "uint24", ZCL_ZCL_TYPE_UINT24 },
        { "uint32", ZCL_ZCL_TYPE_UINT32 },
        { "uint40", ZCL_ZCL_TYPE_UINT40 },
        { "uint48", ZCL_ZCL_TYPE_UINT48 },
        { "uint56", ZCL_ZCL_TYPE_UINT56 },
        { "uint64", ZCL_ZCL_TYPE_UINT64 },
        { "int8", ZCL_ZCL_TYPE_INT8 },
        { "int16", ZCL_ZCL_TYPE_INT16 },
        { "int24", ZCL_ZCL_TYPE_INT24 },
        { "int32", ZCL_ZCL_TYPE_INT32 },
        { "int40", ZCL_ZCL_TYPE_INT40 },
        { "int48", ZCL_ZCL_TYPE_INT48 },
        { "int56", ZCL_ZCL_TYPE_INT56 },
        { "int64", ZCL_ZCL_TYPE_INT64 },
        { "enum8", ZCL_ZCL_TYPE_ENUM8 },
        { "enum16", ZCL_ZCL_TYPE_ENUM16 },
        { "semi", ZCL_ZCL_TYPE_SEMI },
        { "single", ZCL_ZCL_TYPE_SINGLE },
        { "double", ZCL_ZCL_TYPE_DOUBLE },
        { "octstr", ZCL_ZCL_TYPE_OCTSTR },
        { "string", ZCL_ZCL_TYPE_STRING },
        { "octstr16", ZCL_ZCL_TYPE_OCTSTR16 },
        { "string16", ZCL_ZCL_TYPE_STRING16 },
        { "array", ZCL_ZCL_TYPE_ARRAY },
        { "struct", ZCL_ZCL_TYPE_STRUCT },
        { "set", ZCL_ZCL_TYPE_SET },
        { "bag", ZCL_ZCL_TYPE_BAG },
        { "ToD", ZCL_ZCL_TYPE_TO_D },
        { "date", ZCL_ZCL_TYPE_DATE },
        { "UTC", ZCL_ZCL_TYPE_UTC },
        { "clusterId", ZCL_ZCL_TYPE_CLUSTER_ID },
        { "attribId", ZCL_ZCL_TYPE_ATTRIB_ID },
        { "bacOID", ZCL_ZCL_TYPE_BAC_OID },
        { "EUI64", ZCL_ZCL_TYPE_EUI64 },
        { "key128", ZCL_ZCL_TYPE_KEY128 },
        { "unk", ZCL_ZCL_TYPE_UNK }
      };
      return boost::optional<external_type>(enum_map[str]);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {
    std::map<external_type, internal_type> enum_map = {
      { ZCL_ZCL_TYPE_NODATA, "nodata" },
      { ZCL_ZCL_TYPE_DATA8, "data8" },
      { ZCL_ZCL_TYPE_DATA16, "data16" },
      { ZCL_ZCL_TYPE_DATA24, "data24" },
      { ZCL_ZCL_TYPE_DATA32, "data32" },
      { ZCL_ZCL_TYPE_DATA40, "data40" },
      { ZCL_ZCL_TYPE_DATA48, "data48" },
      { ZCL_ZCL_TYPE_DATA56, "data56" },
      { ZCL_ZCL_TYPE_DATA64, "data64" },
      { ZCL_ZCL_TYPE_BOOL, "bool" },
      { ZCL_ZCL_TYPE_MAP8, "map8" },
      { ZCL_ZCL_TYPE_MAP16, "map16" },
      { ZCL_ZCL_TYPE_MAP24, "map24" },
      { ZCL_ZCL_TYPE_MAP32, "map32" },
      { ZCL_ZCL_TYPE_MAP40, "map40" },
      { ZCL_ZCL_TYPE_MAP48, "map48" },
      { ZCL_ZCL_TYPE_MAP56, "map56" },
      { ZCL_ZCL_TYPE_MAP64, "map64" },
      { ZCL_ZCL_TYPE_UINT8, "uint8" },
      { ZCL_ZCL_TYPE_UINT16, "uint16" },
      { ZCL_ZCL_TYPE_UINT24, "uint24" },
      { ZCL_ZCL_TYPE_UINT32, "uint32" },
      { ZCL_ZCL_TYPE_UINT40, "uint40" },
      { ZCL_ZCL_TYPE_UINT48, "uint48" },
      { ZCL_ZCL_TYPE_UINT56, "uint56" },
      { ZCL_ZCL_TYPE_UINT64, "uint64" },
      { ZCL_ZCL_TYPE_INT8, "int8" },
      { ZCL_ZCL_TYPE_INT16, "int16" },
      { ZCL_ZCL_TYPE_INT24, "int24" },
      { ZCL_ZCL_TYPE_INT32, "int32" },
      { ZCL_ZCL_TYPE_INT40, "int40" },
      { ZCL_ZCL_TYPE_INT48, "int48" },
      { ZCL_ZCL_TYPE_INT56, "int56" },
      { ZCL_ZCL_TYPE_INT64, "int64" },
      { ZCL_ZCL_TYPE_ENUM8, "enum8" },
      { ZCL_ZCL_TYPE_ENUM16, "enum16" },
      { ZCL_ZCL_TYPE_SEMI, "semi" },
      { ZCL_ZCL_TYPE_SINGLE, "single" },
      { ZCL_ZCL_TYPE_DOUBLE, "double" },
      { ZCL_ZCL_TYPE_OCTSTR, "octstr" },
      { ZCL_ZCL_TYPE_STRING, "string" },
      { ZCL_ZCL_TYPE_OCTSTR16, "octstr16" },
      { ZCL_ZCL_TYPE_STRING16, "string16" },
      { ZCL_ZCL_TYPE_ARRAY, "array" },
      { ZCL_ZCL_TYPE_STRUCT, "struct" },
      { ZCL_ZCL_TYPE_SET, "set" },
      { ZCL_ZCL_TYPE_BAG, "bag" },
      { ZCL_ZCL_TYPE_TO_D, "ToD" },
      { ZCL_ZCL_TYPE_DATE, "date" },
      { ZCL_ZCL_TYPE_UTC, "UTC" },
      { ZCL_ZCL_TYPE_CLUSTER_ID, "clusterId" },
      { ZCL_ZCL_TYPE_ATTRIB_ID, "attribId" },
      { ZCL_ZCL_TYPE_BAC_OID, "bacOID" },
      { ZCL_ZCL_TYPE_EUI64, "EUI64" },
      { ZCL_ZCL_TYPE_KEY128, "key128" },
      { ZCL_ZCL_TYPE_UNK, "unk" }
    };
    return boost::optional<internal_type>(enum_map[e]);
  }
};


struct IasaceZoneStatusRecordTranslator {
  typedef std::string internal_type;
  typedef IasaceZoneStatusRecord   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      external_type new_external_instance;

      std::stringstream ss;
      bpt::ptree pt;
      ss << str;
      bpt::json_parser::read_json(ss, pt);

        new_external_instance.ZoneID = pt.get<uint8_t>("ZoneID");
        new_external_instance.ZoneStatus = pt.get<uint16_t>("ZoneStatus");

      return boost::optional<external_type>(new_external_instance);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {

    bpt::ptree doc;

      doc.add("ZoneID", e.ZoneID);
      doc.add("ZoneStatus", e.ZoneStatus);

    std::stringstream ss;
    bpt::write_json(ss, doc);

    return boost::optional<internal_type>(ss.str());
  }
};

struct SExtensionFieldSetListTranslator {
  typedef std::string internal_type;
  typedef SExtensionFieldSetList   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      external_type new_external_instance;

      std::stringstream ss;
      bpt::ptree pt;
      ss << str;
      bpt::json_parser::read_json(ss, pt);

        new_external_instance.ClusterId = pt.get<uint16_t>("ClusterId");
        new_external_instance.ExtensionFieldSet = pt.get<const char*>("ExtensionFieldSet");

      return boost::optional<external_type>(new_external_instance);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {

    bpt::ptree doc;

      doc.add("ClusterId", e.ClusterId);
      doc.add("ExtensionFieldSet", e.ExtensionFieldSet);

    std::stringstream ss;
    bpt::write_json(ss, doc);

    return boost::optional<internal_type>(ss.str());
  }
};

struct TLDeviceInformationRecordTranslator {
  typedef std::string internal_type;
  typedef TLDeviceInformationRecord   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      external_type new_external_instance;

      std::stringstream ss;
      bpt::ptree pt;
      ss << str;
      bpt::json_parser::read_json(ss, pt);

        new_external_instance.IEEEAddress = pt.get<EUI64>("IEEEAddress");
        new_external_instance.EndpointIdentifier = pt.get<uint8_t>("EndpointIdentifier");
        new_external_instance.ProfileIndentifier = pt.get<uint16_t>("ProfileIndentifier");
        new_external_instance.DeviceIdentifier = pt.get<uint16_t>("DeviceIdentifier");
        new_external_instance.Version = pt.get<uint8_t>("Version");
        new_external_instance.GroupIdentifierCount = pt.get<uint8_t>("GroupIdentifierCount");
        new_external_instance.Sort = pt.get<uint8_t>("Sort");

      return boost::optional<external_type>(new_external_instance);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {

    bpt::ptree doc;

      doc.add("IEEEAddress", e.IEEEAddress);
      doc.add("EndpointIdentifier", e.EndpointIdentifier);
      doc.add("ProfileIndentifier", e.ProfileIndentifier);
      doc.add("DeviceIdentifier", e.DeviceIdentifier);
      doc.add("Version", e.Version);
      doc.add("GroupIdentifierCount", e.GroupIdentifierCount);
      doc.add("Sort", e.Sort);

    std::stringstream ss;
    bpt::write_json(ss, doc);

    return boost::optional<internal_type>(ss.str());
  }
};

struct TLEndpointInformationRecordTranslator {
  typedef std::string internal_type;
  typedef TLEndpointInformationRecord   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      external_type new_external_instance;

      std::stringstream ss;
      bpt::ptree pt;
      ss << str;
      bpt::json_parser::read_json(ss, pt);

        new_external_instance.NetworkAddress = pt.get<uint16_t>("NetworkAddress");
        new_external_instance.EndpointIdentifier = pt.get<uint8_t>("EndpointIdentifier");
        new_external_instance.ProfileIdentifier = pt.get<uint16_t>("ProfileIdentifier");
        new_external_instance.DeviceIdentifier = pt.get<uint16_t>("DeviceIdentifier");
        new_external_instance.Version = pt.get<uint8_t>("Version");

      return boost::optional<external_type>(new_external_instance);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {

    bpt::ptree doc;

      doc.add("NetworkAddress", e.NetworkAddress);
      doc.add("EndpointIdentifier", e.EndpointIdentifier);
      doc.add("ProfileIdentifier", e.ProfileIdentifier);
      doc.add("DeviceIdentifier", e.DeviceIdentifier);
      doc.add("Version", e.Version);

    std::stringstream ss;
    bpt::write_json(ss, doc);

    return boost::optional<internal_type>(ss.str());
  }
};

struct TLGroupInformationRecordTranslator {
  typedef std::string internal_type;
  typedef TLGroupInformationRecord   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      external_type new_external_instance;

      std::stringstream ss;
      bpt::ptree pt;
      ss << str;
      bpt::json_parser::read_json(ss, pt);

        new_external_instance.GroupIdentifier = pt.get<uint16_t>("GroupIdentifier");
        new_external_instance.GroupType = pt.get<uint8_t>("GroupType");

      return boost::optional<external_type>(new_external_instance);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {

    bpt::ptree doc;

      doc.add("GroupIdentifier", e.GroupIdentifier);
      doc.add("GroupType", e.GroupType);

    std::stringstream ss;
    bpt::write_json(ss, doc);

    return boost::optional<internal_type>(ss.str());
  }
};

struct TransitionTypeTranslator {
  typedef std::string internal_type;
  typedef TransitionType   external_type;

  boost::optional<external_type> get_value(const internal_type& str)
  {
    if (!str.empty())
    {
      external_type new_external_instance;

      std::stringstream ss;
      bpt::ptree pt;
      ss << str;
      bpt::json_parser::read_json(ss, pt);

        new_external_instance.TransitionTime = pt.get<uint16_t>("TransitionTime");
        new_external_instance.HeatSetPoint = pt.get<int16_t>("HeatSetPoint");
        new_external_instance.CoolSetPoint = pt.get<int16_t>("CoolSetPoint");

      return boost::optional<external_type>(new_external_instance);
    }
    else
    {
      return boost::optional<external_type>(boost::none);
    }
  }

  boost::optional<internal_type> put_value(const external_type& e) {

    bpt::ptree doc;

      doc.add("TransitionTime", e.TransitionTime);
      doc.add("HeatSetPoint", e.HeatSetPoint);
      doc.add("CoolSetPoint", e.CoolSetPoint);

    std::stringstream ss;
    bpt::write_json(ss, doc);

    return boost::optional<internal_type>(ss.str());
  }
};



namespace boost {
namespace property_tree {

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, const char*>
{
  typedef constCharPtrTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ArmArmMode>
{
    typedef ArmArmModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ArmResponseArmNotification>
{
    typedef ArmResponseArmNotificationTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, BarrierControlMovingState>
{
    typedef BarrierControlMovingStateTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, BasicGenericDeviceClass>
{
    typedef BasicGenericDeviceClassTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, BasicGenericDeviceType>
{
    typedef BasicGenericDeviceTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, BasicPhysicalEnvironment>
{
    typedef BasicPhysicalEnvironmentTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, BasicPowerSource>
{
    typedef BasicPowerSourceTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, BatterySize>
{
    typedef BatterySizeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, BypassResponseZoneIDBypassResult>
{
    typedef BypassResponseZoneIDBypassResultTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, CCColorLoopDirection>
{
    typedef CCColorLoopDirectionTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, CCDirection>
{
    typedef CCDirectionTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, CCMoveMode>
{
    typedef CCMoveModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, CCStepMode>
{
    typedef CCStepModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ColorControlColorLoopActive>
{
    typedef ColorControlColorLoopActiveTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ColorControlColorMode>
{
    typedef ColorControlColorModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ColorControlDriftCompensation>
{
    typedef ColorControlDriftCompensationTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ColorControlEnhancedColorMode>
{
    typedef ColorControlEnhancedColorModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ColorLoopSetAction>
{
    typedef ColorLoopSetActionTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, CommissioningNetworkKeyType>
{
    typedef CommissioningNetworkKeyTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, CommissioningProtocolVersion>
{
    typedef CommissioningProtocolVersionTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, CommissioningStackProfile>
{
    typedef CommissioningStackProfileTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, CommissioningStartupControl>
{
    typedef CommissioningStartupControlTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DehumidificationControlDehumidificationLockout>
{
    typedef DehumidificationControlDehumidificationLockoutTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DehumidificationControlRelativeHumidityDisplay>
{
    typedef DehumidificationControlRelativeHumidityDisplayTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DehumidificationControlRelativeHumidityMode>
{
    typedef DehumidificationControlRelativeHumidityModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DoorLockDoorState>
{
    typedef DoorLockDoorStateTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DoorLockLEDSettings>
{
    typedef DoorLockLEDSettingsTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DoorLockLockState>
{
    typedef DoorLockLockStateTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DoorLockLockType>
{
    typedef DoorLockLockTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DoorLockSecurityLevel>
{
    typedef DoorLockSecurityLevelTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DoorLockSoundVolume>
{
    typedef DoorLockSoundVolumeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DrlkOperEventSource>
{
    typedef DrlkOperEventSourceTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DrlkOperMode>
{
    typedef DrlkOperModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DrlkPassFailStatus>
{
    typedef DrlkPassFailStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DrlkSetCodeStatus>
{
    typedef DrlkSetCodeStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DrlkSettableUserStatus>
{
    typedef DrlkSettableUserStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DrlkUserStatus>
{
    typedef DrlkUserStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, DrlkUserType>
{
    typedef DrlkUserTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, FanControlFanMode>
{
    typedef FanControlFanModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, FanControlFanModeSequence>
{
    typedef FanControlFanModeSequenceTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, GetLogRecordResponseEventType>
{
    typedef GetLogRecordResponseEventTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, GetMeasurementProfileResponseStatus>
{
    typedef GetMeasurementProfileResponseStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, HVACSystemTypeConfigurationCoolingSystemStage>
{
    typedef HVACSystemTypeConfigurationCoolingSystemStageTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, HVACSystemTypeConfigurationHeatingFuelSource>
{
    typedef HVACSystemTypeConfigurationHeatingFuelSourceTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, HVACSystemTypeConfigurationHeatingSystemStage>
{
    typedef HVACSystemTypeConfigurationHeatingSystemStageTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, HVACSystemTypeConfigurationHeatingSystemType>
{
    typedef HVACSystemTypeConfigurationHeatingSystemTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IASZoneZoneState>
{
    typedef IASZoneZoneStateTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IasZoneType>
{
    typedef IasZoneTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IasacPanelStatus>
{
    typedef IasacPanelStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IasaceAlarmStatus>
{
    typedef IasaceAlarmStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IasaceAudibleNotification>
{
    typedef IasaceAudibleNotificationTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IaswdLevel>
{
    typedef IaswdLevelTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IlluminanceLevelSensingLevelStatus>
{
    typedef IlluminanceLevelSensingLevelStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IlluminanceLevelSensingLightSensorType>
{
    typedef IlluminanceLevelSensingLightSensorTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IlluminanceMeasurementLightSensorType>
{
    typedef IlluminanceMeasurementLightSensorTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ImageNotifyPayloadType>
{
    typedef ImageNotifyPayloadTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, MoveStepMode>
{
    typedef MoveStepModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OTADeviceSpecificImageType>
{
    typedef OTADeviceSpecificImageTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OTAUpgradeImageUpgradeStatus>
{
    typedef OTAUpgradeImageUpgradeStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OTAUpgradeUpgradeActivationPolicy>
{
    typedef OTAUpgradeUpgradeActivationPolicyTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OTAUpgradeUpgradeTimeoutPolicy>
{
    typedef OTAUpgradeUpgradeTimeoutPolicyTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OccupancySensingOccupancySensorType>
{
    typedef OccupancySensingOccupancySensorTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OffWithEffectEffectIdentifier>
{
    typedef OffWithEffectEffectIdentifierTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OnOffStartUpOnOff>
{
    typedef OnOffStartUpOnOffTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OperatingEventNotificationOperationEventCode>
{
    typedef OperatingEventNotificationOperationEventCodeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, OptionsStartupMode>
{
    typedef OptionsStartupModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ProfileIntervalPeriod>
{
    typedef ProfileIntervalPeriodTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ProgrammingEventNotificationProgramEventCode>
{
    typedef ProgrammingEventNotificationProgramEventCodeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ProgrammingEventNotificationProgramEventSource>
{
    typedef ProgrammingEventNotificationProgramEventSourceTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, PumpControlMode>
{
    typedef PumpControlModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, PumpOperationMode>
{
    typedef PumpOperationModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, SHDCFGDirection>
{
    typedef SHDCFGDirectionTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, SetpointRaiseOrLowerMode>
{
    typedef SetpointRaiseOrLowerModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ShadeConfigurationMode>
{
    typedef ShadeConfigurationModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, SirenConfigurationStrobe>
{
    typedef SirenConfigurationStrobeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, SirenConfigurationWarningMode>
{
    typedef SirenConfigurationWarningModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, SquawkConfigurationSquawkMode>
{
    typedef SquawkConfigurationSquawkModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TLKeyIndex>
{
    typedef TLKeyIndexTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TLStatus>
{
    typedef TLStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TLZigbeeInformationLogicalType>
{
    typedef TLZigbeeInformationLogicalTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatACCapacityFormat>
{
    typedef ThermostatACCapacityFormatTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatACCompressorType>
{
    typedef ThermostatACCompressorTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatACLouverPosition>
{
    typedef ThermostatACLouverPositionTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatACRefrigerantType>
{
    typedef ThermostatACRefrigerantTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatACType>
{
    typedef ThermostatACTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatControlSequenceOfOperation>
{
    typedef ThermostatControlSequenceOfOperationTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatProgrammingOperationModeProgrammingMode>
{
    typedef ThermostatProgrammingOperationModeProgrammingModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatSetpointChangeSource>
{
    typedef ThermostatSetpointChangeSourceTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatStartOfWeek>
{
    typedef ThermostatStartOfWeekTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatSystemMode>
{
    typedef ThermostatSystemModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatTemperatureSetpointHold>
{
    typedef ThermostatTemperatureSetpointHoldTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatThermostatRunningMode>
{
    typedef ThermostatThermostatRunningModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatUserInterfaceConfigurationKeypadLockout>
{
    typedef ThermostatUserInterfaceConfigurationKeypadLockoutTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatUserInterfaceConfigurationScheduleProgrammingVisibility>
{
    typedef ThermostatUserInterfaceConfigurationScheduleProgrammingVisibilityTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ThermostatUserInterfaceConfigurationTemperatureDisplayMode>
{
    typedef ThermostatUserInterfaceConfigurationTemperatureDisplayModeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TriggerEffectEffectIdentifier>
{
    typedef TriggerEffectEffectIdentifierTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TriggerEffectEffectVariant>
{
    typedef TriggerEffectEffectVariantTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, WindowCoveringWindowCoveringType>
{
    typedef WindowCoveringWindowCoveringTypeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, ZoneEnrollResponseEnrollResponseCode>
{
    typedef ZoneEnrollResponseEnrollResponseCodeTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, attributeReportingStatus>
{
    typedef attributeReportingStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, zclStatus>
{
    typedef zclStatusTranslator type;
};

template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, zclType>
{
    typedef zclTypeTranslator type;
};



template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, IasaceZoneStatusRecord>
{
    typedef IasaceZoneStatusRecordTranslator type;
};
template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, SExtensionFieldSetList>
{
    typedef SExtensionFieldSetListTranslator type;
};
template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TLDeviceInformationRecord>
{
    typedef TLDeviceInformationRecordTranslator type;
};
template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TLEndpointInformationRecord>
{
    typedef TLEndpointInformationRecordTranslator type;
};
template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TLGroupInformationRecord>
{
    typedef TLGroupInformationRecordTranslator type;
};
template<typename Ch, typename Traits, typename Alloc>
struct translator_between<std::basic_string< Ch, Traits, Alloc >, TransitionType>
{
    typedef TransitionTypeTranslator type;
};

} // namespace property_tree
} // namespace boost

#endif
