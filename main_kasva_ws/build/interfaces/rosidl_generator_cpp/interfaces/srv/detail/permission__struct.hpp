// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/Permission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces/srv/permission.hpp"


#ifndef INTERFACES__SRV__DETAIL__PERMISSION__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__PERMISSION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__Permission_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__Permission_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Permission_Request_
{
  using Type = Permission_Request_<ContainerAllocator>;

  explicit Permission_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->who = "";
    }
  }

  explicit Permission_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : who(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->who = "";
    }
  }

  // field types and members
  using _who_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _who_type who;

  // setters for named parameter idiom
  Type & set__who(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->who = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::Permission_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::Permission_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::Permission_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::Permission_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Permission_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Permission_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Permission_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Permission_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::Permission_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::Permission_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__Permission_Request
    std::shared_ptr<interfaces::srv::Permission_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__Permission_Request
    std::shared_ptr<interfaces::srv::Permission_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Permission_Request_ & other) const
  {
    if (this->who != other.who) {
      return false;
    }
    return true;
  }
  bool operator!=(const Permission_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Permission_Request_

// alias to use template instance with default allocator
using Permission_Request =
  interfaces::srv::Permission_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__Permission_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__Permission_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Permission_Response_
{
  using Type = Permission_Response_<ContainerAllocator>;

  explicit Permission_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->granted = false;
    }
  }

  explicit Permission_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->granted = false;
    }
  }

  // field types and members
  using _granted_type =
    bool;
  _granted_type granted;

  // setters for named parameter idiom
  Type & set__granted(
    const bool & _arg)
  {
    this->granted = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::Permission_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::Permission_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::Permission_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::Permission_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Permission_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Permission_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Permission_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Permission_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::Permission_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::Permission_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__Permission_Response
    std::shared_ptr<interfaces::srv::Permission_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__Permission_Response
    std::shared_ptr<interfaces::srv::Permission_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Permission_Response_ & other) const
  {
    if (this->granted != other.granted) {
      return false;
    }
    return true;
  }
  bool operator!=(const Permission_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Permission_Response_

// alias to use template instance with default allocator
using Permission_Response =
  interfaces::srv::Permission_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__srv__Permission_Event __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__Permission_Event __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Permission_Event_
{
  using Type = Permission_Event_<ContainerAllocator>;

  explicit Permission_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Permission_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<interfaces::srv::Permission_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<interfaces::srv::Permission_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<interfaces::srv::Permission_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<interfaces::srv::Permission_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<interfaces::srv::Permission_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<interfaces::srv::Permission_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<interfaces::srv::Permission_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<interfaces::srv::Permission_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::Permission_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::Permission_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::Permission_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::Permission_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Permission_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Permission_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Permission_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Permission_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::Permission_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::Permission_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__Permission_Event
    std::shared_ptr<interfaces::srv::Permission_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__Permission_Event
    std::shared_ptr<interfaces::srv::Permission_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Permission_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Permission_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Permission_Event_

// alias to use template instance with default allocator
using Permission_Event =
  interfaces::srv::Permission_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct Permission
{
  using Request = interfaces::srv::Permission_Request;
  using Response = interfaces::srv::Permission_Response;
  using Event = interfaces::srv::Permission_Event;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__PERMISSION__STRUCT_HPP_
