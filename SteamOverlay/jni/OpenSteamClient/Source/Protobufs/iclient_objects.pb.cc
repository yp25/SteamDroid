// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: iclient_objects.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "iclient_objects.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace Sc {

void protobuf_ShutdownFile_iclient_5fobjects_2eproto() {
  delete ClientAppInfo::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_iclient_5fobjects_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_iclient_5fobjects_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  ClientAppInfo::default_instance_ = new ClientAppInfo();
  ClientAppInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_iclient_5fobjects_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_iclient_5fobjects_2eproto_once_);
void protobuf_AddDesc_iclient_5fobjects_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_iclient_5fobjects_2eproto_once_,
                 &protobuf_AddDesc_iclient_5fobjects_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_iclient_5fobjects_2eproto {
  StaticDescriptorInitializer_iclient_5fobjects_2eproto() {
    protobuf_AddDesc_iclient_5fobjects_2eproto();
  }
} static_descriptor_initializer_iclient_5fobjects_2eproto_;
#endif

// ===================================================================

#ifndef _MSC_VER
const int ClientAppInfo::kAppidFieldNumber;
const int ClientAppInfo::kFavoriteFieldNumber;
const int ClientAppInfo::kInstalledFieldNumber;
const int ClientAppInfo::kAutoUpdateFieldNumber;
const int ClientAppInfo::kCategoryFieldNumber;
const int ClientAppInfo::kAppTypeFieldNumber;
const int ClientAppInfo::kDownloadingFieldNumber;
const int ClientAppInfo::kDownloadPausedFieldNumber;
const int ClientAppInfo::kBytesDownloadRateFieldNumber;
const int ClientAppInfo::kBytesDownloadedFieldNumber;
const int ClientAppInfo::kBytesNeededFieldNumber;
const int ClientAppInfo::kChangingFieldNumber;
const int ClientAppInfo::kAvailableOnPlatformFieldNumber;
#endif  // !_MSC_VER

ClientAppInfo::ClientAppInfo()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void ClientAppInfo::InitAsDefaultInstance() {
}

ClientAppInfo::ClientAppInfo(const ClientAppInfo& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void ClientAppInfo::SharedCtor() {
  _cached_size_ = 0;
  appid_ = 0u;
  favorite_ = false;
  installed_ = false;
  auto_update_ = false;
  category_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  app_type_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  downloading_ = false;
  download_paused_ = false;
  bytes_download_rate_ = 0u;
  bytes_downloaded_ = GOOGLE_ULONGLONG(0);
  bytes_needed_ = GOOGLE_ULONGLONG(0);
  changing_ = false;
  available_on_platform_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ClientAppInfo::~ClientAppInfo() {
  SharedDtor();
}

void ClientAppInfo::SharedDtor() {
  if (category_ != &::google::protobuf::internal::kEmptyString) {
    delete category_;
  }
  if (app_type_ != &::google::protobuf::internal::kEmptyString) {
    delete app_type_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void ClientAppInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ClientAppInfo& ClientAppInfo::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_iclient_5fobjects_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_iclient_5fobjects_2eproto();
#endif
  return *default_instance_;
}

ClientAppInfo* ClientAppInfo::default_instance_ = NULL;

ClientAppInfo* ClientAppInfo::New() const {
  return new ClientAppInfo;
}

void ClientAppInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    appid_ = 0u;
    favorite_ = false;
    installed_ = false;
    auto_update_ = false;
    if (has_category()) {
      if (category_ != &::google::protobuf::internal::kEmptyString) {
        category_->clear();
      }
    }
    if (has_app_type()) {
      if (app_type_ != &::google::protobuf::internal::kEmptyString) {
        app_type_->clear();
      }
    }
    downloading_ = false;
    download_paused_ = false;
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    bytes_download_rate_ = 0u;
    bytes_downloaded_ = GOOGLE_ULONGLONG(0);
    bytes_needed_ = GOOGLE_ULONGLONG(0);
    changing_ = false;
    available_on_platform_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool ClientAppInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 appid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &appid_)));
          set_has_appid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_favorite;
        break;
      }

      // optional bool favorite = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_favorite:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &favorite_)));
          set_has_favorite();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_installed;
        break;
      }

      // optional bool installed = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_installed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &installed_)));
          set_has_installed();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_auto_update;
        break;
      }

      // optional bool auto_update = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_auto_update:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &auto_update_)));
          set_has_auto_update();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_category;
        break;
      }

      // optional string category = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_category:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_category()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_app_type;
        break;
      }

      // optional string app_type = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_app_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_app_type()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_downloading;
        break;
      }

      // optional bool downloading = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_downloading:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &downloading_)));
          set_has_downloading();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_download_paused;
        break;
      }

      // optional bool download_paused = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_download_paused:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &download_paused_)));
          set_has_download_paused();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_bytes_download_rate;
        break;
      }

      // optional uint32 bytes_download_rate = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_bytes_download_rate:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &bytes_download_rate_)));
          set_has_bytes_download_rate();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(80)) goto parse_bytes_downloaded;
        break;
      }

      // optional uint64 bytes_downloaded = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_bytes_downloaded:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &bytes_downloaded_)));
          set_has_bytes_downloaded();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(88)) goto parse_bytes_needed;
        break;
      }

      // optional uint64 bytes_needed = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_bytes_needed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &bytes_needed_)));
          set_has_bytes_needed();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(96)) goto parse_changing;
        break;
      }

      // optional bool changing = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_changing:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &changing_)));
          set_has_changing();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(104)) goto parse_available_on_platform;
        break;
      }

      // optional bool available_on_platform = 13;
      case 13: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_available_on_platform:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &available_on_platform_)));
          set_has_available_on_platform();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ClientAppInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional uint32 appid = 1;
  if (has_appid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->appid(), output);
  }

  // optional bool favorite = 2;
  if (has_favorite()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->favorite(), output);
  }

  // optional bool installed = 3;
  if (has_installed()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->installed(), output);
  }

  // optional bool auto_update = 4;
  if (has_auto_update()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->auto_update(), output);
  }

  // optional string category = 5;
  if (has_category()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->category(), output);
  }

  // optional string app_type = 6;
  if (has_app_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      6, this->app_type(), output);
  }

  // optional bool downloading = 7;
  if (has_downloading()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->downloading(), output);
  }

  // optional bool download_paused = 8;
  if (has_download_paused()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->download_paused(), output);
  }

  // optional uint32 bytes_download_rate = 9;
  if (has_bytes_download_rate()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(9, this->bytes_download_rate(), output);
  }

  // optional uint64 bytes_downloaded = 10;
  if (has_bytes_downloaded()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(10, this->bytes_downloaded(), output);
  }

  // optional uint64 bytes_needed = 11;
  if (has_bytes_needed()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(11, this->bytes_needed(), output);
  }

  // optional bool changing = 12;
  if (has_changing()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(12, this->changing(), output);
  }

  // optional bool available_on_platform = 13;
  if (has_available_on_platform()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(13, this->available_on_platform(), output);
  }

}

int ClientAppInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 appid = 1;
    if (has_appid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->appid());
    }

    // optional bool favorite = 2;
    if (has_favorite()) {
      total_size += 1 + 1;
    }

    // optional bool installed = 3;
    if (has_installed()) {
      total_size += 1 + 1;
    }

    // optional bool auto_update = 4;
    if (has_auto_update()) {
      total_size += 1 + 1;
    }

    // optional string category = 5;
    if (has_category()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->category());
    }

    // optional string app_type = 6;
    if (has_app_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->app_type());
    }

    // optional bool downloading = 7;
    if (has_downloading()) {
      total_size += 1 + 1;
    }

    // optional bool download_paused = 8;
    if (has_download_paused()) {
      total_size += 1 + 1;
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional uint32 bytes_download_rate = 9;
    if (has_bytes_download_rate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->bytes_download_rate());
    }

    // optional uint64 bytes_downloaded = 10;
    if (has_bytes_downloaded()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->bytes_downloaded());
    }

    // optional uint64 bytes_needed = 11;
    if (has_bytes_needed()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->bytes_needed());
    }

    // optional bool changing = 12;
    if (has_changing()) {
      total_size += 1 + 1;
    }

    // optional bool available_on_platform = 13;
    if (has_available_on_platform()) {
      total_size += 1 + 1;
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ClientAppInfo::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const ClientAppInfo*>(&from));
}

void ClientAppInfo::MergeFrom(const ClientAppInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_appid()) {
      set_appid(from.appid());
    }
    if (from.has_favorite()) {
      set_favorite(from.favorite());
    }
    if (from.has_installed()) {
      set_installed(from.installed());
    }
    if (from.has_auto_update()) {
      set_auto_update(from.auto_update());
    }
    if (from.has_category()) {
      set_category(from.category());
    }
    if (from.has_app_type()) {
      set_app_type(from.app_type());
    }
    if (from.has_downloading()) {
      set_downloading(from.downloading());
    }
    if (from.has_download_paused()) {
      set_download_paused(from.download_paused());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_bytes_download_rate()) {
      set_bytes_download_rate(from.bytes_download_rate());
    }
    if (from.has_bytes_downloaded()) {
      set_bytes_downloaded(from.bytes_downloaded());
    }
    if (from.has_bytes_needed()) {
      set_bytes_needed(from.bytes_needed());
    }
    if (from.has_changing()) {
      set_changing(from.changing());
    }
    if (from.has_available_on_platform()) {
      set_available_on_platform(from.available_on_platform());
    }
  }
}

void ClientAppInfo::CopyFrom(const ClientAppInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClientAppInfo::IsInitialized() const {

  return true;
}

void ClientAppInfo::Swap(ClientAppInfo* other) {
  if (other != this) {
    std::swap(appid_, other->appid_);
    std::swap(favorite_, other->favorite_);
    std::swap(installed_, other->installed_);
    std::swap(auto_update_, other->auto_update_);
    std::swap(category_, other->category_);
    std::swap(app_type_, other->app_type_);
    std::swap(downloading_, other->downloading_);
    std::swap(download_paused_, other->download_paused_);
    std::swap(bytes_download_rate_, other->bytes_download_rate_);
    std::swap(bytes_downloaded_, other->bytes_downloaded_);
    std::swap(bytes_needed_, other->bytes_needed_);
    std::swap(changing_, other->changing_);
    std::swap(available_on_platform_, other->available_on_platform_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string ClientAppInfo::GetTypeName() const {
  return "Sc.ClientAppInfo";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Sc

// @@protoc_insertion_point(global_scope)
