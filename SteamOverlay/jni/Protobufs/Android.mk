    LOCAL_PATH := $(call my-dir)
    
    include $(CLEAR_VARS)
    
    CC_LITE_SRC_FILES := \
        src/google/protobuf/stubs/common.cc                              \
        src/google/protobuf/stubs/once.cc                                \
        src/google/protobuf/stubs/hash.cc                                \
        src/google/protobuf/extension_set.cc                             \
        src/google/protobuf/generated_message_util.cc                    \
        src/google/protobuf/message_lite.cc                              \
        src/google/protobuf/repeated_field.cc                            \
        src/google/protobuf/wire_format_lite.cc                          \
        src/google/protobuf/io/coded_stream.cc                           \
        src/google/protobuf/io/zero_copy_stream.cc                       \
        src/google/protobuf/io/zero_copy_stream_impl_lite.cc


    COMPILER_SRC_FILES :=  \
        src/google/protobuf/descriptor.cc \
        src/google/protobuf/descriptor.pb.cc \
        src/google/protobuf/descriptor_database.cc \
        src/google/protobuf/dynamic_message.cc \
        src/google/protobuf/extension_set.cc \
        src/google/protobuf/extension_set_heavy.cc \
        src/google/protobuf/generated_message_reflection.cc \
        src/google/protobuf/generated_message_util.cc \
        src/google/protobuf/message.cc \
        src/google/protobuf/message_lite.cc \
        src/google/protobuf/reflection_ops.cc \
        src/google/protobuf/repeated_field.cc \
        src/google/protobuf/service.cc \
        src/google/protobuf/text_format.cc \
        src/google/protobuf/unknown_field_set.cc \
        src/google/protobuf/wire_format.cc \
        src/google/protobuf/wire_format_lite.cc \
        src/google/protobuf/compiler/code_generator.cc \
        src/google/protobuf/compiler/command_line_interface.cc \
        src/google/protobuf/compiler/importer.cc \
        src/google/protobuf/compiler/main.cc \
        src/google/protobuf/compiler/parser.cc \
        src/google/protobuf/compiler/plugin.cc \
        src/google/protobuf/compiler/plugin.pb.cc \
        src/google/protobuf/compiler/subprocess.cc \
        src/google/protobuf/compiler/zip_writer.cc \
        src/google/protobuf/compiler/cpp/cpp_enum.cc \
        src/google/protobuf/compiler/cpp/cpp_enum_field.cc \
        src/google/protobuf/compiler/cpp/cpp_extension.cc \
        src/google/protobuf/compiler/cpp/cpp_field.cc \
        src/google/protobuf/compiler/cpp/cpp_file.cc \
        src/google/protobuf/compiler/cpp/cpp_generator.cc \
        src/google/protobuf/compiler/cpp/cpp_helpers.cc \
        src/google/protobuf/compiler/cpp/cpp_message.cc \
        src/google/protobuf/compiler/cpp/cpp_message_field.cc \
        src/google/protobuf/compiler/cpp/cpp_primitive_field.cc \
        src/google/protobuf/compiler/cpp/cpp_service.cc \
        src/google/protobuf/compiler/cpp/cpp_string_field.cc \
        src/google/protobuf/compiler/java/java_enum.cc \
        src/google/protobuf/compiler/java/java_enum_field.cc \
        src/google/protobuf/compiler/java/java_extension.cc \
        src/google/protobuf/compiler/java/java_field.cc \
        src/google/protobuf/compiler/java/java_file.cc \
        src/google/protobuf/compiler/java/java_generator.cc \
        src/google/protobuf/compiler/java/java_helpers.cc \
        src/google/protobuf/compiler/java/java_message.cc \
        src/google/protobuf/compiler/java/java_message_field.cc \
        src/google/protobuf/compiler/java/java_primitive_field.cc \
        src/google/protobuf/compiler/java/java_service.cc \
        src/google/protobuf/compiler/javamicro/javamicro_enum.cc \
        src/google/protobuf/compiler/javamicro/javamicro_enum_field.cc \
        src/google/protobuf/compiler/javamicro/javamicro_field.cc \
        src/google/protobuf/compiler/javamicro/javamicro_file.cc \
        src/google/protobuf/compiler/javamicro/javamicro_generator.cc \
        src/google/protobuf/compiler/javamicro/javamicro_helpers.cc \
        src/google/protobuf/compiler/javamicro/javamicro_message.cc \
        src/google/protobuf/compiler/javamicro/javamicro_message_field.cc \
        src/google/protobuf/compiler/javamicro/javamicro_primitive_field.cc \
        src/google/protobuf/compiler/python/python_generator.cc \
        src/google/protobuf/io/coded_stream.cc \
        src/google/protobuf/io/gzip_stream.cc \
        src/google/protobuf/io/printer.cc \
        src/google/protobuf/io/tokenizer.cc \
        src/google/protobuf/io/zero_copy_stream.cc \
        src/google/protobuf/io/zero_copy_stream_impl.cc \
        src/google/protobuf/io/zero_copy_stream_impl_lite.cc \
        src/google/protobuf/stubs/common.cc \
        src/google/protobuf/stubs/hash.cc \
        src/google/protobuf/stubs/once.cc \
        src/google/protobuf/stubs/structurally_valid.cc \
        src/google/protobuf/stubs/strutil.cc \
        src/google/protobuf/stubs/stringprintf.cc \
        src/google/protobuf/stubs/substitute.cc

    # C++ full library
    # =======================================================
    #include $(CLEAR_VARS)

    LOCAL_MODULE := protobufs

    LOCAL_CPP_EXTENSION := .cc

    LOCAL_SRC_FILES := \
        $(CC_LITE_SRC_FILES)                                             \
        src/google/protobuf/stubs/strutil.cc                             \
        src/google/protobuf/stubs/stringprintf.cc						 \
        src/google/protobuf/stubs/substitute.cc                          \
        src/google/protobuf/stubs/structurally_valid.cc                  \
        src/google/protobuf/descriptor.cc                                \
        src/google/protobuf/descriptor.pb.cc                             \
        src/google/protobuf/descriptor_database.cc                       \
        src/google/protobuf/dynamic_message.cc                           \
        src/google/protobuf/extension_set_heavy.cc                       \
        src/google/protobuf/generated_message_reflection.cc              \
        src/google/protobuf/message.cc                                   \
        src/google/protobuf/reflection_ops.cc                            \
        src/google/protobuf/service.cc                                   \
        src/google/protobuf/text_format.cc                               \
        src/google/protobuf/unknown_field_set.cc                         \
        src/google/protobuf/wire_format.cc                               \
        src/google/protobuf/io/gzip_stream.cc                            \
        src/google/protobuf/io/printer.cc                                \
        src/google/protobuf/io/tokenizer.cc                              \
        src/google/protobuf/io/zero_copy_stream_impl.cc                  \
        src/google/protobuf/compiler/importer.cc                         \
        src/google/protobuf/compiler/parser.cc

    LOCAL_C_INCLUDES := \
        $(MY_BASE_JNI_PATH)/Protobufs/src \
        $(MY_BASE_JNI_PATH)/Protobufs/src/google \
        $(MY_BASE_JNI_PATH)/Protobufs/src/google/protobuf

    LOCAL_SHARED_LIBRARIES := \
        libz libcutils libutils
    LOCAL_LDLIBS := -lm -lz

    # stlport conflicts with the host stl library

    # Define the header files to be copied
    #LOCAL_COPY_HEADERS := \
    #    src/google/protobuf/stubs/once.h \
    #    src/google/protobuf/stubs/common.h \
    #    src/google/protobuf/io/coded_stream.h \
    #    src/google/protobuf/generated_message_util.h \
    #    src/google/protobuf/repeated_field.h \
    #    src/google/protobuf/extension_set.h \
    #    src/google/protobuf/wire_format_lite_inl.h
    #
    #LOCAL_COPY_HEADERS_TO := $(LOCAL_MODULE)

    include $(BUILD_STATIC_LIBRARY)