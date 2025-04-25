// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/Permission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/srv/permission.hpp"


#ifndef INTERFACES__SRV__DETAIL__PERMISSION__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__PERMISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/permission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Permission_Request_who
{
public:
  Init_Permission_Request_who()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Permission_Request who(::interfaces::srv::Permission_Request::_who_type arg)
  {
    msg_.who = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Permission_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Permission_Request>()
{
  return interfaces::srv::builder::Init_Permission_Request_who();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Permission_Response_granted
{
public:
  Init_Permission_Response_granted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Permission_Response granted(::interfaces::srv::Permission_Response::_granted_type arg)
  {
    msg_.granted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Permission_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Permission_Response>()
{
  return interfaces::srv::builder::Init_Permission_Response_granted();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Permission_Event_response
{
public:
  explicit Init_Permission_Event_response(::interfaces::srv::Permission_Event & msg)
  : msg_(msg)
  {}
  ::interfaces::srv::Permission_Event response(::interfaces::srv::Permission_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Permission_Event msg_;
};

class Init_Permission_Event_request
{
public:
  explicit Init_Permission_Event_request(::interfaces::srv::Permission_Event & msg)
  : msg_(msg)
  {}
  Init_Permission_Event_response request(::interfaces::srv::Permission_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Permission_Event_response(msg_);
  }

private:
  ::interfaces::srv::Permission_Event msg_;
};

class Init_Permission_Event_info
{
public:
  Init_Permission_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Permission_Event_request info(::interfaces::srv::Permission_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Permission_Event_request(msg_);
  }

private:
  ::interfaces::srv::Permission_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Permission_Event>()
{
  return interfaces::srv::builder::Init_Permission_Event_info();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__PERMISSION__BUILDER_HPP_
