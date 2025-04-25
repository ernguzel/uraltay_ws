// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:srv/Permission.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "interfaces/srv/detail/permission__functions.h"
#include "interfaces/srv/detail/permission__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void Permission_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) interfaces::srv::Permission_Request(_init);
}

void Permission_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<interfaces::srv::Permission_Request *>(message_memory);
  typed_message->~Permission_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Permission_Request_message_member_array[1] = {
  {
    "who",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces::srv::Permission_Request, who),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Permission_Request_message_members = {
  "interfaces::srv",  // message namespace
  "Permission_Request",  // message name
  1,  // number of fields
  sizeof(interfaces::srv::Permission_Request),
  false,  // has_any_key_member_
  Permission_Request_message_member_array,  // message members
  Permission_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Permission_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Permission_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Permission_Request_message_members,
  get_message_typesupport_handle_function,
  &interfaces__srv__Permission_Request__get_type_hash,
  &interfaces__srv__Permission_Request__get_type_description,
  &interfaces__srv__Permission_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::srv::Permission_Request>()
{
  return &::interfaces::srv::rosidl_typesupport_introspection_cpp::Permission_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, srv, Permission_Request)() {
  return &::interfaces::srv::rosidl_typesupport_introspection_cpp::Permission_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "interfaces/srv/detail/permission__functions.h"
// already included above
// #include "interfaces/srv/detail/permission__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void Permission_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) interfaces::srv::Permission_Response(_init);
}

void Permission_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<interfaces::srv::Permission_Response *>(message_memory);
  typed_message->~Permission_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Permission_Response_message_member_array[1] = {
  {
    "granted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces::srv::Permission_Response, granted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Permission_Response_message_members = {
  "interfaces::srv",  // message namespace
  "Permission_Response",  // message name
  1,  // number of fields
  sizeof(interfaces::srv::Permission_Response),
  false,  // has_any_key_member_
  Permission_Response_message_member_array,  // message members
  Permission_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Permission_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Permission_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Permission_Response_message_members,
  get_message_typesupport_handle_function,
  &interfaces__srv__Permission_Response__get_type_hash,
  &interfaces__srv__Permission_Response__get_type_description,
  &interfaces__srv__Permission_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::srv::Permission_Response>()
{
  return &::interfaces::srv::rosidl_typesupport_introspection_cpp::Permission_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, srv, Permission_Response)() {
  return &::interfaces::srv::rosidl_typesupport_introspection_cpp::Permission_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "interfaces/srv/detail/permission__functions.h"
// already included above
// #include "interfaces/srv/detail/permission__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void Permission_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) interfaces::srv::Permission_Event(_init);
}

void Permission_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<interfaces::srv::Permission_Event *>(message_memory);
  typed_message->~Permission_Event();
}

size_t size_function__Permission_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<interfaces::srv::Permission_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Permission_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<interfaces::srv::Permission_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__Permission_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<interfaces::srv::Permission_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__Permission_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const interfaces::srv::Permission_Request *>(
    get_const_function__Permission_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<interfaces::srv::Permission_Request *>(untyped_value);
  value = item;
}

void assign_function__Permission_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<interfaces::srv::Permission_Request *>(
    get_function__Permission_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const interfaces::srv::Permission_Request *>(untyped_value);
  item = value;
}

void resize_function__Permission_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<interfaces::srv::Permission_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Permission_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<interfaces::srv::Permission_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Permission_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<interfaces::srv::Permission_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__Permission_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<interfaces::srv::Permission_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__Permission_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const interfaces::srv::Permission_Response *>(
    get_const_function__Permission_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<interfaces::srv::Permission_Response *>(untyped_value);
  value = item;
}

void assign_function__Permission_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<interfaces::srv::Permission_Response *>(
    get_function__Permission_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const interfaces::srv::Permission_Response *>(untyped_value);
  item = value;
}

void resize_function__Permission_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<interfaces::srv::Permission_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Permission_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces::srv::Permission_Event, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<interfaces::srv::Permission_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(interfaces::srv::Permission_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__Permission_Event__request,  // size() function pointer
    get_const_function__Permission_Event__request,  // get_const(index) function pointer
    get_function__Permission_Event__request,  // get(index) function pointer
    fetch_function__Permission_Event__request,  // fetch(index, &value) function pointer
    assign_function__Permission_Event__request,  // assign(index, value) function pointer
    resize_function__Permission_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<interfaces::srv::Permission_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(interfaces::srv::Permission_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__Permission_Event__response,  // size() function pointer
    get_const_function__Permission_Event__response,  // get_const(index) function pointer
    get_function__Permission_Event__response,  // get(index) function pointer
    fetch_function__Permission_Event__response,  // fetch(index, &value) function pointer
    assign_function__Permission_Event__response,  // assign(index, value) function pointer
    resize_function__Permission_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Permission_Event_message_members = {
  "interfaces::srv",  // message namespace
  "Permission_Event",  // message name
  3,  // number of fields
  sizeof(interfaces::srv::Permission_Event),
  false,  // has_any_key_member_
  Permission_Event_message_member_array,  // message members
  Permission_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  Permission_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Permission_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Permission_Event_message_members,
  get_message_typesupport_handle_function,
  &interfaces__srv__Permission_Event__get_type_hash,
  &interfaces__srv__Permission_Event__get_type_description,
  &interfaces__srv__Permission_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::srv::Permission_Event>()
{
  return &::interfaces::srv::rosidl_typesupport_introspection_cpp::Permission_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, srv, Permission_Event)() {
  return &::interfaces::srv::rosidl_typesupport_introspection_cpp::Permission_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "interfaces/srv/detail/permission__functions.h"
// already included above
// #include "interfaces/srv/detail/permission__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers Permission_service_members = {
  "interfaces::srv",  // service namespace
  "Permission",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<interfaces::srv::Permission>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t Permission_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Permission_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<interfaces::srv::Permission_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<interfaces::srv::Permission_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<interfaces::srv::Permission_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<interfaces::srv::Permission>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<interfaces::srv::Permission>,
  &interfaces__srv__Permission__get_type_hash,
  &interfaces__srv__Permission__get_type_description,
  &interfaces__srv__Permission__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<interfaces::srv::Permission>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::interfaces::srv::rosidl_typesupport_introspection_cpp::Permission_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure all of the service_members are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr ||
    service_members->event_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::interfaces::srv::Permission_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::interfaces::srv::Permission_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::interfaces::srv::Permission_Event
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, srv, Permission)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<interfaces::srv::Permission>();
}

#ifdef __cplusplus
}
#endif
