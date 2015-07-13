#ifndef _RMW_FASTRTPS_CPP_SERVICETYPESUPPORT_H_
#define _RMW_FASTRTPS_CPP_SERVICETYPESUPPORT_H_

#include "TypeSupport.h"

struct CustomServiceInfo;

namespace rmw_fastrtps_cpp
{
    class ServiceTypeSupport : public TypeSupport
    {
        public:

            virtual bool serialize(void *data, SerializedPayload_t *payload) = 0;

            virtual bool deserialize(SerializedPayload_t *payload, void *data) = 0;

            virtual void* createData() = 0;

            virtual bool serializeROSmessage(const void *ros_message, void *data) = 0;

            virtual bool deserializeROSmessage(const void* data, void *ros_message) = 0;

        protected:

            ServiceTypeSupport();
    };

    class RequestTypeSupport : public ServiceTypeSupport
    {
        public:

            typedef struct RequestBuffer
            {
                uint32_t length;
                char *pointer;
            } Buffer;

            RequestTypeSupport(const rosidl_typesupport_introspection_cpp::ServiceMembers *members);

            bool serialize(void *data, SerializedPayload_t *payload);

            bool deserialize(SerializedPayload_t *payload, void *data);

            void* createData();

            bool serializeROSmessage(const void *ros_message, void *data);

            bool deserializeROSmessage(const void* data, void *ros_message);

            static void* create_data(size_t dataSize);

            static void delete_data(void *data);

            static void copy_data(RequestBuffer *dst, const RequestBuffer *src);
    };

    class ResponseTypeSupport : public ServiceTypeSupport
    {
        public:

            typedef struct ResponseBuffer
            {
                uint32_t length;
                char *pointer;
            } Buffer;

            ResponseTypeSupport(const rosidl_typesupport_introspection_cpp::ServiceMembers *members);

            bool serialize(void *data, SerializedPayload_t *payload);

            bool deserialize(SerializedPayload_t *payload, void *data);

            void* createData();

            bool serializeROSmessage(const void *ros_message, void *data);

            bool deserializeROSmessage(const void* data, void *ros_message);

            static void* create_data(size_t dataSize);

            static void delete_data(void *data);

            static void copy_data(ResponseBuffer *dst, const ResponseBuffer *src);
    };
}


#endif // _RMW_FASTRTPS_CPP_SERVICETYPESUPPORT_H_
