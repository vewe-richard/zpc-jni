# Install script for directory: /home/richard/disks/sdb6/2023/pytronic/UnifySDK/applications/zpc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/applications/zpc/components/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/applications/zpc/applications/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xuic-zpcx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zpc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zpc")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zpc"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/applications/zpc/zpc")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zpc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zpc")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zpc"
         OLD_RPATH "/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_main:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_attribute_mapper:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_smartstart_management:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_attribute_utils:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_ota:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_attribute_resolver:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_dotdot_mqtt:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_stdin:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_mqtt:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_main_fd:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_contiki:/usr/local/lib:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_attribute_store:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_datastore:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_log:/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/components/uic_config:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zpc")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xuic-zpcx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bash-completion/completions" TYPE FILE FILES "/home/richard/disks/sdb6/2023/pytronic/UnifySDK/applications/zpc/scripts/bash-completion/zpc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xuic-zpcx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/uic" TYPE DIRECTORY FILES "/home/richard/disks/sdb6/2023/pytronic/UnifySDK/applications/zpc/components/dotdot_mapper/rules" FILES_MATCHING REGEX "/[^/]*\\.uam$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xuic-zpcx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/var/lib/zpc/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/var/lib/zpc" TYPE DIRECTORY FILES "")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xuic-zpcx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/lib/systemd/system/uic-zpc.service")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/lib/systemd/system" TYPE FILE FILES "/home/richard/disks/sdb6/2023/pytronic/UnifySDK/applications/zpc/scripts/systemd/uic-zpc.service")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xuic-zpcx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/udev/rules.d/99-leds.rules")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/udev/rules.d" TYPE FILE FILES "/home/richard/disks/sdb6/2023/pytronic/UnifySDK/applications/zpc/scripts/udev/99-leds.rules")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xuic-zpcx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/zpc/node_identify_rpi4_led.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/zpc" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_EXECUTE GROUP_READ WORLD_READ WORLD_EXECUTE FILES "/home/richard/disks/sdb6/2023/pytronic/UnifySDK/build/applications/zpc/node_identify_rpi4_led.sh")
endif()

