//
// Created by 张涛 on 2020-08-18.
//

#pragma once

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int BOOL;
typedef unsigned int uid_t;
typedef void *view_t;

#define TRUE 1
#define FALSE 0

enum API_TYPE {
  INITIALIZE = 0,
  RELEASE = 1,
  SET_CHANNEL_PROFILE = 2,
  SET_CLIENT_ROLE = 3,
  JOIN_CHANNEL = 4,
  SWITCH_CHANNEL = 5,
  LEAVE_CHANNEL = 6,
  RE_NEW_TOKEN = 7,
  REGISTER_LOCAL_USER_ACCOUNT = 8,
  JOIN_CHANNEL_WITH_USER_ACCOUNT = 9,
  GET_USER_INFO_BY_USER_ACCOUNT = 10,
  GET_USER_INFO_BY_UID = 11,
  START_ECHO_TEST = 12,
  START_ECHO_TEST_2 = 13,
  STOP_ECHO_TEST = 14,
  ENABLE_VIDEO = 15,
  DISABLE_VIDEO = 16,
  SET_VIDEO_PROFILE = 17,
  SET_VIDEO_ENCODER_CONFIGURATION = 18,
  SET_CAMERA_CAPTURER_CONFIGURATION = 19,
  SET_UP_LOCAL_VIDEO = 20,
  SET_UP_REMOTE_VIDEO = 21,
  START_PREVIEW = 22,
  SET_REMOTE_USER_PRIORITY = 23,
  STOP_PREVIEW = 24,
  ENABLE_AUDIO = 25,
  ENABLE_LOCAL_AUDIO = 26,
  DISABLE_AUDIO = 27,
  SET_AUDIO_PROFILE = 28,
  MUTE_LOCAL_AUDIO_STREAM = 29,
  MUTE_ALL_REMOTE_AUDIO_STREAMS = 30,
  SET_DEFAULT_MUTE_ALL_REMOTE_AUDIO_STREAMS = 31,
  ADJUST_USER_PLAYBACK_SIGNAL_VOLUME = 32,
  MUTE_REMOTE_AUDIO_STREAM = 33,
  MUTE_LOCAL_VIDEO_STREAM = 34,
  ENABLE_LOCAL_VIDEO = 35,
  MUTE_ALL_REMOTE_VIDEO_STREAMS = 36,
  SET_DEFAULT_MUTE_ALL_REMOTE_VIDEO_STREAMS = 37,
  MUTE_REMOTE_VIDEO_STREAM = 38,
  SET_REMOTE_VIDEO_STREAM_TYPE = 39,
  SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE = 40,
  ENABLE_AUDIO_VOLUME_INDICATION = 41,
  START_AUDIO_RECORDING = 42,
  START_AUDIO_RECORDING2 = 43,
  STOP_AUDIO_RECORDING = 44,
  ENABLE_FACE_DETECTION = 62,
  SET_REMOTE_VOICE_POSITIONN = 73,
  SET_LOG_FILE = 79,
  SET_LOG_FILTER = 80,
  SET_LOG_FILE_SIZE = 81,
  SET_LOCAL_RENDER_MODE = 82,
  SET_LOCAL_RENDER_MODE_2 = 83,
  SET_REMOTE_RENDER_MODE = 84,
  SET_REMOTE_RENDER_MODE_2 = 85,
  SET_LOCAL_VIDEO_MIRROR_MODE = 86,
  ENABLE_DUAL_STREAM_MODE = 87,
  ADJUST_RECORDING_SIGNAL_VOLUME = 93,
  ADJUST_PLAYBACK_SIGNAL_VOLUME = 94,
  ENABLE_WEB_SDK_INTEROPER_ABILITY = 95,
  SET_VIDEO_QUALITY_PARAMETERS = 96,
  SET_LOCAL_PUBLISH_FALLBACK_OPTION = 97,
  SET_REMOTE_SUBSCRIBE_FALLBACK_OPTION = 98,
  SWITCH_CAMERA = 99,
  SWITCH_CAMERA_2 = 100,
  SET_DEFAULT_AUDIO_ROUTE_SPEAKER_PHONE = 101,
  SET_ENABLE_SPEAKER_PHONE = 102,
  ENABLE_IN_EAR_MONITORING = 103,
  SET_IN_EAR_MONITORING_VOLUME = 104,
  IS_SPEAKER_PHONE_ENABLED = 105,
  SET_AUDIO_SESSION_OPERATION_RESTRICTION = 106,
  ENABLE_LOOP_BACK_RECORDING = 107,
  START_SCREEN_CAPTURE_BY_DISPLAY_ID = 108,
  START_SCREEN_CAPTURE_BY_SCREEN_RECT = 109,
  START_SCREEN_CAPTURE_BY_WINDOW_ID = 110,
  SET_SCREEN_CAPTURE_CONTENT_HINT = 111,
  UPDATE_SCREEN_CAPTURE_PARAMETERS = 112,
  UPDATE_SCREEN_CAPTURE_REGION = 113,
  STOP_SCREEN_CAPTURE = 114,
  GET_CALL_ID = 117,
  RATE = 118,
  COMPLAIN = 119,
  GET_VERSION = 120,
  ENABLE_LAST_MILE_TEST = 121,
  DISABLE_LAST_MILE_TEST = 122,
  START_LAST_MILE_PROBE_TEST = 123,
  STOP_LAST_MILE_PROBE_TEST = 124,
  GET_ERROR_DESCRIPTION = 125,
  SET_ENCRYPTION_SECTRT = 126,
  SET_ENCRYPTION_MODE = 127,
  REGISTER_PACKET_OBSERVER = 128,
  CREATE_DATA_STREAM = 129,
  SEND_STREAM_MESSAGE = 130,
  ADD_PUBLISH_STREAM_URL = 131,
  REMOVE_PUBLISH_STREAM_URL = 132,
  SET_LIVE_TRANSCODING = 133,
  ADD_VIDEO_WATER_MARK = 134,
  ADD_VIDEO_WATER_MARK_2 = 135,
  CLEAR_VIDEO_WATER_MARKS = 136,
  SET_BEAUTY_EFFECT_OPTIONS = 137,
  ADD_INJECT_STREAM_URL = 138,
  START_CHANNEL_MEDIA_RELAY = 139,
  UPDATE_CHANNEL_MEDIA_RELAY = 140,
  STOP_CHANNEL_MEDIA_RELAY = 141,
  REMOVE_INJECT_STREAM_URL = 142,
  GET_CONNECTION_STATE = 143,
  REGISTER_MEDIA_META_DATA_OBSERVER = 144,
  SET_PARAMETERS = 145,
  SET_PLAYBACK_DEVICE_VOLUME = 146,
  PUBLISH = 147,
  UNPUBLISH = 148,
  CHANNEL_ID = 149,
  SEND_METADATA = 150,
  SET_MAX_META_SIZE = 151,
  PUSH_AUDIO_FRAME = 152,
  PUSH_AUDIO_FRAME_2 = 153,
  PULL_AUDIO_FRAME = 154,
  SET_EXTERN_VIDEO_SOURCE = 155,
  PUSH_VIDEO_FRAME = 156
};

enum API_TYPE_AUDIO_EFFECT {
  START_AUDIO_MIXING = 45,
  STOP_AUDIO_MIXING = 46,
  PAUSE_AUDIO_MIXING = 47,
  RESUME_AUDIO_MIXING = 48,
  SET_HIGH_QUALITY_AUDIO_PARAMETERS = 49,
  ADJUST_AUDIO_MIXING_VOLUME = 50,
  ADJUST_AUDIO_MIXING_PLAYOUT_VOLUME = 51,
  GET_AUDIO_MIXING_PLAYOUT_VOLUME = 52,
  ADJUST_AUDIO_MIXING_PUBLISH_VOLUME = 53,
  GET_AUDIO_MIXING_PUBLISH_VOLUME = 54,
  GET_AUDIO_MIXING_DURATION = 55,
  GET_AUDIO_MIXING_CURRENT_POSITION = 56,
  SET_AUDIO_MIXING_POSITION = 57,
  SET_AUDIO_MIXING_PITCH = 58,
  GET_EFFECTS_VOLUME = 59,
  SET_EFFECTS_VOLUME = 60,
  SET_VOLUME_OF_EFFECT = 61,
  PLAY_EFFECT = 63,
  STOP_EFFECT = 64,
  STOP_ALL_EFFECTS = 65,
  PRE_LOAD_EFFECT = 66,
  UN_LOAD_EFFECT = 67,
  PAUSE_EFFECT = 68,
  PAUSE_ALL_EFFECTS = 69,
  RESUME_EFFECT = 70,
  RESUME_ALL_EFFECTS = 71,
  ENABLE_SOUND_POSITION_INDICATION = 72,
  SET_LOCAL_VOICE_PITCH = 74,
  SET_LOCAL_VOICE_EQUALIZATION = 75,
  SET_LOCAL_VOICE_REVERB = 76,
  SET_LOCAL_VOICE_CHANGER = 77,
  SET_LOCAL_VOICE_REVERB_PRESET = 78,
  SET_EXTERNAL_AUDIO_SOURCE = 88,
  SET_EXTERNAL_AUDIO_SINK = 89,
  SET_RECORDING_AUDIO_FRAME_PARAMETERS = 90,
  SET_PLAYBACK_AUDIO_FRAME_PARAMETERS = 91,
  SET_MIXED_AUDIO_FRAME_PARAMETERS = 92,
};

enum API_TYPE_DEVICE_MANAGER {
  GET_COUNT = 151,
  GET_DEVICE = 152,
  GET_CURRENT_DEVICE = 153,
  GET_CURRENT_DEVICE_INFO = 154,
  SET_DEVICE = 155,
  SET_DEVICE_VOLUME = 156,
  GET_DEVICE_VOLUME = 157,
  SET_DEVICE_MUTE = 158,
  GET_DEVICE_MUTE = 159,
  START_DEVICE_TEST = 160,
  STOP_DEVICE_TEST = 161,
  START_AUDIO_DEVICE_LOOP_BACK_TEST = 162,
  STOP_AUDIO_DEVICE_LOOP_BACK_TEST = 163
};

enum ERROR_CODE {
  ERROR_OK = 0,
  ERROR_INVALID_API_TYPE = -100,
  ERROR_INVALID_PARAM = -101,
  ERROR_PARSE_PARAMETER = -102,
  ERROR_NO_CURRENT_PARAMETER = -103,
  ERROR_NOT_SUPPORT_API = -4,
  ERROR_NOT_INITIALIZE_OBSERVER = -104,
  ERROR_NO_DEVICE = -105,
  ERROR_ENGINE_EXIST = -106,
  ERROR_NO_ENGINE = -107,
  ERROR_INVALID_DEVICE_TYPE = -108,
};

enum DEVICE_TYPE {
  PLAYBACK_DEVICE = 0,
  RECORDING_DEVICE = 1,
};

/** Maximum length of the device ID.
 */
enum MAX_DEVICE_ID_LENGTH_TYPE {
  /** The maximum length of the device ID is 512 bytes.
   */
  MAX_DEVICE_ID_LENGTH = 512
};
/** Maximum length of user account.
 */
enum MAX_USER_ACCOUNT_LENGTH_TYPE {
  /** The maximum length of user account is 255 bytes.
   */
  MAX_USER_ACCOUNT_LENGTH = 256
};
/** Maximum length of channel ID.
 */
enum MAX_CHANNEL_ID_LENGTH_TYPE {
  /** The maximum length of channel id is 64 bytes.
   */
  MAX_CHANNEL_ID_LENGTH = 65
};
/** Formats of the quality report.
 */
enum QUALITY_REPORT_FORMAT_TYPE {
  /** 0: The quality report in JSON format,
   */
  QUALITY_REPORT_JSON = 0,
  /** 1: The quality report in HTML format.
   */
  QUALITY_REPORT_HTML = 1,
};

enum MEDIA_ENGINE_EVENT_CODE_TYPE {
  /** 0: For internal use only.
   */
  MEDIA_ENGINE_RECORDING_ERROR = 0,
  /** 1: For internal use only.
   */
  MEDIA_ENGINE_PLAYOUT_ERROR = 1,
  /** 2: For internal use only.
   */
  MEDIA_ENGINE_RECORDING_WARNING = 2,
  /** 3: For internal use only.
   */
  MEDIA_ENGINE_PLAYOUT_WARNING = 3,
  /** 10: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_FILE_MIX_FINISH = 10,
  /** 12: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_FAREND_MUSIC_BEGINS = 12,
  /** 13: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_FAREND_MUSIC_ENDS = 13,
  /** 14: For internal use only.
   */
  MEDIA_ENGINE_LOCAL_AUDIO_RECORD_ENABLED = 14,
  /** 15: For internal use only.
   */
  MEDIA_ENGINE_LOCAL_AUDIO_RECORD_DISABLED = 15,
  // media engine role changed
  /** 20: For internal use only.
   */
  MEDIA_ENGINE_ROLE_BROADCASTER_SOLO = 20,
  /** 21: For internal use only.
   */
  MEDIA_ENGINE_ROLE_BROADCASTER_INTERACTIVE = 21,
  /** 22: For internal use only.
   */
  MEDIA_ENGINE_ROLE_AUDIENCE = 22,
  /** 23: For internal use only.
   */
  MEDIA_ENGINE_ROLE_COMM_PEER = 23,
  /** 24: For internal use only.
   */
  MEDIA_ENGINE_ROLE_GAME_PEER = 24,
  // iOS adm sample rate changed
  /** 110: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_ADM_REQUIRE_RESTART = 110,
  /** 111: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_ADM_SPECIAL_RESTART = 111,
  /** 112: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_ADM_USING_COMM_PARAMS = 112,
  /** 113: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_ADM_USING_NORM_PARAMS = 113,
  // audio mix state
  /** 710: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_EVENT_MIXING_PLAY = 710,
  /** 711: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_EVENT_MIXING_PAUSED = 711,
  /** 712: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_EVENT_MIXING_RESTART = 712,
  /** 713: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_EVENT_MIXING_STOPPED = 713,
  /** 714: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_EVENT_MIXING_ERROR = 714,
  // Mixing error codes
  /** 701: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_ERROR_MIXING_OPEN = 701,
  /** 702: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_ERROR_MIXING_TOO_FREQUENT = 702,
  /** 703: The audio mixing file playback is interrupted. For internal use only.
   */
  MEDIA_ENGINE_AUDIO_ERROR_MIXING_INTERRUPTED_EOF = 703,
  /** 0: For internal use only.
   */
  MEDIA_ENGINE_AUDIO_ERROR_MIXING_NO_ERROR = 0,
};

/** The states of the local user's audio mixing file.
 */
enum AUDIO_MIXING_STATE_TYPE {
  /** 710: The audio mixing file is playing.
   */
  AUDIO_MIXING_STATE_PLAYING = 710,
  /** 711: The audio mixing file pauses playing.
   */
  AUDIO_MIXING_STATE_PAUSED = 711,
  /** 713: The audio mixing file stops playing.
   */
  AUDIO_MIXING_STATE_STOPPED = 713,
  /** 714: An exception occurs when playing the audio mixing file. See
   * #AUDIO_MIXING_ERROR_TYPE.
   */
  AUDIO_MIXING_STATE_FAILED = 714,
};

/** The error codes of the local user's audio mixing file.
 */
enum AUDIO_MIXING_ERROR_TYPE {
  /** 701: The SDK cannot open the audio mixing file.
   */
  AUDIO_MIXING_ERROR_CAN_NOT_OPEN = 701,
  /** 702: The SDK opens the audio mixing file too frequently.
   */
  AUDIO_MIXING_ERROR_TOO_FREQUENT_CALL = 702,
  /** 703: The audio mixing file playback is interrupted.
   */
  AUDIO_MIXING_ERROR_INTERRUPTED_EOF = 703,
  /** 0: The SDK can open the audio mixing file.
   */
  AUDIO_MIXING_ERROR_OK = 0,
};

/** Media device states.
 */
enum MEDIA_DEVICE_STATE_TYPE {
  /** 1: The device is active.
   */
  MEDIA_DEVICE_STATE_ACTIVE = 1,
  /** 2: The device is disabled.
   */
  MEDIA_DEVICE_STATE_DISABLED = 2,
  /** 4: The device is not present.
   */
  MEDIA_DEVICE_STATE_NOT_PRESENT = 4,
  /** 8: The device is unplugged.
   */
  MEDIA_DEVICE_STATE_UNPLUGGED = 8
};

/** Media device types.
 */
enum MEDIA_DEVICE_TYPE {
  /** -1: Unknown device type.
   */
  UNKNOWN_AUDIO_DEVICE = -1,
  /** 0: Audio playback device.
   */
  AUDIO_PLAYOUT_DEVICE = 0,
  /** 1: Audio recording device.
   */
  AUDIO_RECORDING_DEVICE = 1,
  /** 2: Video renderer.
   */
  VIDEO_RENDER_DEVICE = 2,
  /** 3: Video capturer.
   */
  VIDEO_CAPTURE_DEVICE = 3,
  /** 4: Application audio playback device.
   */
  AUDIO_APPLICATION_PLAYOUT_DEVICE = 4,
};

/** Local video state types
 */
enum LOCAL_VIDEO_STREAM_STATE {
  /** 0: Initial state */
  LOCAL_VIDEO_STREAM_STATE_STOPPED = 0,
  /** 1: The local video capturing device starts successfully.
   *
   * The SDK also reports this state when you share a maximized window by
   * calling \ref IRtcEngine::startScreenCaptureByWindowId
   * "startScreenCaptureByWindowId".
   */
  LOCAL_VIDEO_STREAM_STATE_CAPTURING = 1,
  /** 2: The first video frame is successfully encoded. */
  LOCAL_VIDEO_STREAM_STATE_ENCODING = 2,
  /** 3: The local video fails to start. */
  LOCAL_VIDEO_STREAM_STATE_FAILED = 3
};

/** Local video state error codes
 */
enum LOCAL_VIDEO_STREAM_ERROR {
  /** 0: The local video is normal. */
  LOCAL_VIDEO_STREAM_ERROR_OK = 0,
  /** 1: No specified reason for the local video failure. */
  LOCAL_VIDEO_STREAM_ERROR_FAILURE = 1,
  /** 2: No permission to use the local video capturing device. */
  LOCAL_VIDEO_STREAM_ERROR_DEVICE_NO_PERMISSION = 2,
  /** 3: The local video capturing device is in use. */
  LOCAL_VIDEO_STREAM_ERROR_DEVICE_BUSY = 3,
  /** 4: The local video capture fails. Check whether the capturing device is
     working properly. */
  LOCAL_VIDEO_STREAM_ERROR_CAPTURE_FAILURE = 4,
  /** 5: The local video encoding fails. */
  LOCAL_VIDEO_STREAM_ERROR_ENCODE_FAILURE = 5,
  /** 11: The shared window is minimized when you call \ref
   * IRtcEngine::startScreenCaptureByWindowId "startScreenCaptureByWindowId" to
   * share a window.
   */
  LOCAL_VIDEO_STREAM_ERROR_SCREEN_CAPTURE_WINDOW_MINIMIZED = 11,
};

/** Local audio state types.
 */
enum LOCAL_AUDIO_STREAM_STATE {
  /** 0: The local audio is in the initial state.
   */
  LOCAL_AUDIO_STREAM_STATE_STOPPED = 0,
  /** 1: The recording device starts successfully.
   */
  LOCAL_AUDIO_STREAM_STATE_RECORDING = 1,
  /** 2: The first audio frame encodes successfully.
   */
  LOCAL_AUDIO_STREAM_STATE_ENCODING = 2,
  /** 3: The local audio fails to start.
   */
  LOCAL_AUDIO_STREAM_STATE_FAILED = 3
};

/** Local audio state error codes.
 */
enum LOCAL_AUDIO_STREAM_ERROR {
  /** 0: The local audio is normal.
   */
  LOCAL_AUDIO_STREAM_ERROR_OK = 0,
  /** 1: No specified reason for the local audio failure.
   */
  LOCAL_AUDIO_STREAM_ERROR_FAILURE = 1,
  /** 2: No permission to use the local audio device.
   */
  LOCAL_AUDIO_STREAM_ERROR_DEVICE_NO_PERMISSION = 2,
  /** 3: The microphone is in use.
   */
  LOCAL_AUDIO_STREAM_ERROR_DEVICE_BUSY = 3,
  /** 4: The local audio recording fails. Check whether the recording device
   * is working properly.
   */
  LOCAL_AUDIO_STREAM_ERROR_RECORD_FAILURE = 4,
  /** 5: The local audio encoding fails.
   */
  LOCAL_AUDIO_STREAM_ERROR_ENCODE_FAILURE = 5
};

/** Audio recording qualities.
 */
enum AUDIO_RECORDING_QUALITY_TYPE {
  /** 0: Low quality. The sample rate is 32 kHz, and the file size is around
   * 1.2 MB after 10 minutes of recording.
   */
  AUDIO_RECORDING_QUALITY_LOW = 0,
  /** 1: Medium quality. The sample rate is 32 kHz, and the file size is
   * around 2 MB after 10 minutes of recording.
   */
  AUDIO_RECORDING_QUALITY_MEDIUM = 1,
  /** 2: High quality. The sample rate is 32 kHz, and the file size is
   * around 3.75 MB after 10 minutes of recording.
   */
  AUDIO_RECORDING_QUALITY_HIGH = 2,
};

/** Network quality types. */
enum QUALITY_TYPE {
  /** 0: The network quality is unknown. */
  QUALITY_UNKNOWN = 0,
  /**  1: The network quality is excellent. */
  QUALITY_EXCELLENT = 1,
  /** 2: The network quality is quite good, but the bitrate may be slightly
     lower than excellent. */
  QUALITY_GOOD = 2,
  /** 3: Users can feel the communication slightly impaired. */
  QUALITY_POOR = 3,
  /** 4: Users cannot communicate smoothly. */
  QUALITY_BAD = 4,
  /** 5: The network is so bad that users can barely communicate. */
  QUALITY_VBAD = 5,
  /** 6: The network is down and users cannot communicate at all. */
  QUALITY_DOWN = 6,
  /** 7: Users cannot detect the network quality. (Not in use.) */
  QUALITY_UNSUPPORTED = 7,
  /** 8: Detecting the network quality. */
  QUALITY_DETECTING = 8,
};

/** Video display modes. */
enum RENDER_MODE_TYPE {
  /**
1: Uniformly scale the video until it fills the visible boundaries (cropped).
One dimension of the video may have clipped contents.
 */
  RENDER_MODE_HIDDEN = 1,
  /**
2: Uniformly scale the video until one of its dimension fits the boundary
(zoomed to fit). Areas that are not filled due to disparity in the aspect ratio
are filled with black.
*/
  RENDER_MODE_FIT = 2,
  /** **DEPRECATED** 3: This mode is deprecated.
   */
  RENDER_MODE_ADAPTIVE = 3,
  /**
  4: The fill mode. In this mode, the SDK stretches or zooms the video to fill
  the display window.
  */
  RENDER_MODE_FILL = 4,
};

/** Video mirror modes. */
enum VIDEO_MIRROR_MODE_TYPE {
  /** 0: (Default) The SDK enables the mirror mode.
   */
  VIDEO_MIRROR_MODE_AUTO = 0, // determined by SDK
  /** 1: Enable mirror mode. */
  VIDEO_MIRROR_MODE_ENABLED = 1, // enabled mirror
  /** 2: Disable mirror mode. */
  VIDEO_MIRROR_MODE_DISABLED = 2, // disable mirror
};

/** **DEPRECATED** Video profiles. */
enum VIDEO_PROFILE_TYPE {
  /** 0: 160 * 120, frame rate 15 fps, bitrate 65 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_120P = 0,
  /** 2: 120 * 120, frame rate 15 fps, bitrate 50 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_120P_3 = 2,
  /** 10: 320*180, frame rate 15 fps, bitrate 140 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_180P = 10,
  /** 12: 180 * 180, frame rate 15 fps, bitrate 100 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_180P_3 = 12,
  /** 13: 240 * 180, frame rate 15 fps, bitrate 120 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_180P_4 = 13,
  /** 20: 320 * 240, frame rate 15 fps, bitrate 200 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_240P = 20,
  /** 22: 240 * 240, frame rate 15 fps, bitrate 140 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_240P_3 = 22,
  /** 23: 424 * 240, frame rate 15 fps, bitrate 220 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_240P_4 = 23,
  /** 30: 640 * 360, frame rate 15 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_360P = 30,
  /** 32: 360 * 360, frame rate 15 fps, bitrate 260 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_360P_3 = 32,
  /** 33: 640 * 360, frame rate 30 fps, bitrate 600 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_360P_4 = 33,
  /** 35: 360 * 360, frame rate 30 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_360P_6 = 35,
  /** 36: 480 * 360, frame rate 15 fps, bitrate 320 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_360P_7 = 36,
  /** 37: 480 * 360, frame rate 30 fps, bitrate 490 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_360P_8 = 37,
  /** 38: 640 * 360, frame rate 15 fps, bitrate 800 Kbps.
   @note `LIVE_BROADCASTING` profile only.
   */
  VIDEO_PROFILE_LANDSCAPE_360P_9 = 38,
  /** 39: 640 * 360, frame rate 24 fps, bitrate 800 Kbps.
   @note `LIVE_BROADCASTING` profile only.
   */
  VIDEO_PROFILE_LANDSCAPE_360P_10 = 39,
  /** 100: 640 * 360, frame rate 24 fps, bitrate 1000 Kbps.
   @note `LIVE_BROADCASTING` profile only.
   */
  VIDEO_PROFILE_LANDSCAPE_360P_11 = 100,
  /** 40: 640 * 480, frame rate 15 fps, bitrate 500 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_480P = 40,
  /** 42: 480 * 480, frame rate 15 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_480P_3 = 42,
  /** 43: 640 * 480, frame rate 30 fps, bitrate 750 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_480P_4 = 43,
  /** 45: 480 * 480, frame rate 30 fps, bitrate 600 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_480P_6 = 45,
  /** 47: 848 * 480, frame rate 15 fps, bitrate 610 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_480P_8 = 47,
  /** 48: 848 * 480, frame rate 30 fps, bitrate 930 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_480P_9 = 48,
  /** 49: 640 * 480, frame rate 10 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_480P_10 = 49,
  /** 50: 1280 * 720, frame rate 15 fps, bitrate 1130 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_720P = 50,
  /** 52: 1280 * 720, frame rate 30 fps, bitrate 1710 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_720P_3 = 52,
  /** 54: 960 * 720, frame rate 15 fps, bitrate 910 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_720P_5 = 54,
  /** 55: 960 * 720, frame rate 30 fps, bitrate 1380 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_720P_6 = 55,
  /** 60: 1920 * 1080, frame rate 15 fps, bitrate 2080 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_1080P = 60,
  /** 62: 1920 * 1080, frame rate 30 fps, bitrate 3150 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_1080P_3 = 62,
  /** 64: 1920 * 1080, frame rate 60 fps, bitrate 4780 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_1080P_5 = 64,
  /** 66: 2560 * 1440, frame rate 30 fps, bitrate 4850 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_1440P = 66,
  /** 67: 2560 * 1440, frame rate 60 fps, bitrate 6500 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_1440P_2 = 67,
  /** 70: 3840 * 2160, frame rate 30 fps, bitrate 6500 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_4K = 70,
  /** 72: 3840 * 2160, frame rate 60 fps, bitrate 6500 Kbps. */
  VIDEO_PROFILE_LANDSCAPE_4K_3 = 72,
  /** 1000: 120 * 160, frame rate 15 fps, bitrate 65 Kbps. */
  VIDEO_PROFILE_PORTRAIT_120P = 1000,
  /** 1002: 120 * 120, frame rate 15 fps, bitrate 50 Kbps. */
  VIDEO_PROFILE_PORTRAIT_120P_3 = 1002,
  /** 1010: 180 * 320, frame rate 15 fps, bitrate 140 Kbps. */
  VIDEO_PROFILE_PORTRAIT_180P = 1010,
  /** 1012: 180 * 180, frame rate 15 fps, bitrate 100 Kbps. */
  VIDEO_PROFILE_PORTRAIT_180P_3 = 1012,
  /** 1013: 180 * 240, frame rate 15 fps, bitrate 120 Kbps. */
  VIDEO_PROFILE_PORTRAIT_180P_4 = 1013,
  /** 1020: 240 * 320, frame rate 15 fps, bitrate 200 Kbps. */
  VIDEO_PROFILE_PORTRAIT_240P = 1020,
  /** 1022: 240 * 240, frame rate 15 fps, bitrate 140 Kbps. */
  VIDEO_PROFILE_PORTRAIT_240P_3 = 1022,
  /** 1023: 240 * 424, frame rate 15 fps, bitrate 220 Kbps. */
  VIDEO_PROFILE_PORTRAIT_240P_4 = 1023,
  /** 1030: 360 * 640, frame rate 15 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_PORTRAIT_360P = 1030,
  /** 1032: 360 * 360, frame rate 15 fps, bitrate 260 Kbps. */
  VIDEO_PROFILE_PORTRAIT_360P_3 = 1032,
  /** 1033: 360 * 640, frame rate 30 fps, bitrate 600 Kbps. */
  VIDEO_PROFILE_PORTRAIT_360P_4 = 1033,
  /** 1035: 360 * 360, frame rate 30 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_PORTRAIT_360P_6 = 1035,
  /** 1036: 360 * 480, frame rate 15 fps, bitrate 320 Kbps. */
  VIDEO_PROFILE_PORTRAIT_360P_7 = 1036,
  /** 1037: 360 * 480, frame rate 30 fps, bitrate 490 Kbps. */
  VIDEO_PROFILE_PORTRAIT_360P_8 = 1037,
  /** 1038: 360 * 640, frame rate 15 fps, bitrate 800 Kbps.
   @note `LIVE_BROADCASTING` profile only.
   */
  VIDEO_PROFILE_PORTRAIT_360P_9 = 1038,
  /** 1039: 360 * 640, frame rate 24 fps, bitrate 800 Kbps.
   @note `LIVE_BROADCASTING` profile only.
   */
  VIDEO_PROFILE_PORTRAIT_360P_10 = 1039,
  /** 1100: 360 * 640, frame rate 24 fps, bitrate 1000 Kbps.
   @note `LIVE_BROADCASTING` profile only.
   */
  VIDEO_PROFILE_PORTRAIT_360P_11 = 1100,
  /** 1040: 480 * 640, frame rate 15 fps, bitrate 500 Kbps. */
  VIDEO_PROFILE_PORTRAIT_480P = 1040,
  /** 1042: 480 * 480, frame rate 15 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_PORTRAIT_480P_3 = 1042,
  /** 1043: 480 * 640, frame rate 30 fps, bitrate 750 Kbps. */
  VIDEO_PROFILE_PORTRAIT_480P_4 = 1043,
  /** 1045: 480 * 480, frame rate 30 fps, bitrate 600 Kbps. */
  VIDEO_PROFILE_PORTRAIT_480P_6 = 1045,
  /** 1047: 480 * 848, frame rate 15 fps, bitrate 610 Kbps. */
  VIDEO_PROFILE_PORTRAIT_480P_8 = 1047,
  /** 1048: 480 * 848, frame rate 30 fps, bitrate 930 Kbps. */
  VIDEO_PROFILE_PORTRAIT_480P_9 = 1048,
  /** 1049: 480 * 640, frame rate 10 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_PORTRAIT_480P_10 = 1049,
  /** 1050: 720 * 1280, frame rate 15 fps, bitrate 1130 Kbps. */
  VIDEO_PROFILE_PORTRAIT_720P = 1050,
  /** 1052: 720 * 1280, frame rate 30 fps, bitrate 1710 Kbps. */
  VIDEO_PROFILE_PORTRAIT_720P_3 = 1052,
  /** 1054: 720 * 960, frame rate 15 fps, bitrate 910 Kbps. */
  VIDEO_PROFILE_PORTRAIT_720P_5 = 1054,
  /** 1055: 720 * 960, frame rate 30 fps, bitrate 1380 Kbps. */
  VIDEO_PROFILE_PORTRAIT_720P_6 = 1055,
  /** 1060: 1080 * 1920, frame rate 15 fps, bitrate 2080 Kbps. */
  VIDEO_PROFILE_PORTRAIT_1080P = 1060,
  /** 1062: 1080 * 1920, frame rate 30 fps, bitrate 3150 Kbps. */
  VIDEO_PROFILE_PORTRAIT_1080P_3 = 1062,
  /** 1064: 1080 * 1920, frame rate 60 fps, bitrate 4780 Kbps. */
  VIDEO_PROFILE_PORTRAIT_1080P_5 = 1064,
  /** 1066: 1440 * 2560, frame rate 30 fps, bitrate 4850 Kbps. */
  VIDEO_PROFILE_PORTRAIT_1440P = 1066,
  /** 1067: 1440 * 2560, frame rate 60 fps, bitrate 6500 Kbps. */
  VIDEO_PROFILE_PORTRAIT_1440P_2 = 1067,
  /** 1070: 2160 * 3840, frame rate 30 fps, bitrate 6500 Kbps. */
  VIDEO_PROFILE_PORTRAIT_4K = 1070,
  /** 1072: 2160 * 3840, frame rate 60 fps, bitrate 6500 Kbps. */
  VIDEO_PROFILE_PORTRAIT_4K_3 = 1072,
  /** Default 640 * 360, frame rate 15 fps, bitrate 400 Kbps. */
  VIDEO_PROFILE_DEFAULT = VIDEO_PROFILE_LANDSCAPE_360P,
};

/** Audio profiles.

Sets the sample rate, bitrate, encoding mode, and the number of channels:*/
enum AUDIO_PROFILE_TYPE // sample rate, bit rate, mono/stereo, speech/music
                        // codec
{
  /**
   0: Default audio profile:
   - For the interactive streaming profile: A sample rate of 48 KHz, music
   encoding, mono, and a bitrate of up to 64 Kbps.
   - For the `COMMUNICATION` profile:
      - Windows: A sample rate of 16 KHz, music encoding, mono, and a bitrate of
   up to 16 Kbps.
      - Android/macOS/iOS: A sample rate of 32 KHz, music encoding, mono, and a
   bitrate of up to 18 Kbps.
  */
  AUDIO_PROFILE_DEFAULT = 0, // use default settings
  /**
   1: A sample rate of 32 KHz, audio encoding, mono, and a bitrate of up to 18
   Kbps.
   */
  AUDIO_PROFILE_SPEECH_STANDARD = 1, // 32Khz, 18Kbps, mono, speech
  /**
   2: A sample rate of 48 KHz, music encoding, mono, and a bitrate of up to 64
   Kbps.
   */
  AUDIO_PROFILE_MUSIC_STANDARD = 2, // 48Khz, 48Kbps, mono, music
  /**
   3: A sample rate of 48 KHz, music encoding, stereo, and a bitrate of up to 80
   Kbps.
   */
  AUDIO_PROFILE_MUSIC_STANDARD_STEREO = 3, // 48Khz, 56Kbps, stereo, music
  /**
   4: A sample rate of 48 KHz, music encoding, mono, and a bitrate of up to 96
   Kbps.
   */
  AUDIO_PROFILE_MUSIC_HIGH_QUALITY = 4, // 48Khz, 128Kbps, mono, music
  /**
   5: A sample rate of 48 KHz, music encoding, stereo, and a bitrate of up to
   128 Kbps.
   */
  AUDIO_PROFILE_MUSIC_HIGH_QUALITY_STEREO = 5, // 48Khz, 192Kbps, stereo, music
  /**
   6: A sample rate of 16 KHz, audio encoding, mono, and Acoustic Echo
   Cancellation (AES) enabled.
   */
  AUDIO_PROFILE_IOT = 6,
  AUDIO_PROFILE_NUM = 7,
};

/** Audio application scenarios.
 */
enum AUDIO_SCENARIO_TYPE // set a suitable scenario for your app type
{
  /** 0: Default. */
  AUDIO_SCENARIO_DEFAULT = 0,
  /** 1: Entertainment scenario, supporting voice during gameplay. */
  AUDIO_SCENARIO_CHATROOM_ENTERTAINMENT = 1,
  /** 2: Education scenario, prioritizing smoothness and stability. */
  AUDIO_SCENARIO_EDUCATION = 2,
  /** 3: Live gaming scenario, enabling the gaming audio effects in the speaker
     mode in the interactive live streaming scenario. Choose this scenario for
     high-fidelity music playback. */
  AUDIO_SCENARIO_GAME_STREAMING = 3,
  /** 4: Showroom scenario, optimizing the audio quality with external
     professional equipment. */
  AUDIO_SCENARIO_SHOWROOM = 4,
  /** 5: Gaming scenario. */
  AUDIO_SCENARIO_CHATROOM_GAMING = 5,
  /** 6: Applicable to the IoT scenario. */
  AUDIO_SCENARIO_IOT = 6,
  AUDIO_SCENARIO_NUM = 7,
};

/** The channel profile.
 */
enum CHANNEL_PROFILE_TYPE {
  /** (Default) Communication. This profile applies to scenarios such as an
   * audio call or video call, where all users can publish and subscribe to
   * streams.
   */
  CHANNEL_PROFILE_COMMUNICATION = 0,
  /** Live streaming. In this profile, uses have roles, namely, host and
   * audience (default). A host both publishes and subscribes to streams, while
   * an audience subscribes to streams only. This profile applies to scenarios
   * such as a chat room or interactive video streaming.
   */
  CHANNEL_PROFILE_LIVE_BROADCASTING = 1,
  /** 2: Gaming. This profile uses a codec with a lower bitrate and consumes
   * less power. Applies to the gaming scenario, where all game players can talk
   * freely.
   */
  CHANNEL_PROFILE_GAME = 2,
};

/** Client roles in the live interactive streaming. */
enum CLIENT_ROLE_TYPE {
  /** 1: Host. A host can both send and receive streams. */
  CLIENT_ROLE_BROADCASTER = 1,
  /** 2: Audience, the default role. An audience can only receive streams. */
  CLIENT_ROLE_AUDIENCE = 2,
};

/** Reasons for a user being offline. */
enum USER_OFFLINE_REASON_TYPE {
  /** 0: The user quits the call. */
  USER_OFFLINE_QUIT = 0,
  /** 1: The SDK times out and the user drops offline because no data packet is
     received within a certain period of time. If the user quits the call and
     the message is not passed to the SDK (due to an unreliable channel), the
     SDK assumes the user dropped offline. */
  USER_OFFLINE_DROPPED = 1,
  /** 2: (`LIVE_BROADCASTING` only.) The client role switched from the host to
     the audience. */
  USER_OFFLINE_BECOME_AUDIENCE = 2,
};
/**
 States of the RTMP streaming.
 */
enum RTMP_STREAM_PUBLISH_STATE {
  /** The RTMP streaming has not started or has ended. This state is also
   * triggered after you remove an RTMP address from the CDN by calling
   * removePublishStreamUrl.
   */
  RTMP_STREAM_PUBLISH_STATE_IDLE = 0,
  /** The SDK is connecting to Agora's streaming server and the RTMP server.
   * This state is triggered after you call the \ref
   * IRtcEngine::addPublishStreamUrl "addPublishStreamUrl" method.
   */
  RTMP_STREAM_PUBLISH_STATE_CONNECTING = 1,
  /** The RTMP streaming publishes. The SDK successfully publishes the RTMP
   * streaming and returns this state.
   */
  RTMP_STREAM_PUBLISH_STATE_RUNNING = 2,
  /** The RTMP streaming is recovering. When exceptions occur to the CDN, or the
   streaming is interrupted, the SDK tries to resume RTMP streaming and returns
   this state.

   - If the SDK successfully resumes the streaming,
   #RTMP_STREAM_PUBLISH_STATE_RUNNING (2) returns.
   - If the streaming does not resume within 60 seconds or server errors occur,
   #RTMP_STREAM_PUBLISH_STATE_FAILURE (4) returns. You can also reconnect to the
   server by calling the \ref IRtcEngine::removePublishStreamUrl
   "removePublishStreamUrl" and \ref IRtcEngine::addPublishStreamUrl
   "addPublishStreamUrl" methods.
   */
  RTMP_STREAM_PUBLISH_STATE_RECOVERING = 3,
  /** The RTMP streaming fails. See the errCode parameter for the detailed error
   * information. You can also call the \ref IRtcEngine::addPublishStreamUrl
   * "addPublishStreamUrl" method to publish the RTMP streaming again.
   */
  RTMP_STREAM_PUBLISH_STATE_FAILURE = 4,
};

/**
 Error codes of the RTMP streaming.
 */
enum RTMP_STREAM_PUBLISH_ERROR {
  /** The RTMP streaming publishes successfully. */
  RTMP_STREAM_PUBLISH_ERROR_OK = 0,
  /** Invalid argument used. If, for example, you do not call the \ref
     IRtcEngine::setLiveTranscoding "setLiveTranscoding" method to configure the
     LiveTranscoding parameters before calling the addPublishStreamUrl method,
     the SDK returns this error. Check whether you set the parameters in the
     *setLiveTranscoding* method properly. */
  RTMP_STREAM_PUBLISH_ERROR_INVALID_ARGUMENT = 1,
  /** The RTMP streaming is encrypted and cannot be published. */
  RTMP_STREAM_PUBLISH_ERROR_ENCRYPTED_STREAM_NOT_ALLOWED = 2,
  /** Timeout for the RTMP streaming. Call the \ref
     IRtcEngine::addPublishStreamUrl "addPublishStreamUrl" method to publish the
     streaming again. */
  RTMP_STREAM_PUBLISH_ERROR_CONNECTION_TIMEOUT = 3,
  /** An error occurs in Agora's streaming server. Call the addPublishStreamUrl
     method to publish the streaming again. */
  RTMP_STREAM_PUBLISH_ERROR_INTERNAL_SERVER_ERROR = 4,
  /** An error occurs in the RTMP server. */
  RTMP_STREAM_PUBLISH_ERROR_RTMP_SERVER_ERROR = 5,
  /** The RTMP streaming publishes too frequently. */
  RTMP_STREAM_PUBLISH_ERROR_TOO_OFTEN = 6,
  /** The host publishes more than 10 URLs. Delete the unnecessary URLs before
     adding new ones. */
  RTMP_STREAM_PUBLISH_ERROR_REACH_LIMIT = 7,
  /** The host manipulates other hosts' URLs. Check your app logic. */
  RTMP_STREAM_PUBLISH_ERROR_NOT_AUTHORIZED = 8,
  /** Agora's server fails to find the RTMP streaming. */
  RTMP_STREAM_PUBLISH_ERROR_STREAM_NOT_FOUND = 9,
  /** The format of the RTMP streaming URL is not supported. Check whether the
     URL format is correct. */
  RTMP_STREAM_PUBLISH_ERROR_FORMAT_NOT_SUPPORTED = 10,
};

/** Events during the RTMP streaming. */
enum RTMP_STREAMING_EVENT {
  /** An error occurs when you add a background image or a watermark image to
   * the RTMP stream.
   */
  RTMP_STREAMING_EVENT_FAILED_LOAD_IMAGE = 1,
};

/** States of importing an external video stream in the live interactive
 * streaming. */
enum INJECT_STREAM_STATUS {
  /** 0: The external video stream imported successfully. */
  INJECT_STREAM_STATUS_START_SUCCESS = 0,
  /** 1: The external video stream already exists. */
  INJECT_STREAM_STATUS_START_ALREADY_EXISTS = 1,
  /** 2: The external video stream to be imported is unauthorized. */
  INJECT_STREAM_STATUS_START_UNAUTHORIZED = 2,
  /** 3: Import external video stream timeout. */
  INJECT_STREAM_STATUS_START_TIMEDOUT = 3,
  /** 4: Import external video stream failed. */
  INJECT_STREAM_STATUS_START_FAILED = 4,
  /** 5: The external video stream stopped importing successfully. */
  INJECT_STREAM_STATUS_STOP_SUCCESS = 5,
  /** 6: No external video stream is found. */
  INJECT_STREAM_STATUS_STOP_NOT_FOUND = 6,
  /** 7: The external video stream to be stopped importing is unauthorized. */
  INJECT_STREAM_STATUS_STOP_UNAUTHORIZED = 7,
  /** 8: Stop importing external video stream timeout. */
  INJECT_STREAM_STATUS_STOP_TIMEDOUT = 8,
  /** 9: Stop importing external video stream failed. */
  INJECT_STREAM_STATUS_STOP_FAILED = 9,
  /** 10: The external video stream is corrupted. */
  INJECT_STREAM_STATUS_BROKEN = 10,
};
/** Remote video stream types. */
enum REMOTE_VIDEO_STREAM_TYPE {
  /** 0: High-stream video. */
  REMOTE_VIDEO_STREAM_HIGH = 0,
  /** 1: Low-stream video. */
  REMOTE_VIDEO_STREAM_LOW = 1,
};

/** The use mode of the audio data in the \ref
 * media::IAudioFrameObserver::onRecordAudioFrame "onRecordAudioFrame" or \ref
 * media::IAudioFrameObserver::onPlaybackAudioFrame "onPlaybackAudioFrame"
 * callback.
 */
enum RAW_AUDIO_FRAME_OP_MODE_TYPE {
  /** 0: Read-only mode: Users only read the \ref
     agora::media::IAudioFrameObserver::AudioFrame "AudioFrame" data without
     modifying anything. For example, when users acquire the data with the Agora
     SDK, then push the RTMP streams. */
  RAW_AUDIO_FRAME_OP_MODE_READ_ONLY = 0,
  /** 1: Write-only mode: Users replace the \ref
     agora::media::IAudioFrameObserver::AudioFrame "AudioFrame" data with their
     own data and pass the data to the SDK for encoding. For example, when users
     acquire the data. */
  RAW_AUDIO_FRAME_OP_MODE_WRITE_ONLY = 1,
  /** 2: Read and write mode: Users read the data from \ref
     agora::media::IAudioFrameObserver::AudioFrame "AudioFrame", modify it, and
     then play it. For example, when users have their own sound-effect
     processing module and perform some voice pre-processing, such as a voice
     change. */
  RAW_AUDIO_FRAME_OP_MODE_READ_WRITE = 2,
};

/** Audio-sample rates. */
enum AUDIO_SAMPLE_RATE_TYPE {
  /** 32000: 32 kHz */
  AUDIO_SAMPLE_RATE_32000 = 32000,
  /** 44100: 44.1 kHz */
  AUDIO_SAMPLE_RATE_44100 = 44100,
  /** 48000: 48 kHz */
  AUDIO_SAMPLE_RATE_48000 = 48000,
};

/** Video codec profile types. */
enum VIDEO_CODEC_PROFILE_TYPE { /** 66: Baseline video codec profile. Generally
                                   used in video calls on mobile phones. */
                                VIDEO_CODEC_PROFILE_BASELINE = 66,
                                /** 77: Main video codec profile. Generally used
                                   in mainstream electronics such as MP4
                                   players, portable video players, PSP, and
                                   iPads. */
                                VIDEO_CODEC_PROFILE_MAIN = 77,
                                /** 100: (Default) High video codec profile.
                                   Generally used in high-resolution live
                                   streaming or television. */
                                VIDEO_CODEC_PROFILE_HIGH = 100,
};

/** Video codec types */
enum VIDEO_CODEC_TYPE {
  /** Standard VP8 */
  VIDEO_CODEC_VP8 = 1,
  /** Standard H264 */
  VIDEO_CODEC_H264 = 2,
  /** Enhanced VP8 */
  VIDEO_CODEC_EVP = 3,
  /** Enhanced H264 */
  VIDEO_CODEC_E264 = 4,
};

/** Audio equalization band frequencies. */
enum AUDIO_EQUALIZATION_BAND_FREQUENCY {
  /** 0: 31 Hz */
  AUDIO_EQUALIZATION_BAND_31 = 0,
  /** 1: 62 Hz */
  AUDIO_EQUALIZATION_BAND_62 = 1,
  /** 2: 125 Hz */
  AUDIO_EQUALIZATION_BAND_125 = 2,
  /** 3: 250 Hz */
  AUDIO_EQUALIZATION_BAND_250 = 3,
  /** 4: 500 Hz */
  AUDIO_EQUALIZATION_BAND_500 = 4,
  /** 5: 1 kHz */
  AUDIO_EQUALIZATION_BAND_1K = 5,
  /** 6: 2 kHz */
  AUDIO_EQUALIZATION_BAND_2K = 6,
  /** 7: 4 kHz */
  AUDIO_EQUALIZATION_BAND_4K = 7,
  /** 8: 8 kHz */
  AUDIO_EQUALIZATION_BAND_8K = 8,
  /** 9: 16 kHz */
  AUDIO_EQUALIZATION_BAND_16K = 9,
};

/** Audio reverberation types. */
enum AUDIO_REVERB_TYPE {
  /** 0: The level of the dry signal (db). The value is between -20 and 10. */
  AUDIO_REVERB_DRY_LEVEL = 0, // (dB, [-20,10]), the level of the dry signal
  /** 1: The level of the early reflection signal (wet signal) (dB). The value
     is between -20 and 10. */
  AUDIO_REVERB_WET_LEVEL = 1, // (dB, [-20,10]), the level of the early
                              // reflection signal (wet signal)
  /** 2: The room size of the reflection. The value is between 0 and 100. */
  AUDIO_REVERB_ROOM_SIZE = 2, // ([0,100]), the room size of the reflection
  /** 3: The length of the initial delay of the wet signal (ms). The value is
     between 0 and 200. */
  AUDIO_REVERB_WET_DELAY = 3, // (ms, [0,200]), the length of the initial delay
                              // of the wet signal in ms
  /** 4: The reverberation strength. The value is between 0 and 100. */
  AUDIO_REVERB_STRENGTH = 4, // ([0,100]), the strength of the reverberation
};

/**
 * Local voice changer options.
 */
enum VOICE_CHANGER_PRESET {
  /**
   * The original voice (no local voice change).
   */
  VOICE_CHANGER_OFF = 0x00000000, // Turn off the voice changer
  /**
   * The voice of an old man.
   */
  VOICE_CHANGER_OLDMAN = 0x00000001,
  /**
   * The voice of a little boy.
   */
  VOICE_CHANGER_BABYBOY = 0x00000002,
  /**
   * The voice of a little girl.
   */
  VOICE_CHANGER_BABYGIRL = 0x00000003,
  /**
   * The voice of Zhu Bajie, a character in Journey to the West who has a voice
   * like that of a growling bear.
   */
  VOICE_CHANGER_ZHUBAJIE = 0x00000004,
  /**
   * The ethereal voice.
   */
  VOICE_CHANGER_ETHEREAL = 0x00000005,
  /**
   * The voice of Hulk.
   */
  VOICE_CHANGER_HULK = 0x00000006,
  /**
   * A more vigorous voice.
   */
  VOICE_BEAUTY_VIGOROUS = 0x00100001, // 7,
  /**
   * A deeper voice.
   */
  VOICE_BEAUTY_DEEP = 0x00100002,
  /**
   * A mellower voice.
   */
  VOICE_BEAUTY_MELLOW = 0x00100003,
  /**
   * Falsetto.
   */
  VOICE_BEAUTY_FALSETTO = 0x00100004,
  /**
   * A fuller voice.
   */
  VOICE_BEAUTY_FULL = 0x00100005,
  /**
   * A clearer voice.
   */
  VOICE_BEAUTY_CLEAR = 0x00100006,
  /**
   * A more resounding voice.
   */
  VOICE_BEAUTY_RESOUNDING = 0x00100007,
  /**
   * A more ringing voice.
   */
  VOICE_BEAUTY_RINGING = 0x00100008,
  /**
   * A more spatially resonant voice.
   */
  VOICE_BEAUTY_SPACIAL = 0x00100009,
  /**
   * (For male only) A more magnetic voice. Do not use it when the speaker is a
   * female; otherwise, voice distortion occurs.
   */
  GENERAL_BEAUTY_VOICE_MALE_MAGNETIC = 0x00200001,
  /**
   * (For female only) A fresher voice. Do not use it when the speaker is a
   * male; otherwise, voice distortion occurs.
   */
  GENERAL_BEAUTY_VOICE_FEMALE_FRESH = 0x00200002,
  /**
   * 	(For female only) A more vital voice. Do not use it when the speaker is
   * a male; otherwise, voice distortion occurs.
   */
  GENERAL_BEAUTY_VOICE_FEMALE_VITALITY = 0x00200003

};

/** Local voice reverberation presets. */
enum AUDIO_REVERB_PRESET {
  /**
   * Turn off local voice reverberation, that is, to use the original voice.
   */
  AUDIO_REVERB_OFF = 0x00000000, // Turn off audio reverb
  /**
   * The reverberation style typical of a KTV venue (enhanced).
   */
  AUDIO_REVERB_FX_KTV = 0x00100001,
  /**
   * The reverberation style typical of a concert hall (enhanced).
   */
  AUDIO_REVERB_FX_VOCAL_CONCERT = 0x00100002,
  /**
   * The reverberation style typical of an uncle's voice.
   */
  AUDIO_REVERB_FX_UNCLE = 0x00100003,
  /**
   * The reverberation style typical of a little sister's voice.
   */
  AUDIO_REVERB_FX_SISTER = 0x00100004,
  /**
   * The reverberation style typical of a recording studio (enhanced).
   */
  AUDIO_REVERB_FX_STUDIO = 0x00100005,
  /**
   * The reverberation style typical of popular music (enhanced).
   */
  AUDIO_REVERB_FX_POPULAR = 0x00100006,
  /**
   * The reverberation style typical of R&B music (enhanced).
   */
  AUDIO_REVERB_FX_RNB = 0x00100007,
  /**
   * The reverberation style typical of the vintage phonograph.
   */
  AUDIO_REVERB_FX_PHONOGRAPH = 0x00100008,
  /**
   * The reverberation style typical of popular music.
   */
  AUDIO_REVERB_POPULAR = 0x00000001,
  /**
   * The reverberation style typical of R&B music.
   */
  AUDIO_REVERB_RNB = 0x00000002,
  /**
   * The reverberation style typical of rock music.
   */
  AUDIO_REVERB_ROCK = 0x00000003,
  /**
   * The reverberation style typical of hip-hop music.
   */
  AUDIO_REVERB_HIPHOP = 0x00000004,
  /**
   * The reverberation style typical of a concert hall.
   */
  AUDIO_REVERB_VOCAL_CONCERT = 0x00000005,
  /**
   * The reverberation style typical of a KTV venue.
   */
  AUDIO_REVERB_KTV = 0x00000006,
  /**
   * The reverberation style typical of a recording studio.
   */
  AUDIO_REVERB_STUDIO = 0x00000007,
  /**
   * The reverberation of the virtual stereo. The virtual stereo is an effect
   * that renders the monophonic audio as the stereo audio, so that all users in
   * the channel can hear the stereo voice effect. To achieve better virtual
   * stereo reverberation, Agora recommends setting `profile` in
   * `setAudioProfile` as `AUDIO_PROFILE_MUSIC_HIGH_QUALITY_STEREO(5)`.
   */
  AUDIO_VIRTUAL_STEREO = 0x00200001
};
/** Audio codec profile types. The default value is LC_ACC. */
enum AUDIO_CODEC_PROFILE_TYPE {
  /** 0: LC-AAC, which is the low-complexity audio codec type. */
  AUDIO_CODEC_PROFILE_LC_AAC = 0,
  /** 1: HE-AAC, which is the high-efficiency audio codec type. */
  AUDIO_CODEC_PROFILE_HE_AAC = 1,
};

/** Remote audio states.
 */
enum REMOTE_AUDIO_STATE {
  /** 0: The remote audio is in the default state, probably due to
   * #REMOTE_AUDIO_REASON_LOCAL_MUTED (3),
   * #REMOTE_AUDIO_REASON_REMOTE_MUTED (5), or
   * #REMOTE_AUDIO_REASON_REMOTE_OFFLINE (7).
   */
  REMOTE_AUDIO_STATE_STOPPED = 0, // Default state, audio is started or remote
                                  // user disabled/muted audio stream
  /** 1: The first remote audio packet is received.
   */
  REMOTE_AUDIO_STATE_STARTING =
      1, // The first audio frame packet has been received
  /** 2: The remote audio stream is decoded and plays normally, probably
   * due to #REMOTE_AUDIO_REASON_NETWORK_RECOVERY (2),
   * #REMOTE_AUDIO_REASON_LOCAL_UNMUTED (4), or
   * #REMOTE_AUDIO_REASON_REMOTE_UNMUTED (6).
   */
  REMOTE_AUDIO_STATE_DECODING =
      2, // The first remote audio frame has been decoded or fronzen state ends
  /** 3: The remote audio is frozen, probably due to
   * #REMOTE_AUDIO_REASON_NETWORK_CONGESTION (1).
   */
  REMOTE_AUDIO_STATE_FROZEN =
      3, // Remote audio is frozen, probably due to network issue
  /** 4: The remote audio fails to start, probably due to
   * #REMOTE_AUDIO_REASON_INTERNAL (0).
   */
  REMOTE_AUDIO_STATE_FAILED = 4, // Remote audio play failed
};

/** Remote audio state reasons.
 */
enum REMOTE_AUDIO_STATE_REASON {
  /** 0: Internal reasons.
   */
  REMOTE_AUDIO_REASON_INTERNAL = 0,
  /** 1: Network congestion.
   */
  REMOTE_AUDIO_REASON_NETWORK_CONGESTION = 1,
  /** 2: Network recovery.
   */
  REMOTE_AUDIO_REASON_NETWORK_RECOVERY = 2,
  /** 3: The local user stops receiving the remote audio stream or
   * disables the audio module.
   */
  REMOTE_AUDIO_REASON_LOCAL_MUTED = 3,
  /** 4: The local user resumes receiving the remote audio stream or
   * enables the audio module.
   */
  REMOTE_AUDIO_REASON_LOCAL_UNMUTED = 4,
  /** 5: The remote user stops sending the audio stream or disables the
   * audio module.
   */
  REMOTE_AUDIO_REASON_REMOTE_MUTED = 5,
  /** 6: The remote user resumes sending the audio stream or enables the
   * audio module.
   */
  REMOTE_AUDIO_REASON_REMOTE_UNMUTED = 6,
  /** 7: The remote user leaves the channel.
   */
  REMOTE_AUDIO_REASON_REMOTE_OFFLINE = 7,
};

/** Remote video states. */
// enum REMOTE_VIDEO_STATE
// {
//     // REMOTE_VIDEO_STATE_STOPPED is not used at this version. Ignore this
//     value.
//     // REMOTE_VIDEO_STATE_STOPPED = 0,  // Default state, video is started or
//     remote user disabled/muted video stream
//       /** 1: The remote video is playing. */
//       REMOTE_VIDEO_STATE_RUNNING = 1,  // Running state, remote video can be
//       displayed normally
//       /** 2: The remote video is frozen. */
//       REMOTE_VIDEO_STATE_FROZEN = 2,    // Remote video is frozen, probably
//       due to network issue.
// };

/** The state of the remote video. */
enum REMOTE_VIDEO_STATE {
  /** 0: The remote video is in the default state, probably due to
   * #REMOTE_VIDEO_STATE_REASON_LOCAL_MUTED (3),
   * #REMOTE_VIDEO_STATE_REASON_REMOTE_MUTED (5), or
   * #REMOTE_VIDEO_STATE_REASON_REMOTE_OFFLINE (7).
   */
  REMOTE_VIDEO_STATE_STOPPED = 0,

  /** 1: The first remote video packet is received.
   */
  REMOTE_VIDEO_STATE_STARTING = 1,

  /** 2: The remote video stream is decoded and plays normally, probably due to
   * #REMOTE_VIDEO_STATE_REASON_NETWORK_RECOVERY (2),
   * #REMOTE_VIDEO_STATE_REASON_LOCAL_UNMUTED (4),
   * #REMOTE_VIDEO_STATE_REASON_REMOTE_UNMUTED (6), or
   * #REMOTE_VIDEO_STATE_REASON_AUDIO_FALLBACK_RECOVERY (9).
   */
  REMOTE_VIDEO_STATE_DECODING = 2,

  /** 3: The remote video is frozen, probably due to
   * #REMOTE_VIDEO_STATE_REASON_NETWORK_CONGESTION (1) or
   * #REMOTE_VIDEO_STATE_REASON_AUDIO_FALLBACK (8).
   */
  REMOTE_VIDEO_STATE_FROZEN = 3,

  /** 4: The remote video fails to start, probably due to
   * #REMOTE_VIDEO_STATE_REASON_INTERNAL (0).
   */
  REMOTE_VIDEO_STATE_FAILED = 4
};
/** The publishing state.
 */
enum STREAM_PUBLISH_STATE {
  /** 0: The initial publishing state after joining the channel.
   */
  PUB_STATE_IDLE = 0,
  /** 1: Fails to publish the local stream. Possible reasons:
   * - The local user calls \ref IRtcEngine::muteLocalAudioStream
   * "muteLocalAudioStream(true)" or \ref IRtcEngine::muteLocalVideoStream
   * "muteLocalVideoStream(true)" to stop sending local streams.
   * - The local user calls \ref IRtcEngine::disableAudio "disableAudio" or \ref
   * IRtcEngine::disableVideo "disableVideo" to disable the entire audio or
   * video module.
   * - The local user calls \ref IRtcEngine::enableLocalAudio
   * "enableLocalAudio(false)" or \ref IRtcEngine::enableLocalVideo
   * "enableLocalVideo(false)" to disable the local audio sampling or video
   * capturing.
   * - The role of the local user is `AUDIENCE`.
   */
  PUB_STATE_NO_PUBLISHED = 1,
  /** 2: Publishing.
   */
  PUB_STATE_PUBLISHING = 2,
  /** 3: Publishes successfully.
   */
  PUB_STATE_PUBLISHED = 3
};
/** The subscribing state.
 */
enum STREAM_SUBSCRIBE_STATE {
  /** 0: The initial subscribing state after joining the channel.
   */
  SUB_STATE_IDLE = 0,
  /** 1: Fails to subscribe to the remote stream. Possible reasons:
   * - The remote user:
   *  - Calls \ref IRtcEngine::muteLocalAudioStream "muteLocalAudioStream(true)"
   * or \ref IRtcEngine::muteLocalVideoStream "muteLocalVideoStream(true)" to
   * stop sending local streams.
   *  - Calls \ref IRtcEngine::disableAudio "disableAudio" or \ref
   * IRtcEngine::disableVideo "disableVideo" to disable the entire audio or
   * video modules.
   *  - Calls \ref IRtcEngine::enableLocalAudio "enableLocalAudio(false)" or
   * \ref IRtcEngine::enableLocalVideo "enableLocalVideo(false)" to disable the
   * local audio sampling or video capturing.
   *  - The role of the remote user is `AUDIENCE`.
   * - The local user calls the following methods to stop receiving remote
   * streams:
   *  - Calls \ref IRtcEngine::muteRemoteAudioStream
   * "muteRemoteAudioStream(true)", \ref IRtcEngine::muteAllRemoteAudioStreams
   * "muteAllRemoteAudioStreams(true)", or \ref
   * IRtcEngine::setDefaultMuteAllRemoteAudioStreams
   * "setDefaultMuteAllRemoteAudioStreams(true)" to stop receiving remote audio
   * streams.
   *  - Calls \ref IRtcEngine::muteRemoteVideoStream
   * "muteRemoteVideoStream(true)", \ref IRtcEngine::muteAllRemoteVideoStreams
   * "muteAllRemoteVideoStreams(true)", or \ref
   * IRtcEngine::setDefaultMuteAllRemoteVideoStreams
   * "setDefaultMuteAllRemoteVideoStreams(true)" to stop receiving remote video
   * streams.
   */
  SUB_STATE_NO_SUBSCRIBED = 1,
  /** 2: Subscribing.
   */
  SUB_STATE_SUBSCRIBING = 2,
  /** 3: Subscribes to and receives the remote stream successfully.
   */
  SUB_STATE_SUBSCRIBED = 3
};

/** The reason for the remote video state change. */
enum REMOTE_VIDEO_STATE_REASON {
  /** 0: Internal reasons.
   */
  REMOTE_VIDEO_STATE_REASON_INTERNAL = 0,

  /** 1: Network congestion.
   */
  REMOTE_VIDEO_STATE_REASON_NETWORK_CONGESTION = 1,

  /** 2: Network recovery.
   */
  REMOTE_VIDEO_STATE_REASON_NETWORK_RECOVERY = 2,

  /** 3: The local user stops receiving the remote video stream or disables the
   * video module.
   */
  REMOTE_VIDEO_STATE_REASON_LOCAL_MUTED = 3,

  /** 4: The local user resumes receiving the remote video stream or enables the
   * video module.
   */
  REMOTE_VIDEO_STATE_REASON_LOCAL_UNMUTED = 4,

  /** 5: The remote user stops sending the video stream or disables the video
   * module.
   */
  REMOTE_VIDEO_STATE_REASON_REMOTE_MUTED = 5,

  /** 6: The remote user resumes sending the video stream or enables the video
   * module.
   */
  REMOTE_VIDEO_STATE_REASON_REMOTE_UNMUTED = 6,

  /** 7: The remote user leaves the channel.
   */
  REMOTE_VIDEO_STATE_REASON_REMOTE_OFFLINE = 7,

  /** 8: The remote audio-and-video stream falls back to the audio-only stream
   * due to poor network conditions.
   */
  REMOTE_VIDEO_STATE_REASON_AUDIO_FALLBACK = 8,

  /** 9: The remote audio-only stream switches back to the audio-and-video
   * stream after the network conditions improve.
   */
  REMOTE_VIDEO_STATE_REASON_AUDIO_FALLBACK_RECOVERY = 9

};

/** Video frame rates. */
enum FRAME_RATE {
  /** 1: 1 fps */
  FRAME_RATE_FPS_1 = 1,
  /** 7: 7 fps */
  FRAME_RATE_FPS_7 = 7,
  /** 10: 10 fps */
  FRAME_RATE_FPS_10 = 10,
  /** 15: 15 fps */
  FRAME_RATE_FPS_15 = 15,
  /** 24: 24 fps */
  FRAME_RATE_FPS_24 = 24,
  /** 30: 30 fps */
  FRAME_RATE_FPS_30 = 30,
  /** 60: 60 fps (Windows and macOS only) */
  FRAME_RATE_FPS_60 = 60,
};

/** Video output orientation modes.
 */
enum ORIENTATION_MODE {
  /** 0: (Default) Adaptive mode.

   The video encoder adapts to the orientation mode of the video input device.

   - If the width of the captured video from the SDK is greater than the height,
   the encoder sends the video in landscape mode. The encoder also sends the
   rotational information of the video, and the receiver uses the rotational
   information to rotate the received video.
   - When you use a custom video source, the output video from the encoder
   inherits the orientation of the original video. If the original video is in
   portrait mode, the output video from the encoder is also in portrait mode.
   The encoder also sends the rotational information of the video to the
   receiver.
   */
  ORIENTATION_MODE_ADAPTIVE = 0,
  /** 1: Landscape mode.

   The video encoder always sends the video in landscape mode. The video encoder
   rotates the original video before sending it and the rotational infomation is
   0. This mode applies to scenarios involving CDN live streaming.
   */
  ORIENTATION_MODE_FIXED_LANDSCAPE = 1,
  /** 2: Portrait mode.

   The video encoder always sends the video in portrait mode. The video encoder
   rotates the original video before sending it and the rotational infomation is
   0. This mode applies to scenarios involving CDN live streaming.
   */
  ORIENTATION_MODE_FIXED_PORTRAIT = 2,
};

/** Video degradation preferences when the bandwidth is a constraint. */
enum DEGRADATION_PREFERENCE {
  /** 0: (Default) Degrade the frame rate in order to maintain the video
     quality. */
  MAINTAIN_QUALITY = 0,
  /** 1: Degrade the video quality in order to maintain the frame rate. */
  MAINTAIN_FRAMERATE = 1,
  /** 2: (For future use) Maintain a balance between the frame rate and video
     quality. */
  MAINTAIN_BALANCED = 2,
};

/** Stream fallback options. */
enum STREAM_FALLBACK_OPTIONS {
  /** 0: No fallback behavior for the local/remote video stream when the
     uplink/downlink network conditions are poor. The quality of the stream is
     not guaranteed. */
  STREAM_FALLBACK_OPTION_DISABLED = 0,
  /** 1: Under poor downlink network conditions, the remote video stream, to
     which you subscribe, falls back to the low-stream (low resolution and low
     bitrate) video. You can set this option only in the \ref
     IRtcEngine::setRemoteSubscribeFallbackOption
     "setRemoteSubscribeFallbackOption" method. Nothing happens when you set
     this in the \ref IRtcEngine::setLocalPublishFallbackOption
     "setLocalPublishFallbackOption" method. */
  STREAM_FALLBACK_OPTION_VIDEO_STREAM_LOW = 1,
  /** 2: Under poor uplink network conditions, the published video stream falls
  back to audio only.

  Under poor downlink network conditions, the remote video stream, to which you
  subscribe, first falls back to the low-stream (low resolution and low bitrate)
  video; and then to an audio-only stream if the network conditions worsen.*/
  STREAM_FALLBACK_OPTION_AUDIO_ONLY = 2,
};

/** Camera capturer configuration.
 */
enum CAPTURER_OUTPUT_PREFERENCE {
  /** 0: (Default) self-adapts the camera output parameters to the system
   * performance and network conditions to balance CPU consumption and video
   * preview quality.
   */
  CAPTURER_OUTPUT_PREFERENCE_AUTO = 0,
  /** 1: Prioritizes the system performance. The SDK chooses the dimension and
   * frame rate of the local camera capture closest to those set by \ref
   * IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration".
   */
  CAPTURER_OUTPUT_PREFERENCE_PERFORMANCE = 1,
  /** 2: Prioritizes the local preview quality. The SDK chooses higher camera
   * output parameters to improve the local video preview quality. This option
   * requires extra CPU and RAM usage for video pre-processing.
   */
  CAPTURER_OUTPUT_PREFERENCE_PREVIEW = 2,
};

/** The priority of the remote user.
 */
enum PRIORITY_TYPE {
  /** 50: The user's priority is high.
   */
  PRIORITY_HIGH = 50,
  /** 100: (Default) The user's priority is normal.
   */
  PRIORITY_NORMAL = 100,
};

/** Connection states. */
enum CONNECTION_STATE_TYPE {
  /** 1: The SDK is disconnected from Agora's edge server.

   - This is the initial state before calling the \ref
   agora::rtc::IRtcEngine::joinChannel "joinChannel" method.
   - The SDK also enters this state when the application calls the \ref
   agora::rtc::IRtcEngine::leaveChannel "leaveChannel" method.
   */
  CONNECTION_STATE_DISCONNECTED = 1,
  /** 2: The SDK is connecting to Agora's edge server.

   - When the application calls the \ref agora::rtc::IRtcEngine::joinChannel
   "joinChannel" method, the SDK starts to establish a connection to the
   specified channel, triggers the \ref
   agora::rtc::IRtcEngineEventHandler::onConnectionStateChanged
   "onConnectionStateChanged" callback, and switches to the
   #CONNECTION_STATE_CONNECTING state.
   - When the SDK successfully joins the channel, it triggers the \ref
   agora::rtc::IRtcEngineEventHandler::onConnectionStateChanged
   "onConnectionStateChanged" callback and switches to the
   #CONNECTION_STATE_CONNECTED state.
   - After the SDK joins the channel and when it finishes initializing the media
   engine, the SDK triggers the \ref
   agora::rtc::IRtcEngineEventHandler::onJoinChannelSuccess
   "onJoinChannelSuccess" callback.
   */
  CONNECTION_STATE_CONNECTING = 2,
  /** 3: The SDK is connected to Agora's edge server and has joined a channel.
   You can now publish or subscribe to a media stream in the channel.

   If the connection to the channel is lost because, for example, if the network
   is down or switched, the SDK automatically tries to reconnect and triggers:
   - The \ref agora::rtc::IRtcEngineEventHandler::onConnectionInterrupted
   "onConnectionInterrupted" callback (deprecated).
   - The \ref agora::rtc::IRtcEngineEventHandler::onConnectionStateChanged
   "onConnectionStateChanged" callback and switches to the
   #CONNECTION_STATE_RECONNECTING state.
   */
  CONNECTION_STATE_CONNECTED = 3,
  /** 4: The SDK keeps rejoining the channel after being disconnected from a
   joined channel because of network issues.

   - If the SDK cannot rejoin the channel within 10 seconds after being
   disconnected from Agora's edge server, the SDK triggers the \ref
   agora::rtc::IRtcEngineEventHandler::onConnectionLost "onConnectionLost"
   callback, stays in the #CONNECTION_STATE_RECONNECTING state, and keeps
   rejoining the channel.
   - If the SDK fails to rejoin the channel 20 minutes after being disconnected
   from Agora's edge server, the SDK triggers the \ref
   agora::rtc::IRtcEngineEventHandler::onConnectionStateChanged
   "onConnectionStateChanged" callback, switches to the #CONNECTION_STATE_FAILED
   state, and stops rejoining the channel.
   */
  CONNECTION_STATE_RECONNECTING = 4,
  /** 5: The SDK fails to connect to Agora's edge server or join the channel.

   You must call the \ref agora::rtc::IRtcEngine::leaveChannel "leaveChannel"
   method to leave this state, and call the \ref
   agora::rtc::IRtcEngine::joinChannel "joinChannel" method again to rejoin the
   channel.

   If the SDK is banned from joining the channel by Agora's edge server (through
   the RESTful API), the SDK triggers the \ref
   agora::rtc::IRtcEngineEventHandler::onConnectionBanned "onConnectionBanned"
   (deprecated) and \ref
   agora::rtc::IRtcEngineEventHandler::onConnectionStateChanged
   "onConnectionStateChanged" callbacks.
   */
  CONNECTION_STATE_FAILED = 5,
};

/** Reasons for a connection state change. */
enum CONNECTION_CHANGED_REASON_TYPE {
  /** 0: The SDK is connecting to Agora's edge server. */
  CONNECTION_CHANGED_CONNECTING = 0,
  /** 1: The SDK has joined the channel successfully. */
  CONNECTION_CHANGED_JOIN_SUCCESS = 1,
  /** 2: The connection between the SDK and Agora's edge server is interrupted.
   */
  CONNECTION_CHANGED_INTERRUPTED = 2,
  /** 3: The connection between the SDK and Agora's edge server is banned by
     Agora's edge server. */
  CONNECTION_CHANGED_BANNED_BY_SERVER = 3,
  /** 4: The SDK fails to join the channel for more than 20 minutes and stops
     reconnecting to the channel. */
  CONNECTION_CHANGED_JOIN_FAILED = 4,
  /** 5: The SDK has left the channel. */
  CONNECTION_CHANGED_LEAVE_CHANNEL = 5,
  /** 6: The connection failed since Appid is not valid. */
  CONNECTION_CHANGED_INVALID_APP_ID = 6,
  /** 7: The connection failed since channel name is not valid. */
  CONNECTION_CHANGED_INVALID_CHANNEL_NAME = 7,
  /** 8: The connection failed since token is not valid, possibly because:

   - The App Certificate for the project is enabled in Console, but you do not
   use Token when joining the channel. If you enable the App Certificate, you
   must use a token to join the channel.
   - The uid that you specify in the \ref agora::rtc::IRtcEngine::joinChannel
   "joinChannel" method is different from the uid that you pass for generating
   the token.
   */
  CONNECTION_CHANGED_INVALID_TOKEN = 8,
  /** 9: The connection failed since token is expired. */
  CONNECTION_CHANGED_TOKEN_EXPIRED = 9,
  /** 10: The connection is rejected by server. */
  CONNECTION_CHANGED_REJECTED_BY_SERVER = 10,
  /** 11: The connection changed to reconnecting since SDK has set a proxy
     server. */
  CONNECTION_CHANGED_SETTING_PROXY_SERVER = 11,
  /** 12: When SDK is in connection failed, the renew token operation will make
     it connecting. */
  CONNECTION_CHANGED_RENEW_TOKEN = 12,
  /** 13: The IP Address of SDK client has changed. i.e., Network type or
     IP/Port changed by network operator might change client IP address. */
  CONNECTION_CHANGED_CLIENT_IP_ADDRESS_CHANGED = 13,
  /** 14: Timeout for the keep-alive of the connection between the SDK and
     Agora's edge server. The connection state changes to
     CONNECTION_STATE_RECONNECTING(4). */
  CONNECTION_CHANGED_KEEP_ALIVE_TIMEOUT = 14,
};

/** Network type. */
enum NETWORK_TYPE {
  /** -1: The network type is unknown. */
  NETWORK_TYPE_UNKNOWN = -1,
  /** 0: The SDK disconnects from the network. */
  NETWORK_TYPE_DISCONNECTED = 0,
  /** 1: The network type is LAN. */
  NETWORK_TYPE_LAN = 1,
  /** 2: The network type is Wi-Fi(including hotspots). */
  NETWORK_TYPE_WIFI = 2,
  /** 3: The network type is mobile 2G. */
  NETWORK_TYPE_MOBILE_2G = 3,
  /** 4: The network type is mobile 3G. */
  NETWORK_TYPE_MOBILE_3G = 4,
  /** 5: The network type is mobile 4G. */
  NETWORK_TYPE_MOBILE_4G = 5,
};

/** States of the last-mile network probe test. */
enum LASTMILE_PROBE_RESULT_STATE {
  /** 1: The last-mile network probe test is complete. */
  LASTMILE_PROBE_RESULT_COMPLETE = 1,
  /** 2: The last-mile network probe test is incomplete and the bandwidth
     estimation is not available, probably due to limited test resources. */
  LASTMILE_PROBE_RESULT_INCOMPLETE_NO_BWE = 2,
  /** 3: The last-mile network probe test is not carried out, probably due to
     poor network conditions. */
  LASTMILE_PROBE_RESULT_UNAVAILABLE = 3
};
/** Audio output routing. */
enum AUDIO_ROUTE_TYPE {
  /** Default.
   */
  AUDIO_ROUTE_DEFAULT = -1,
  /** Headset.
   */
  AUDIO_ROUTE_HEADSET = 0,
  /** Earpiece.
   */
  AUDIO_ROUTE_EARPIECE = 1,
  /** Headset with no microphone.
   */
  AUDIO_ROUTE_HEADSET_NO_MIC = 2,
  /** Speakerphone.
   */
  AUDIO_ROUTE_SPEAKERPHONE = 3,
  /** Loudspeaker.
   */
  AUDIO_ROUTE_LOUDSPEAKER = 4,
  /** Bluetooth headset.
   */
  AUDIO_ROUTE_BLUETOOTH = 5,
  /** USB peripheral.
   */
  AUDIO_ROUTE_USB = 6,
  /** HDMI peripheral.
   */
  AUDIO_ROUTE_HDMI = 7,
  /** DisplayPort peripheral.
   */
  AUDIO_ROUTE_DISPLAYPORT = 8,
  /** Apple AirPlay.
   */
  AUDIO_ROUTE_AIRPLAY = 9,
};

#if (defined(__APPLE__) && TARGET_OS_IOS)
/** Audio session restriction. */
enum AUDIO_SESSION_OPERATION_RESTRICTION {
  /** No restriction, the SDK has full control of the audio session operations.
   */
  AUDIO_SESSION_OPERATION_RESTRICTION_NONE = 0,
  /** The SDK does not change the audio session category. */
  AUDIO_SESSION_OPERATION_RESTRICTION_SET_CATEGORY = 1,
  /** The SDK does not change any setting of the audio session (category, mode,
     categoryOptions). */
  AUDIO_SESSION_OPERATION_RESTRICTION_CONFIGURE_SESSION = 1 << 1,
  /** The SDK keeps the audio session active when leaving a channel. */
  AUDIO_SESSION_OPERATION_RESTRICTION_DEACTIVATE_SESSION = 1 << 2,
  /** The SDK does not configure the audio session anymore. */
  AUDIO_SESSION_OPERATION_RESTRICTION_ALL = 1 << 7,
};
#endif

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
enum CAMERA_DIRECTION {
  /** The rear camera. */
  CAMERA_REAR = 0,
  /** The front camera. */
  CAMERA_FRONT = 1,
};
#endif

/** The uplink or downlink last-mile network probe test result. */
struct LastmileProbeOneWayResult {
  /** The packet loss rate (%). */
  unsigned int packetLossRate;
  /** The network jitter (ms). */
  unsigned int jitter;
  /* The estimated available bandwidth (bps). */
  unsigned int availableBandwidth;
};

/** The uplink and downlink last-mile network probe test result. */
struct LastmileProbeResult {
  /** The state of the probe test. */
  enum LASTMILE_PROBE_RESULT_STATE state;
  /** The uplink last-mile network probe test result. */
  struct LastmileProbeOneWayResult uplinkReport;
  /** The downlink last-mile network probe test result. */
  struct LastmileProbeOneWayResult downlinkReport;
  /** The round-trip delay time (ms). */
  unsigned int rtt;
};

/** Configurations of the last-mile network probe test. */
struct LastmileProbeConfig {
  /** Sets whether or not to test the uplink network. Some users, for example,
  the audience in a `LIVE_BROADCASTING` channel, do not need such a test:
  - true: test.
  - false: do not test. */
  BOOL probeUplink;
  /** Sets whether or not to test the downlink network:
  - true: test.
  - false: do not test. */
  BOOL probeDownlink;
  /** The expected maximum sending bitrate (bps) of the local user. The value
   * ranges between 100000 and 5000000. We recommend setting this parameter
   * according to the bitrate value set by \ref
   * IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration". */
  unsigned int expectedUplinkBitrate;
  /** The expected maximum receiving bitrate (bps) of the local user. The value
   * ranges between 100000 and 5000000. */
  unsigned int expectedDownlinkBitrate;
};

/** Properties of the audio volume information.

 An array containing the user ID and volume information for each speaker.
 */
struct AudioVolumeInfo {
  /**
   User ID of the speaker. The uid of the local user is 0.
   */
  uid_t uid;
  /** The volume of the speaker. The volume ranges between 0 (lowest volume) and
   * 255 (highest volume).
   */
  unsigned int volume;
  /** Voice activity status of the local user.
   * - 0: The local user is not speaking.
   * - 1: The local user is speaking.
   *
   * @note
   * - The `vad` parameter cannot report the voice activity status of the remote
   * users. In the remote users' callback, `vad` = 0.
   * - Ensure that you set `report_vad`(true) in the \ref
   * agora::rtc::IRtcEngine::enableAudioVolumeIndication(int, int, bool)
   * "enableAudioVolumeIndication" method to enable the voice activity detection
   * of the local user.
   */
  unsigned int vad;
  /** The channel ID, which indicates which channel the speaker is in.
   */
  const char *channelId;
};

/** Statistics of the channel.
 */
struct RtcStats {
  /**
   Call duration (s), represented by an aggregate value.
   */
  unsigned int duration;
  /**
   Total number of bytes transmitted, represented by an aggregate value.
   */
  unsigned int txBytes;
  /**
   Total number of bytes received, represented by an aggregate value.
   */
  unsigned int rxBytes;
  /** Total number of audio bytes sent (bytes), represented
   * by an aggregate value.
   */
  unsigned int txAudioBytes;
  /** Total number of video bytes sent (bytes), represented
   * by an aggregate value.
   */
  unsigned int txVideoBytes;
  /** Total number of audio bytes received (bytes) before
   * network countermeasures, represented by an aggregate value.
   */
  unsigned int rxAudioBytes;
  /** Total number of video bytes received (bytes),
   * represented by an aggregate value.
   */
  unsigned int rxVideoBytes;

  /**
   Transmission bitrate (Kbps), represented by an instantaneous value.
   */
  unsigned short txKBitRate;
  /**
   Receive bitrate (Kbps), represented by an instantaneous value.
   */
  unsigned short rxKBitRate;
  /**
   Audio receive bitrate (Kbps), represented by an instantaneous value.
   */
  unsigned short rxAudioKBitRate;
  /**
   Audio transmission bitrate (Kbps), represented by an instantaneous value.
   */
  unsigned short txAudioKBitRate;
  /**
   Video receive bitrate (Kbps), represented by an instantaneous value.
   */
  unsigned short rxVideoKBitRate;
  /**
   Video transmission bitrate (Kbps), represented by an instantaneous value.
   */
  unsigned short txVideoKBitRate;
  /** Client-server latency (ms)
   */
  unsigned short lastmileDelay;
  /** The packet loss rate (%) from the local client to Agora's edge server,
   * before using the anti-packet-loss method.
   */
  unsigned short txPacketLossRate;
  /** The packet loss rate (%) from Agora's edge server to the local client,
   * before using the anti-packet-loss method.
   */
  unsigned short rxPacketLossRate;
  /** Number of users in the channel.

   - `COMMUNICATION` profile: The number of users in the channel.
   - `LIVE_BROADCASTING` profile:

       -  If the local user is an audience: The number of users in the channel =
   The number of hosts in the channel + 1.
       -  If the user is a host: The number of users in the channel = The number
   of hosts in the channel.
   */
  unsigned int userCount;
  /**
   Application CPU usage (%).
   */
  double cpuAppUsage;
  /**
   System CPU usage (%).

   In the multi-kernel environment, this member represents the average CPU
   usage. The value **=** 100 **-** System Idle Progress in Task Manager (%).
   */
  double cpuTotalUsage;
  /** The round-trip time delay from the client to the local router.
   */
  int gatewayRtt;
  /**
   The memory usage ratio of the app (%).
   @note This value is for reference only. Due to system limitations, you may
   not get the value of this member.
   */
  double memoryAppUsageRatio;
  /**
   The memory usage ratio of the system (%).
   @note This value is for reference only. Due to system limitations, you may
   not get the value of this member.
   */
  double memoryTotalUsageRatio;
  /**
   The memory usage of the app (KB).
   @note This value is for reference only. Due to system limitations, you may
   not get the value of this member.
   */
  int memoryAppUsageInKbytes;
};

/** Quality change of the local video in terms of target frame rate and target
 * bit rate since last count.
 */
enum QUALITY_ADAPT_INDICATION {
  /** The quality of the local video stays the same. */
  ADAPT_NONE = 0,
  /** The quality improves because the network bandwidth increases. */
  ADAPT_UP_BANDWIDTH = 1,
  /** The quality worsens because the network bandwidth decreases. */
  ADAPT_DOWN_BANDWIDTH = 2,
};

/** The error code in CHANNEL_MEDIA_RELAY_ERROR. */
enum CHANNEL_MEDIA_RELAY_ERROR {
  /** 0: The state is normal.
   */
  RELAY_OK = 0,
  /** 1: An error occurs in the server response.
   */
  RELAY_ERROR_SERVER_ERROR_RESPONSE = 1,
  /** 2: No server response. You can call the
   * \ref agora::rtc::IRtcEngine::leaveChannel "leaveChannel" method to
   * leave the channel.
   */
  RELAY_ERROR_SERVER_NO_RESPONSE = 2,
  /** 3: The SDK fails to access the service, probably due to limited
   * resources of the server.
   */
  RELAY_ERROR_NO_RESOURCE_AVAILABLE = 3,
  /** 4: Fails to send the relay request.
   */
  RELAY_ERROR_FAILED_JOIN_SRC = 4,
  /** 5: Fails to accept the relay request.
   */
  RELAY_ERROR_FAILED_JOIN_DEST = 5,
  /** 6: The server fails to receive the media stream.
   */
  RELAY_ERROR_FAILED_PACKET_RECEIVED_FROM_SRC = 6,
  /** 7: The server fails to send the media stream.
   */
  RELAY_ERROR_FAILED_PACKET_SENT_TO_DEST = 7,
  /** 8: The SDK disconnects from the server due to poor network
   * connections. You can call the \ref agora::rtc::IRtcEngine::leaveChannel
   * "leaveChannel" method to leave the channel.
   */
  RELAY_ERROR_SERVER_CONNECTION_LOST = 8,
  /** 9: An internal error occurs in the server.
   */
  RELAY_ERROR_INTERNAL_ERROR = 9,
  /** 10: The token of the source channel has expired.
   */
  RELAY_ERROR_SRC_TOKEN_EXPIRED = 10,
  /** 11: The token of the destination channel has expired.
   */
  RELAY_ERROR_DEST_TOKEN_EXPIRED = 11,
};

/** The event code in CHANNEL_MEDIA_RELAY_EVENT. */
enum CHANNEL_MEDIA_RELAY_EVENT {
  /** 0: The user disconnects from the server due to poor network
   * connections.
   */
  RELAY_EVENT_NETWORK_DISCONNECTED = 0,
  /** 1: The network reconnects.
   */
  RELAY_EVENT_NETWORK_CONNECTED = 1,
  /** 2: The user joins the source channel.
   */
  RELAY_EVENT_PACKET_JOINED_SRC_CHANNEL = 2,
  /** 3: The user joins the destination channel.
   */
  RELAY_EVENT_PACKET_JOINED_DEST_CHANNEL = 3,
  /** 4: The SDK starts relaying the media stream to the destination channel.
   */
  RELAY_EVENT_PACKET_SENT_TO_DEST_CHANNEL = 4,
  /** 5: The server receives the video stream from the source channel.
   */
  RELAY_EVENT_PACKET_RECEIVED_VIDEO_FROM_SRC = 5,
  /** 6: The server receives the audio stream from the source channel.
   */
  RELAY_EVENT_PACKET_RECEIVED_AUDIO_FROM_SRC = 6,
  /** 7: The destination channel is updated.
   */
  RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL = 7,
  /** 8: The destination channel update fails due to internal reasons.
   */
  RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL_REFUSED = 8,
  /** 9: The destination channel does not change, which means that the
   * destination channel fails to be updated.
   */
  RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL_NOT_CHANGE = 9,
  /** 10: The destination channel name is NULL.
   */
  RELAY_EVENT_PACKET_UPDATE_DEST_CHANNEL_IS_NULL = 10,
  /** 11: The video profile is sent to the server.
   */
  RELAY_EVENT_VIDEO_PROFILE_UPDATE = 11,
};

/** The state code in CHANNEL_MEDIA_RELAY_STATE. */
enum CHANNEL_MEDIA_RELAY_STATE {
  /** 0: The SDK is initializing.
   */
  RELAY_STATE_IDLE = 0,
  /** 1: The SDK tries to relay the media stream to the destination channel.
   */
  RELAY_STATE_CONNECTING = 1,
  /** 2: The SDK successfully relays the media stream to the destination
   * channel.
   */
  RELAY_STATE_RUNNING = 2,
  /** 3: A failure occurs. See the details in code.
   */
  RELAY_STATE_FAILURE = 3,
};

/** Statistics of the local video stream.
 */
struct LocalVideoStats {
  /** Bitrate (Kbps) sent in the reported interval, which does not include
   * the bitrate of the retransmission video after packet loss.
   */
  int sentBitrate;
  /** Frame rate (fps) sent in the reported interval, which does not include
   * the frame rate of the retransmission video after packet loss.
   */
  int sentFrameRate;
  /** The encoder output frame rate (fps) of the local video.
   */
  int encoderOutputFrameRate;
  /** The render output frame rate (fps) of the local video.
   */
  int rendererOutputFrameRate;
  /** The target bitrate (Kbps) of the current encoder. This value is estimated
   * by the SDK based on the current network conditions.
   */
  int targetBitrate;
  /** The target frame rate (fps) of the current encoder.
   */
  int targetFrameRate;
  /** Quality change of the local video in terms of target frame rate and
   * target bit rate in this reported interval. See #QUALITY_ADAPT_INDICATION.
   */
  enum QUALITY_ADAPT_INDICATION qualityAdaptIndication;
  /** The encoding bitrate (Kbps), which does not include the bitrate of the
   * re-transmission video after packet loss.
   */
  int encodedBitrate;
  /** The width of the encoding frame (px).
   */
  int encodedFrameWidth;
  /** The height of the encoding frame (px).
   */
  int encodedFrameHeight;
  /** The value of the sent frames, represented by an aggregate value.
   */
  int encodedFrameCount;
  /** The codec type of the local video:
   * - VIDEO_CODEC_VP8 = 1: VP8.
   * - VIDEO_CODEC_H264 = 2: (Default) H.264.
   */
  enum VIDEO_CODEC_TYPE codecType;
  /** The video packet loss rate (%) from the local client to the Agora edge
   * server before applying the anti-packet loss strategies.
   */
  unsigned short txPacketLossRate;
  /** The capture frame rate (fps) of the local video.
   */
  int captureFrameRate;
};

/** Statistics of the remote video stream.
 */
struct RemoteVideoStats {
  /**
User ID of the remote user sending the video streams.
*/
  uid_t uid;
  /** **DEPRECATED** Time delay (ms).
   *
   * In scenarios where audio and video is synchronized, you can use the value
   * of `networkTransportDelay` and `jitterBufferDelay` in `RemoteAudioStats` to
   * know the delay statistics of the remote video.
   */
  int delay;
  /** Width (pixels) of the video stream.
   */
  int width;
  /**
Height (pixels) of the video stream.
*/
  int height;
  /**
Bitrate (Kbps) received since the last count.
*/
  int receivedBitrate;
  /** The decoder output frame rate (fps) of the remote video.
   */
  int decoderOutputFrameRate;
  /** The render output frame rate (fps) of the remote video.
   */
  int rendererOutputFrameRate;
  /** Packet loss rate (%) of the remote video stream after using the
   * anti-packet-loss method.
   */
  int packetLossRate;
  /** The type of the remote video stream: #REMOTE_VIDEO_STREAM_TYPE
   */
  enum REMOTE_VIDEO_STREAM_TYPE rxStreamType;
  /**
The total freeze time (ms) of the remote video stream after the remote user
joins the channel. In a video session where the frame rate is set to no less
than 5 fps, video freeze occurs when the time interval between two adjacent
renderable video frames is more than 500 ms.
*/
  int totalFrozenTime;
  /**
The total video freeze time as a percentage (%) of the total time when the video
is available.
*/
  int frozenRate;
  /**
The total time (ms) when the remote user in the Communication profile or the
remote broadcaster in the Live-broadcast profile neither stops sending the video
stream nor disables the video module after joining the channel.

@since v3.0.1
*/
  int totalActiveTime;
  /**
   * The total publish duration (ms) of the remote video stream.
   */
  int publishDuration;
};

/** Audio statistics of the local user */
struct LocalAudioStats {
  /** The number of channels.
   */
  int numChannels;
  /** The sample rate (Hz).
   */
  int sentSampleRate;
  /** The average sending bitrate (Kbps).
   */
  int sentBitrate;
  /** The audio packet loss rate (%) from the local client to the Agora edge
   * server before applying the anti-packet loss strategies.
   */
  unsigned short txPacketLossRate;
};

/** Audio statistics of a remote user */
struct RemoteAudioStats {
  /** User ID of the remote user sending the audio streams.
   *
   */
  uid_t uid;
  /** Audio quality received by the user: #QUALITY_TYPE.
   */
  int quality;
  /** Network delay (ms) from the sender to the receiver.
   */
  int networkTransportDelay;
  /** Network delay (ms) from the receiver to the jitter buffer.
   */
  int jitterBufferDelay;
  /** The audio frame loss rate in the reported interval.
   */
  int audioLossRate;
  /** The number of channels.
   */
  int numChannels;
  /** The sample rate (Hz) of the received audio stream in the reported
   * interval.
   */
  int receivedSampleRate;
  /** The average bitrate (Kbps) of the received audio stream in the
   * reported interval. */
  int receivedBitrate;
  /** The total freeze time (ms) of the remote audio stream after the remote
   * user joins the channel. In a session, audio freeze occurs when the audio
   * frame loss rate reaches 4%.
   */
  int totalFrozenTime;
  /** The total audio freeze time as a percentage (%) of the total time when the
   * audio is available. */
  int frozenRate;
  /** The total time (ms) when the remote user in the `COMMUNICATION` profile or
   the remote host in the `LIVE_BROADCASTING` profile neither stops sending the
   audio stream nor disables the audio module after joining the channel.
   */
  int totalActiveTime;
  /**
   * The total publish duration (ms) of the remote audio stream.
   */
  int publishDuration;
};

/**
 * Video dimensions.
 */
struct VideoDimensions {
  /** Width (pixels) of the video. */
  int width;
  /** Height (pixels) of the video. */
  int height;
};

/** (Recommended) The standard bitrate set in the \ref
 IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration" method.

 In this mode, the bitrates differ between the live interactive streaming and
 communication profiles:

 - `COMMUNICATION` profile: The video bitrate is the same as the base bitrate.
 - `LIVE_BROADCASTING` profile: The video bitrate is twice the base bitrate.

 */
const int STANDARD_BITRATE = 0;

/** The compatible bitrate set in the \ref
 IRtcEngine::setVideoEncoderConfiguration "setVideoEncoderConfiguration" method.

 The bitrate remains the same regardless of the channel profile. If you choose
 this mode in the `LIVE_BROADCASTING` profile, the video frame rate may be lower
 than the set value.
 */
const int COMPATIBLE_BITRATE = -1;

/** Use the default minimum bitrate.
 */
const int DEFAULT_MIN_BITRATE = -1;

/** Video encoder configurations.
 */
struct VideoEncoderConfiguration {
  /** The video frame dimensions (px) used to specify the video quality and
   * measured by the total number of pixels along a frame's width and height:
   * VideoDimensions. The default value is 640 x 360.
   */
  struct VideoDimensions dimensions;
  /** The frame rate of the video: #FRAME_RATE. The default value is 15.

   Note that we do not recommend setting this to a value greater than 30.
  */
  enum FRAME_RATE frameRate;
  /** The minimum frame rate of the video. The default value is -1.
   */
  int minFrameRate;
  /** The video encoding bitrate (Kbps).

   Choose one of the following options:

   - #STANDARD_BITRATE: (Recommended) The standard bitrate.
      - the `COMMUNICATION` profile: the encoding bitrate equals the base
   bitrate.
      - the `LIVE_BROADCASTING` profile: the encoding bitrate is twice the base
   bitrate.
   - #COMPATIBLE_BITRATE: The compatible bitrate: the bitrate stays the same
   regardless of the profile.

   the `COMMUNICATION` profile prioritizes smoothness, while the
   `LIVE_BROADCASTING` profile prioritizes video quality (requiring a higher
   bitrate). We recommend setting the bitrate mode as #STANDARD_BITRATE to
   address this difference.

   The following table lists the recommended video encoder configurations, where
   the base bitrate applies to the `COMMUNICATION` profile. Set your bitrate
   based on this table. If you set a bitrate beyond the proper range, the SDK
   automatically sets it to within the range.

   @note
   In the following table, **Base Bitrate** applies to the `COMMUNICATION`
   profile, and **Live Bitrate** applies to the `LIVE_BROADCASTING` profile.

   | Resolution             | Frame Rate (fps) | Base Bitrate (Kbps) | Live
   Bitrate (Kbps)                    |
   |------------------------|------------------|----------------------------------------|----------------------------------------|
   | 160 * 120              | 15               | 65 | 130 | | 120 * 120 | 15 |
   50                                     | 100 | | 320 * 180              | 15
   | 140                                    | 280 | | 180 * 180              |
   15               | 100                                    | 200 | | 240 * 180
   | 15               | 120                                    | 240 | | 320 *
   240              | 15               | 200 | 400 | | 240 * 240              |
   15               | 140                                    | 280 | | 424 * 240
   | 15               | 220                                    | 440 | | 640 *
   360              | 15               | 400 | 800 | | 360 * 360              |
   15               | 260                                    | 520 | | 640 * 360
   | 30               | 600                                    | 1200 | | 360 *
   360              | 30               | 400 | 800 | | 480 * 360              |
   15               | 320                                    | 640 | | 480 * 360
   | 30               | 490                                    | 980 | | 640 *
   480              | 15               | 500 | 1000 | | 480 * 480              |
   15               | 400                                    | 800 | | 640 * 480
   | 30               | 750                                    | 1500 | | 480 *
   480              | 30               | 600 | 1200 | | 848 * 480              |
   15               | 610                                    | 1220 | | 848 *
   480              | 30               | 930 | 1860 | | 640 * 480              |
   10               | 400                                    | 800 | | 1280 *
   720             | 15               | 1130                                   |
   2260                                   | | 1280 * 720             | 30 | 1710
   | 3420                                   | | 960 * 720              | 15 |
   910                                    | 1820 | | 960 * 720              | 30
   | 1380                                   | 2760 | | 1920 * 1080            |
   15               | 2080                                   | 4160 | | 1920 *
   1080            | 30               | 3150                                   |
   6300                                   | | 1920 * 1080            | 60 | 4780
   | 6500                                   | | 2560 * 1440            | 30 |
   4850                                   | 6500 | | 2560 * 1440            | 60
   | 6500                                   | 6500 | | 3840 * 2160            |
   30               | 6500                                   | 6500 | | 3840 *
   2160            | 60               | 6500                                   |
   6500                                   |

   */
  int bitrate;
  /** The minimum encoding bitrate (Kbps).

   The SDK automatically adjusts the encoding bitrate to adapt to the network
   conditions. Using a value greater than the default value forces the video
   encoder to output high-quality images but may cause more packet loss and
   hence sacrifice the smoothness of the video transmission. That said, unless
   you have special requirements for image quality, Agora does not recommend
   changing this value.

   @note This parameter applies only to the `LIVE_BROADCASTING` profile.
   */
  int minBitrate;
  /** The video orientation mode of the video: #ORIENTATION_MODE.
   */
  enum ORIENTATION_MODE orientationMode;
  /** The video encoding degradation preference under limited bandwidth:
   * #DEGRADATION_PREFERENCE.
   */
  enum DEGRADATION_PREFERENCE degradationPreference;
  /** Sets the mirror mode of the published local video stream. It only affects
  the video that the remote user sees. See #VIDEO_MIRROR_MODE_TYPE

  @note: The SDK disables the mirror mode by default.
  */
  enum VIDEO_MIRROR_MODE_TYPE mirrorMode;
};

/** The video and audio properties of the user displaying the video in the CDN
 * live. Agora supports a maximum of 17 transcoding users in a CDN streaming
 * channel.
 */
typedef struct TranscodingUser {
  /** User ID of the user displaying the video in the CDN live.
   */
  uid_t uid;

  /** Horizontal position (pixel) of the video frame relative to the top left
   * corner.
   */
  int x;
  /** Vertical position (pixel) of the video frame relative to the top left
   * corner.
   */
  int y;
  /** Width (pixel) of the video frame. The default value is 360.
   */
  int width;
  /** Height (pixel) of the video frame. The default value is 640.
   */
  int height;

  /** The layer index of the video frame. An integer. The value range is [0,
   100].

   - 0: (Default) Bottom layer.
   - 100: Top layer.

   @note
   - If zOrder is beyond this range, the SDK reports #ERR_INVALID_ARGUMENT.
   - As of v2.3, the SDK supports zOrder = 0.
   */
  int zOrder;
  /** The transparency level of the user's video. The value ranges between 0
   and 1.0:

   - 0: Completely transparent
   - 1.0: (Default) Opaque
   */
  double alpha;
  /** The audio channel of the sound. The default value is 0:

   - 0: (Default) Supports dual channels at most, depending on the upstream of
   the host.
   - 1: The audio stream of the host uses the FL audio channel. If the upstream
   of the host uses multiple audio channels, these channels are mixed into mono
   first.
   - 2: The audio stream of the host uses the FC audio channel. If the upstream
   of the host uses multiple audio channels, these channels are mixed into mono
   first.
   - 3: The audio stream of the host uses the FR audio channel. If the upstream
   of the host uses multiple audio channels, these channels are mixed into mono
   first.
   - 4: The audio stream of the host uses the BL audio channel. If the upstream
   of the host uses multiple audio channels, these channels are mixed into mono
   first.
   - 5: The audio stream of the host uses the BR audio channel. If the upstream
   of the host uses multiple audio channels, these channels are mixed into mono
   first.

   @note If your setting is not 0, you may need a specialized player.
   */
  int audioChannel;
} TranscodingUser;

/** Image properties.

 The properties of the watermark and background images.
 */
typedef struct RtcImage {
  /** HTTP/HTTPS URL address of the image on the live video. The maximum length
   * of this parameter is 1024 bytes. */
  const char *url;
  /** Horizontal position of the image from the upper left of the live video. */
  int x;
  /** Vertical position of the image from the upper left of the live video. */
  int y;
  /** Width of the image on the live video. */
  int width;
  /** Height of the image on the live video. */
  int height;
} RtcImage;
/** The configuration for advanced features of the RTMP streaming with
 * transcoding.
 */
typedef struct LiveStreamAdvancedFeature {
  /** The advanced feature for high-quality video with a lower bitrate. */
  const char *LBHQ;
  /** The advanced feature for the optimized video encoder. */
  const char *VEO;

  /** The name of the advanced feature. It contains LBHQ and VEO.
   */
  const char *featureName;

  /** Whether to enable the advanced feature:
   * - true: Enable the advanced feature.
   * - false: (Default) Disable the advanced feature.
   */
  BOOL opened;
} LiveStreamAdvancedFeature;

/** A struct for managing CDN live audio/video transcoding settings.
 */
typedef struct LiveTranscoding {
  /** The width of the video in pixels. The default value is 360.
   * - When pushing video streams to the CDN, ensure that `width` is at least
   * 64; otherwise, the Agora server adjusts the value to 64.
   * - When pushing audio streams to the CDN, set `width` and `height` as 0.
   */
  int width;
  /** The height of the video in pixels. The default value is 640.
   * - When pushing video streams to the CDN, ensure that `height` is at least
   * 64; otherwise, the Agora server adjusts the value to 64.
   * - When pushing audio streams to the CDN, set `width` and `height` as 0.
   */
  int height;
  /** Bitrate of the CDN live output video stream. The default value is 400
  Kbps.

  Set this parameter according to the Video Bitrate Table. If you set a bitrate
  beyond the proper range, the SDK automatically adapts it to a value within the
  range.
  */
  int videoBitrate;
  /** Frame rate of the output video stream set for the CDN live streaming. The
  default value is 15 fps, and the value range is (0,30].

  @note The Agora server adjusts any value over 30 to 30.
  */
  int videoFramerate;

  /** **DEPRECATED** Latency mode:

   - true: Low latency with unassured quality.
   - false: (Default) High latency with assured quality.
   */
  BOOL lowLatency;

  /** Video GOP in frames. The default value is 30 fps.
   */
  int videoGop;
  /** Self-defined video codec profile: #VIDEO_CODEC_PROFILE_TYPE.

  @note If you set this parameter to other values, Agora adjusts it to the
  default value of 100.
  */
  enum VIDEO_CODEC_PROFILE_TYPE videoCodecProfile;
  /** The background color in RGB hex value. Value only. Do not include a
   * preceeding #. For example, 0xFFB6C1 (light pink). The default value is
   * 0x000000 (black).
   */
  unsigned int backgroundColor;
  /** The number of users in the live interactive streaming.
   */
  unsigned int userCount;
  /** TranscodingUser
   */
  struct TranscodingUser *transcodingUsers;
  /** Reserved property. Extra user-defined information to send SEI for the
   H.264/H.265 video stream to the CDN live client. Maximum length: 4096 Bytes.

   For more information on SEI frame, see [SEI-related
   questions](https://docs.agora.io/en/faq/sei).
   */
  const char *transcodingExtraInfo;

  /** **DEPRECATED** The metadata sent to the CDN live client defined by the
   * RTMP or HTTP-FLV metadata.
   */
  const char *metadata;
  /** The watermark image added to the CDN live publishing stream.

  Ensure that the format of the image is PNG. Once a watermark image is added,
  the audience of the CDN live publishing stream can see the watermark image.
  See RtcImage.
  */
  struct RtcImage *watermark;
  /** The background image added to the CDN live publishing stream.

   Once a background image is added, the audience of the CDN live publishing
   stream can see the background image. See RtcImage.
  */
  struct RtcImage *backgroundImage;
  /** Self-defined audio-sample rate: #AUDIO_SAMPLE_RATE_TYPE.
   */
  enum AUDIO_SAMPLE_RATE_TYPE audioSampleRate;
  /** Bitrate of the CDN live audio output stream. The default value is 48 Kbps,
   * and the highest value is 128.
   */
  int audioBitrate;
  /** The numbder of audio channels for the CDN live stream. Agora recommends
   choosing 1 (mono), or 2 (stereo) audio channels. Special players are required
   if you choose option 3, 4, or 5:

   - 1: (Default) Mono.
   - 2: Stereo.
   - 3: Three audio channels.
   - 4: Four audio channels.
   - 5: Five audio channels.
   */
  int audioChannels;
  /** Self-defined audio codec profile: #AUDIO_CODEC_PROFILE_TYPE.
   */

  enum AUDIO_CODEC_PROFILE_TYPE audioCodecProfile;

  /** Advanced features of the RTMP streaming with transcoding. See
   * LiveStreamAdvancedFeature.
   *
   * @since v3.1.0
   */
  struct LiveStreamAdvancedFeature *advancedFeatures;

  /** The number of enabled advanced features. The default value is 0. */
  unsigned int advancedFeatureCount;
} LiveTranscoding;

/** Camera capturer configuration.
 */
struct CameraCapturerConfiguration {

  /** Camera capturer preference settings. See: #CAPTURER_OUTPUT_PREFERENCE. */
  enum CAPTURER_OUTPUT_PREFERENCE preference;
#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
  /** Camera direction settings (for Android/iOS only). See: #CAMERA_DIRECTION.
   */
  enum CAMERA_DIRECTION cameraDirection;
#endif
};

/** Configuration of the injected media stream.
 */
struct InjectStreamConfig {
  /** Width of the injected stream in the live interactive streaming. The
   * default value is 0 (same width as the original stream).
   */
  int width;
  /** Height of the injected stream in the live interactive streaming. The
   * default value is 0 (same height as the original stream).
   */
  int height;
  /** Video GOP (in frames) of the injected stream in the live interactive
   * streaming. The default value is 30 fps.
   */
  int videoGop;
  /** Video frame rate of the injected stream in the live interactive streaming.
   * The default value is 15 fps.
   */
  int videoFramerate;
  /** Video bitrate of the injected stream in the live interactive streaming.
   The default value is 400 Kbps.

   @note The setting of the video bitrate is closely linked to the resolution.
   If the video bitrate you set is beyond a reasonable range, the SDK sets it
   within a reasonable range.
   */
  int videoBitrate;
  /** Audio-sample rate of the injected stream in the live interactive
   streaming: #AUDIO_SAMPLE_RATE_TYPE. The default value is 48000 Hz.

   @note We recommend setting the default value.
   */
  enum AUDIO_SAMPLE_RATE_TYPE audioSampleRate;
  /** Audio bitrate of the injected stream in the live interactive streaming.
   The default value is 48.

   @note We recommend setting the default value.
   */
  int audioBitrate;
  /** Audio channels in the live interactive streaming.

   - 1: (Default) Mono
   - 2: Two-channel stereo

   @note We recommend setting the default value.
   */
  int audioChannels;
};
/** The definition of ChannelMediaInfo.
 */
struct ChannelMediaInfo {
  /** The channel name.
   */
  const char *channelName;
  /** The token that enables the user to join the channel.
   */
  const char *token;
  /** The user ID.
   */
  uid_t uid;
};

/** The definition of ChannelMediaRelayConfiguration.
 */
struct ChannelMediaRelayConfiguration {
  /** Pointer to the information of the source channel: ChannelMediaInfo. It
   * contains the following members:
   * - `channelName`: The name of the source channel. The default value is
   * `NULL`, which means the SDK applies the name of the current channel.
   * - `uid`: ID of the host whose media stream you want to relay. The default
   * value is 0, which means the SDK generates a random UID. You must set it as
   * 0.
   * - `token`: The token for joining the source channel. It is generated with
   * the `channelName` and `uid` you set in `srcInfo`.
   *   - If you have not enabled the App Certificate, set this parameter as the
   * default value `NULL`, which means the SDK applies the App ID.
   *   - If you have enabled the App Certificate, you must use the `token`
   * generated with the `channelName` and `uid`, and the `uid` must be set as 0.
   */
  struct ChannelMediaInfo *srcInfo;
  /** Pointer to the information of the destination channel: ChannelMediaInfo.
   * It contains the following members:
   * - `channelName`: The name of the destination channel.
   * - `uid`: ID of the host in the destination channel. The value ranges from 0
   * to (2<sup>32</sup>-1). To avoid UID conflicts, this `uid` must be different
   * from any other UIDs in the destination channel. The default value is 0,
   * which means the SDK generates a random UID.
   * - `token`: The token for joining the destination channel. It is generated
   * with the `channelName` and `uid` you set in `destInfos`.
   *   - If you have not enabled the App Certificate, set this parameter as the
   * default value `NULL`, which means the SDK applies the App ID.
   *   - If you have enabled the App Certificate, you must use the `token`
   * generated with the `channelName` and `uid`.
   */
  struct ChannelMediaInfo *destInfos;
  /** The number of destination channels. The default value is 0, and the
   * value range is [0,4). Ensure that the value of this parameter
   * corresponds to the number of ChannelMediaInfo structs you define in
   * `destInfos`.
   */
  int destCount;
};

/**  **DEPRECATED** Lifecycle of the CDN live video stream.
 */
enum RTMP_STREAM_LIFE_CYCLE_TYPE {
  /** Bind to the channel lifecycle. If all hosts leave the channel, the CDN
   * live streaming stops after 30 seconds.
   */
  RTMP_STREAM_LIFE_CYCLE_BIND2CHANNEL = 1,
  /** Bind to the owner of the RTMP stream. If the owner leaves the channel, the
   * CDN live streaming stops immediately.
   */
  RTMP_STREAM_LIFE_CYCLE_BIND2OWNER = 2,
};

/** Content hints for screen sharing.
 */
enum VideoContentHint {
  /** (Default) No content hint.
   */
  CONTENT_HINT_NONE = 0,
  /** Motion-intensive content. Choose this option if you prefer smoothness or
   * when you are sharing a video clip, movie, or video game.
   */
  CONTENT_HINT_MOTION = 1,
  /** Motionless content. Choose this option if you prefer sharpness or when you
   * are sharing a picture, PowerPoint slide, or text.
   */
  CONTENT_HINT_DETAILS = 2
};

/** The relative location of the region to the screen or window.
 */
struct Rectangle {
  /** The horizontal offset from the top-left corner.
   */
  int x;
  /** The vertical offset from the top-left corner.
   */
  int y;
  /** The width of the region.
   */
  int width;
  /** The height of the region.
   */
  int height;
};

/**  **DEPRECATED** Definition of the rectangular region. */
typedef struct Rect {
  /** Y-axis of the top line.
   */
  int top;
  /** X-axis of the left line.
   */
  int left;
  /** Y-axis of the bottom line.
   */
  int bottom;
  /** X-axis of the right line.
   */
  int right;
} Rect;

/** The options of the watermark image to be added. */
typedef struct WatermarkOptions {
  /** Sets whether or not the watermark image is visible in the local video
   * preview:
   * - true: (Default) The watermark image is visible in preview.
   * - false: The watermark image is not visible in preview.
   */
  BOOL visibleInPreview;
  /**
   * The watermark position in the landscape mode. See Rectangle.
   * For detailed information on the landscape mode, see the advanced guide
   * *Video Rotation*.
   */
  struct Rectangle positionInLandscapeMode;
  /**
   * The watermark position in the portrait mode. See Rectangle.
   * For detailed information on the portrait mode, see the advanced guide
   * *Video Rotation*.
   */
  struct Rectangle positionInPortraitMode;
} WatermarkOptions;

/** Screen sharing encoding parameters.
 */
struct ScreenCaptureParameters {
  /** The maximum encoding dimensions of the shared region in terms of width *
   height.

   The default value is 1920 * 1080 pixels, that is, 2073600 pixels. Agora uses
   the value of this parameter to calculate the charges.

   If the aspect ratio is different between the encoding dimensions and screen
   dimensions, Agora applies the following algorithms for encoding. Suppose the
   encoding dimensions are 1920 x 1080:

   - If the value of the screen dimensions is lower than that of the encoding
   dimensions, for example, 1000 * 1000, the SDK uses 1000 * 1000 for encoding.
   - If the value of the screen dimensions is higher than that of the encoding
   dimensions, for example, 2000 * 1500, the SDK uses the maximum value under
   1920 * 1080 with the aspect ratio of the screen dimension (4:3) for encoding,
   that is, 1440 * 1080.
   */
  struct VideoDimensions dimensions;
  /** The frame rate (fps) of the shared region.

  The default value is 5. We do not recommend setting this to a value greater
  than 15.
   */
  int frameRate;
  /** The bitrate (Kbps) of the shared region.

  The default value is 0 (the SDK works out a bitrate according to the
  dimensions of the current screen).
   */
  int bitrate;
  /** Sets whether or not to capture the mouse for screen sharing:

  - true: (Default) Capture the mouse.
  - false: Do not capture the mouse.
   */
  BOOL captureMouseCursor;
  /** Whether to bring the window to the front when calling \ref
   * IRtcEngine::startScreenCaptureByWindowId "startScreenCaptureByWindowId" to
   * share the window:
   * - true: Bring the window to the front.
   * - false: (Default) Do not bring the window to the front.
   */
  BOOL windowFocus;
  /** A list of IDs of windows to be blocked.
   *
   * When calling \ref IRtcEngine::startScreenCaptureByScreenRect
   * "startScreenCaptureByScreenRect" to start screen sharing, you can use this
   * parameter to block the specified windows. When calling \ref
   * IRtcEngine::updateScreenCaptureParameters "updateScreenCaptureParameters"
   * to update the configuration for screen sharing, you can use this parameter
   * to dynamically block the specified windows during screen sharing.
   */
  view_t *excludeWindowList;
  /** The number of windows to be blocked.
   */
  int excludeWindowCount;
};

/** Video display settings of the VideoCanvas class.
 */
struct VideoCanvas {
  /** Video display window (view).
   */
  view_t view;
  /** The rendering mode of the video view. See RENDER_MODE_TYPE
   */
  int renderMode;
  /** The unique channel name for the AgoraRTC session in the string format. The
   string length must be less than 64 bytes. Supported character scopes are:
   - All lowercase English letters: a to z.
   - All uppercase English letters: A to Z.
   - All numeric characters: 0 to 9.
   - The space character.
   - Punctuation characters and other symbols, including: "!", "#", "$", "%",
   "&", "(", ")", "+", "-", ":", ";", "<", "=", ".", ">", "?", "@", "[", "]",
   "^", "_", " {", "}", "|", "~", ",".

   @note
   - The default value is the empty string "". Use the default value if the user
   joins the channel using the \ref IRtcEngine::joinChannel "joinChannel" method
   in the IRtcEngine class. The `VideoCanvas` struct defines the video canvas of
   the user in the channel.
   - If the user joins the channel using the \ref IRtcEngine::joinChannel
   "joinChannel" method in the IChannel class, set this parameter as the
   `channelId` of the `IChannel` object. The `VideoCanvas` struct defines the
   video canvas of the user in the channel with the specified channel ID.
   */
  char channelId[MAX_CHANNEL_ID_LENGTH];
  /** The user ID. */
  uid_t uid;
  void *priv; // private data (underlying video engine denotes it)
  /** The mirror mode of the video view. See VIDEO_MIRROR_MODE_TYPE
   @note
   - For the mirror mode of the local video view: If you use a front camera, the
   SDK enables the mirror mode by default; if you use a rear camera, the SDK
   disables the mirror mode by default.
   - For the mirror mode of the remote video view: The SDK disables the mirror
   mode by default.
  */
  enum VIDEO_MIRROR_MODE_TYPE mirrorMode;
};

/** Image enhancement options.
 */
struct BeautyOptions {
  /** The contrast level, used with the @p lightening parameter.
   */
  enum LIGHTENING_CONTRAST_LEVEL {
    /** Low contrast level. */
    LIGHTENING_CONTRAST_LOW = 0,
    /** (Default) Normal contrast level. */
    LIGHTENING_CONTRAST_NORMAL,
    /** High contrast level. */
    LIGHTENING_CONTRAST_HIGH
  };

  /** The contrast level, used with the @p lightening parameter.
   */
  enum LIGHTENING_CONTRAST_LEVEL lighteningContrastLevel;

  /** The brightness level. The value ranges from 0.0 (original) to 1.0. */
  float lighteningLevel;

  /** The sharpness level. The value ranges between 0 (original) and 1. This
   * parameter is usually used to remove blemishes.
   */
  float smoothnessLevel;

  /** The redness level. The value ranges between 0 (original) and 1. This
   * parameter adjusts the red saturation level.
   */
  float rednessLevel;
};

/**
 * The UserInfo struct.
 */
struct UserInfo {
  /**
   * The user ID.
   */
  uid_t uid;
  /**
   * The user account.
   */
  char userAccount[MAX_USER_ACCOUNT_LENGTH];
};

/**
 * IP areas.
 */
enum AREA_CODE {
  /**
   * Mainland China.
   */
  AREA_CODE_CN = (1 << 0),
  /**
   * North America.
   */
  AREA_CODE_NA = (1 << 1),
  /**
   * Europe.
   */
  AREA_CODE_EUR = (1 << 2),
  /**
   * Asia, excluding Mainland China.
   */
  AREA_CODE_AS = (1 << 3),
  /**
   * Japan.
   */
  AREA_CODE_JAPAN = (1 << 4),
  /**
   * India.
   */
  AREA_CODE_INDIA = (1 << 5),
  /**
   * (Default) Global.
   */
  AREA_CODE_GLOBAL = (0xFFFFFFFF)
};

enum ENCRYPTION_CONFIG {
  /**
   * - 1: Force set master key and mode;
   * - 0: Not force set, checking whether encryption plugin exists
   */
  ENCRYPTION_FORCE_SETTING = (1 << 0),
  /**
   * - 1: Force not encrypting packet;
   * - 0: Not force encrypting;
   */
  ENCRYPTION_FORCE_DISABLE_PACKET = (1 << 1)
};

enum AUDIO_FRAME_TYPE {
  /** 0: PCM16. */
  FRAME_TYPE_PCM16 = 0, // PCM 16bit little endian
};
/** Definition of AudioFrame */
struct AudioFrame {
  /** The type of the audio frame. See #AUDIO_FRAME_TYPE
   */
  enum AUDIO_FRAME_TYPE type;
  /** The number of samples per channel in the audio frame.
   */
  int samples; // number of samples for each channel in this frame
  /**The number of bytes per audio sample, which is usually 16-bit (2-byte).
   */
  int bytesPerSample; // number of bytes per sample: 2 for PCM16
  /** The number of audio channels.
   - 1: Mono
   - 2: Stereo (the data is interleaved)
   */
  int channels; // number of channels (data are interleaved if stereo)
  /** The sample rate.
   */
  int samplesPerSec; // sampling rate
  /** The data buffer of the audio frame. When the audio frame uses a stereo
   channel, the data buffer is interleaved. The size of the data buffer is as
   follows: `buffer` = `samples` × `channels` × `bytesPerSample`.
   */
  void *buffer; // data buffer
  /** The timestamp of the external audio frame. You can use this parameter for
   the following purposes:
   - Restore the order of the captured audio frame.
   - Synchronize audio and video frames in video-related scenarios, including
   where external video sources are used.
   */
  long long renderTimeMs;
  /** Reserved parameter.
   */
  int avsync_type;
};

/** The video buffer type.
 */
enum VIDEO_BUFFER_TYPE {
  /** 1: The video buffer in the format of raw data.
   */
  VIDEO_BUFFER_RAW_DATA = 1,
};

/** The video pixel format.
 */
enum VIDEO_PIXEL_FORMAT {
  /** 0: The video pixel format is unknown.
   */
  VIDEO_PIXEL_UNKNOWN = 0,
  /** 1: The video pixel format is I420.
   */
  VIDEO_PIXEL_I420 = 1,
  /** 2: The video pixel format is BGRA.
   */
  VIDEO_PIXEL_BGRA = 2,
  /** 3: The video pixel format is NV21.
   */
  VIDEO_PIXEL_NV21 = 3,
  /** 4: The video pixel format is RGBA.
   */
  VIDEO_PIXEL_RGBA = 4,
  /** 5: The video pixel format is IMC2.
   */
  VIDEO_PIXEL_IMC2 = 5,
  /** 7: The video pixel format is ARGB.
   */
  VIDEO_PIXEL_ARGB = 7,
  /** 8: The video pixel format is NV12.
   */
  VIDEO_PIXEL_NV12 = 8,
  /** 16: The video pixel format is I422.
   */
  VIDEO_PIXEL_I422 = 16,
};

/** The external video frame.
 */
struct ExternalVideoFrame {
  /** The buffer type. See #VIDEO_BUFFER_TYPE
   */
  enum VIDEO_BUFFER_TYPE type;
  /** The pixel format. See #VIDEO_PIXEL_FORMAT
   */
  enum VIDEO_PIXEL_FORMAT format;
  /** The video buffer.
   */
  void *buffer;
  /** Line spacing of the incoming video frame, which must be in pixels instead
   * of bytes. For textures, it is the width of the texture.
   */
  int stride;
  /** Height of the incoming video frame.
   */
  int height;
  /** [Raw data related parameter] The number of pixels trimmed from the left.
   * The default value is 0.
   */
  int cropLeft;
  /** [Raw data related parameter] The number of pixels trimmed from the top.
   * The default value is 0.
   */
  int cropTop;
  /** [Raw data related parameter] The number of pixels trimmed from the right.
   * The default value is 0.
   */
  int cropRight;
  /** [Raw data related parameter] The number of pixels trimmed from the bottom.
   * The default value is 0.
   */
  int cropBottom;
  /** [Raw data related parameter] The clockwise rotation of the video frame.
   * You can set the rotation angle as 0, 90, 180, or 270. The default value is
   * 0.
   */
  int rotation;
  /** Timestamp of the incoming video frame (ms). An incorrect timestamp results
   * in frame loss or unsynchronized audio and video.
   */
  long long timestamp;
};

enum MEDIA_SOURCE_TYPE {
  /** Audio playback device.
   */
  AUDIO_PLAYOUT_SOURCE = 0,
  /** Microphone.
   */
  AUDIO_RECORDING_SOURCE = 1,
};

struct ChannelMediaOptions {
  /** Determines whether to subscribe to audio streams when the user joins the
   channel:
   - true: (Default) Subscribe.
   - false: Do not subscribe.

   This member serves a similar function to the \ref
   agora::rtc::IChannel::muteAllRemoteAudioStreams "muteAllRemoteAudioStreams"
   method. After joining the channel, you can call the
   `muteAllRemoteAudioStreams` method to set whether to subscribe to audio
   streams in the channel.
   */
  BOOL autoSubscribeAudio;
  /** Determines whether to subscribe to video streams when the user joins the
   channel:
   - true: (Default) Subscribe.
   - false: Do not subscribe.

   This member serves a similar function to the \ref
   agora::rtc::IChannel::muteAllRemoteVideoStreams "muteAllRemoteVideoStreams"
   method. After joining the channel, you can call the
   `muteAllRemoteVideoStreams` method to set whether to subscribe to video
   streams in the channel.
   */
  BOOL autoSubscribeVideo;
};

/** Encryption mode.
 */
enum ENCRYPTION_MODE {
  /** 1: (Default) 128-bit AES encryption, XTS mode.
   */
  AES_128_XTS = 1,
  /** 2: 128-bit AES encryption, ECB mode.
   */
  AES_128_ECB = 2,
  /** 3: 256-bit AES encryption, XTS mode.
   */
  AES_256_XTS = 3,
  /** 4: 128-bit SM4 encryption, ECB mode.
   */
  SM4_128_ECB = 4,
  /** Enumerator boundary.
   */
  MODE_END,
};

/** Configurations of built-in encryption schemas. */
struct EncryptionConfig {
  /**
   * Encryption mode. The default encryption mode is `AES_128_XTS`. See
   * #ENCRYPTION_MODE.
   */
  enum ENCRYPTION_MODE encryptionMode;
  /**
   * Encryption key in string type.
   *
   * @note If you do not set an encryption key or set it as NULL, you cannot use
   * the built-in encryption, and the SDK returns #ERR_INVALID_ARGUMENT (-2).
   */
  const char *encryptionKey;
};

#if defined(_WIN32)
typedef void(__stdcall *FUNC_OnChannelWarning)(const char *channelId, int warn,
                                               const char *msg);
typedef void(__stdcall *FUNC_OnChannelError)(const char *channelId, int err,
                                             const char *msg);
typedef void(__stdcall *FUNC_OnChannelJoinChannelSuccess)(const char *channelId,
                                                          uid_t uid,
                                                          int elapsed);
typedef void(__stdcall *FUNC_OnChannelReJoinChannelSuccess)(
    const char *channelId, uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnChannelLeaveChannel)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnChannelClientRoleChanged)(const char *channelId,
                                                         int oldRole,
                                                         int newRole);
typedef void(__stdcall *FUNC_OnChannelUserJoined)(const char *channelId,
                                                  uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnChannelUserOffLine)(const char *channelId,
                                                   uid_t uid, int reason);
typedef void(__stdcall *FUNC_OnChannelConnectionLost)(const char *channelId);
typedef void(__stdcall *FUNC_OnChannelRequestToken)(const char *channelId);
typedef void(__stdcall *FUNC_OnChannelTokenPrivilegeWillExpire)(
    const char *channelId, const char *token);
typedef void(__stdcall *FUNC_OnChannelRtcStats)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnChannelNetworkQuality)(const char *channelId,
                                                      uid_t uid, int txQuality,
                                                      int rxQuality);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStats)(
    const char *channelId, uid_t uid, int delay, int width, int height,
    int receivedBitrate, int decoderOutputFrameRate,
    int rendererOutputFrameRate, int packetLossRate, int rxStreamType,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStats)(
    const char *channelId, uid_t uid, int quality, int networkTransportDelay,
    int jitterBufferDelay, int audioLossRate, int numChannels,
    int receivedSampleRate, int receivedBitrate, int totalFrozenTime,
    int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStateChanged)(
    const char *channelId, uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelActiveSpeaker)(const char *channelId,
                                                     uid_t uid);
typedef void(__stdcall *FUNC_OnChannelVideoSizeChanged)(const char *channelId,
                                                        uid_t uid, int width,
                                                        int height,
                                                        int rotation);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStateChanged)(
    const char *channelId, uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelStreamMessage)(const char *channelId,
                                                     uid_t uid, int streamId,
                                                     const char *data,
                                                     size_t length);
typedef void(__stdcall *FUNC_OnChannelStreamMessageError)(const char *channelId,
                                                          uid_t uid,
                                                          int streamId,
                                                          int code, int missed,
                                                          int cached);
typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged2)(
    const char *channelId, int state, int code);
typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent2)(const char *channelId,
                                                        int code);
typedef void(__stdcall *FUNC_OnChannelRtmpStreamingStateChanged)(
    const char *channelId, const char *url, int state, int errCode);
typedef void(__stdcall *FUNC_OnChannelTranscodingUpdated)(
    const char *channelId);
typedef void(__stdcall *FUNC_OnChannelStreamInjectedStatus)(
    const char *channelId, const char *url, uid_t uid, int status);
typedef void(__stdcall *FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(
    const char *channelId, uid_t uid, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnChannelConnectionStateChanged)(
    const char *channelId, int state, int reason);
typedef void(__stdcall *FUNC_OnFacePositionChanged)(int imageWidth,
                                                    int imageHeight, int x,
                                                    int y, int width,
                                                    int height, int vecDistance,
                                                    int numFaces);
typedef void(__stdcall *FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged)(int state,
                                                              int code);
typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent)(int code);
typedef void(__stdcall *FUNC_OnChannelTestEnd)(const char *channelId);

typedef void(__stdcall *FUNC_OnJoinChannelSuccess)(const char *, uid_t uid,
                                                   int elapsed);
typedef void(__stdcall *FUNC_OnReJoinChannelSuccess)(const char *, uid_t uid,
                                                     int elapsed);
typedef void(__stdcall *FUNC_OnConnectionLost)();
typedef void(__stdcall *FUNC_OnConnectionInterrupted)();
typedef void(__stdcall *FUNC_OnLeaveChannel)(
    unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
    unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnRequestToken)();
typedef void(__stdcall *FUNC_OnUserJoined)(uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnUserOffline)(uid_t uid, int offLineReason);
typedef void(__stdcall *FUNC_OnAudioVolumeIndication)(
    uid_t *uid, unsigned int *volume, unsigned int *vad, const char **channelId,
    int speakerNumber, int totalVolume);
typedef void(__stdcall *FUNC_OnUserMuteAudio)(uid_t uid, bool muted);
typedef void(__stdcall *FUNC_OnWarning)(int warn, const char *msg);
typedef void(__stdcall *FUNC_OnError)(int error, const char *msg);
typedef void(__stdcall *FUNC_OnRtcStats)(
    unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
    unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnAudioMixingFinished)();
typedef void(__stdcall *FUNC_OnAudioRouteChanged)(int route);
typedef void(__stdcall *FUNC_OnFirstRemoteVideoDecoded)(uid_t uid, int width,
                                                        int height,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnVideoSizeChanged)(uid_t uid, int width,
                                                 int height, int elapsed);
typedef void(__stdcall *FUNC_OnClientRoleChanged)(int oldRole, int newRole);
typedef void(__stdcall *FUNC_OnUserMuteVideo)(uid_t uid, bool muted);
typedef void(__stdcall *FUNC_OnMicrophoneEnabled)(bool isEnabled);
typedef void(__stdcall *FUNC_OnApiExecuted)(int err, const char *api,
                                            const char *result);
typedef void(__stdcall *FUNC_OnFirstLocalAudioFrame)(int elapsed);
typedef void(__stdcall *FUNC_OnFirstRemoteAudioFrame)(uid_t userId,
                                                      int elapsed);
typedef void(__stdcall *FUNC_OnLastmileQuality)(int quality);
typedef void(__stdcall *FUNC_OnAudioQuality)(uid_t userId, int quality,
                                             unsigned short delay,
                                             unsigned short lost);
typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char *url,
                                                     uid_t userId, int status);
typedef void(__stdcall *FUNC_OnStreamUnpublished)(const char *url);
typedef void(__stdcall *FUNC_OnStreamPublished)(const char *url, int error);
typedef void(__stdcall *FUNC_OnStreamMessageError)(uid_t userId, int streamId,
                                                   int code, int missed,
                                                   int cached);
typedef void(__stdcall *FUNC_OnStreamMessage)(uid_t userId, int streamId,
                                              const char *data, size_t length);
typedef void(__stdcall *FUNC_OnConnectionBanned)();
typedef void(__stdcall *FUNC_OnRemoteVideoTransportStats)(
    uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate);
typedef void(__stdcall *FUNC_OnRemoteAudioTransportStats)(
    uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate);
typedef void(__stdcall *FUNC_OnTranscodingUpdated)();
typedef void(__stdcall *FUNC_OnAudioDeviceVolumeChanged)(int deviceType,
                                                         int volume,
                                                         bool muted);
typedef void(__stdcall *FUNC_OnActiveSpeaker)(uid_t userId);
typedef void(__stdcall *FUNC_OnMediaEngineStartCallSuccess)();
typedef void(__stdcall *FUNC_OnMediaEngineLoadSuccess)();
typedef void(__stdcall *FUNC_OnVideoStopped)();
typedef void(__stdcall *FUNC_OnTokenPrivilegeWillExpire)(const char *token);
typedef void(__stdcall *FUNC_OnNetworkQuality)(uid_t uid, int txQuality,
                                               int rxQuality);
typedef void(__stdcall *FUNC_OnLocalVideoStats)(
    int sentBitrate, int sentFrameRate, int encoderOutputFrameRate,
    int rendererOutputFrameRate, int targetBitrate, int targetFrameRate,
    int qualityAdaptIndication, int encodedBitrate, int encodedFrameWidth,
    int encodedFrameHeight, int encodedFrameCount, int codecType);
typedef void(__stdcall *FUNC_OnRemoteVideoStats)(
    uid_t uid, int delay, int width, int height, int receivedBitrate,
    int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate,
    int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnRemoteAudioStats)(
    uid_t uid, int quality, int networkTransportDelay, int jitterBufferDelay,
    int audioLossRate, int numChannels, int receivedSampleRate,
    int receivedBitrate, int totalFrozenTime, int frozenRate,
    int totalActiveTime);
typedef void(__stdcall *FUNC_OnLocalAudioStats)(int numChannels,
                                                int sentSampleRate,
                                                int sentBitrate);
typedef void(__stdcall *FUNC_OnFirstLocalVideoFrame)(int width, int height,
                                                     int elapsed);
typedef void(__stdcall *FUNC_OnFirstRemoteVideoFrame)(uid_t uid, int width,
                                                      int height, int elapsed);
typedef void(__stdcall *FUNC_OnUserEnableVideo)(uid_t uid, bool enabled);
typedef void(__stdcall *FUNC_OnAudioDeviceStateChanged)(const char *deviceId,
                                                        int deviceType,
                                                        int deviceState);
typedef void(__stdcall *FUNC_OnCameraReady)();
typedef void(__stdcall *FUNC_OnCameraFocusAreaChanged)(int x, int y, int width,
                                                       int height);
typedef void(__stdcall *FUNC_OnCameraExposureAreaChanged)(int x, int y,
                                                          int width,
                                                          int height);
typedef void(__stdcall *FUNC_OnRemoteAudioMixingBegin)();
typedef void(__stdcall *FUNC_OnRemoteAudioMixingEnd)();
typedef void(__stdcall *FUNC_OnAudioEffectFinished)(int soundId);
typedef void(__stdcall *FUNC_OnVideoDeviceStateChanged)(const char *deviceId,
                                                        int deviceType,
                                                        int deviceState);
typedef void(__stdcall *FUNC_OnRemoteVideoStateChanged)(uid_t uid, int state,
                                                        int reason,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnUserEnableLocalVideo)(uid_t uid, bool enabled);
typedef void(__stdcall *FUNC_OnLocalPublishFallbackToAudioOnly)(
    bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnRemoteSubscribeFallbackToAudioOnly)(
    uid_t uid, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnConnectionStateChanged)(int state, int reason);
typedef void(__stdcall *FUNC_OnLocalUserRegistered)(uid_t uid,
                                                    const char *userAccount);
typedef void(__stdcall *FUNC_OnUserInfoUpdated)(uid_t uid, uid_t userId,
                                                char *userAccount);
typedef void(__stdcall *FUNC_OnLocalAudioStateChanged)(int state, int error);
typedef void(__stdcall *FUNC_OnRemoteAudioStateChanged)(uid_t uid, int state,
                                                        int reason,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char *url, uid_t uid,
                                                     int status);
typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged)(int state,
                                                              int code);
typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent)(int code);
typedef void(__stdcall *FUNC_OnFacePositionChanged)(int imageWidth,
                                                    int imageHeight, int x,
                                                    int y, int width,
                                                    int height, int vecDistance,
                                                    int numFaces);
typedef void(__stdcall *FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);

// raw data callback
typedef void(__stdcall *FUNC_OnCaptureVideoFrame)(int videoFrameType, int width,
                                                  int height, int yStride,
                                                  void *yBuffer, int rotation,
                                                  int64_t renderTimeMs);
typedef void(__stdcall *FUNC_OnRenderVideoFrame)(unsigned int uid,
                                                 int videoFrameType, int width,
                                                 int height, int yStride,
                                                 void *yBuffer, int rotation,
                                                 int64_t renderTimeMs);
typedef void(__stdcall *FUNC_OnRecordAudioFrame)(
    int type, int samples, int bytesPerSample, int channels, int samplesPerSec,
    void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void(__stdcall *FUNC_OnPlaybackAudioFrame)(
    int type, int samples, int bytesPerSample, int channels, int samplesPerSec,
    void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void(__stdcall *FUNC_OnPullAudioFrame)(int type, int samples,
                                               int bytesPerSample, int channels,
                                               int samplesPerSec, void *buffer,
                                               int64_t renderTimeMs,
                                               int avsync_type);
typedef void(__stdcall *FUNC_OnMixedAudioFrame)(
    int type, int samples, int bytesPerSample, int channels, int samplesPerSec,
    void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void(__stdcall *FUNC_OnPlaybackAudioFrameBeforeMixing)(
    unsigned int uid, int type, int samples, int bytesPerSample, int channels,
    int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void(__stdcall *FUNC_OnAudioMixingStateChanged)(
    int audioMixingStateType, int audioMixingErrorType);
typedef void(__stdcall *FUNC_OnFirstRemoteAudioDecoded)(uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnLocalVideoStateChanged)(int localVideoState,
                                                       int error);
typedef void(__stdcall *FUNC_OnRtmpStreamingStateChanged)(const char *url,
                                                          int state,
                                                          int errCode);
typedef void(__stdcall *FUNC_OnNetworkTypeChanged)(int networkType);
typedef void(__stdcall *FUNC_OnLastmileProbeResult)(
    int state, unsigned int upLinkPacketLossRate, unsigned int upLinkjitter,
    unsigned int upLinkAvailableBandwidth, unsigned int downLinkPacketLossRate,
    unsigned int downLinkJitter, unsigned int downLinkAvailableBandwidth,
    unsigned int rtt);
typedef bool(__stdcall *FUNC_OnSendAudioPacket)(const unsigned char *buffer,
                                                void *size);
typedef bool(__stdcall *FUNC_OnSendVideoPacket)(const unsigned char *buffer,
                                                void *size);
typedef bool(__stdcall *FUNC_OnReceiveAudioPacket)(const unsigned char *buffer,
                                                   void *size);
typedef bool(__stdcall *FUNC_OnReceiveVideoPacket)(const unsigned char *buffer,
                                                   void *size);
typedef bool(__stdcall *FUNC_OnReadyToSendMetadata)();
typedef void(__stdcall *FUNC_OnMetadataReceived)(unsigned int uid,
                                                 unsigned int size,
                                                 unsigned char *buffer,
                                                 long long timeStampMs);
typedef int(__stdcall *FUNC_OnGetMaxMetadataSize)();
typedef void(__stdcall *FUNC_OnChannelWarning)(const char *channelId, int warn,
                                               const char *msg);
typedef void(__stdcall *FUNC_OnChannelError)(const char *channelId, int err,
                                             const char *msg);
typedef void(__stdcall *FUNC_OnChannelJoinChannelSuccess)(const char *channelId,
                                                          uid_t uid,
                                                          int elapsed);
typedef void(__stdcall *FUNC_OnChannelReJoinChannelSuccess)(
    const char *channelId, uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnChannelLeaveChannel)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnChannelClientRoleChanged)(const char *channelId,
                                                         int oldRole,
                                                         int newRole);
typedef void(__stdcall *FUNC_OnChannelUserJoined)(const char *channelId,
                                                  uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnChannelUserOffLine)(const char *channelId,
                                                   uid_t uid, int reason);
typedef void(__stdcall *FUNC_OnChannelConnectionLost)(const char *channelId);
typedef void(__stdcall *FUNC_OnChannelRequestToken)(const char *channelId);
typedef void(__stdcall *FUNC_OnChannelTokenPrivilegeWillExpire)(
    const char *channelId, const char *token);
typedef void(__stdcall *FUNC_OnChannelRtcStats)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnChannelNetworkQuality)(const char *channelId,
                                                      uid_t uid, int txQuality,
                                                      int rxQuality);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStats)(
    const char *channelId, uid_t uid, int delay, int width, int height,
    int receivedBitrate, int decoderOutputFrameRate,
    int rendererOutputFrameRate, int packetLossRate, int rxStreamType,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStats)(
    const char *channelId, uid_t uid, int quality, int networkTransportDelay,
    int jitterBufferDelay, int audioLossRate, int numChannels,
    int receivedSampleRate, int receivedBitrate, int totalFrozenTime,
    int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStateChanged)(
    const char *channelId, uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelActiveSpeaker)(const char *channelId,
                                                     uid_t uid);
typedef void(__stdcall *FUNC_OnChannelVideoSizeChanged)(const char *channelId,
                                                        uid_t uid, int width,
                                                        int height,
                                                        int rotation);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStateChanged)(
    const char *channelId, uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelStreamMessage)(const char *channelId,
                                                     uid_t uid, int streamId,
                                                     const char *data,
                                                     size_t length);
typedef void(__stdcall *FUNC_OnChannelStreamMessageError)(const char *channelId,
                                                          uid_t uid,
                                                          int streamId,
                                                          int code, int missed,
                                                          int cached);
typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged2)(
    const char *channelId, int state, int code);
typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent2)(const char *channelId,
                                                        int code);
typedef void(__stdcall *FUNC_OnChannelRtmpStreamingStateChanged)(
    const char *channelId, const char *url, int state, int errCode);
typedef void(__stdcall *FUNC_OnChannelTranscodingUpdated)(
    const char *channelId);
typedef void(__stdcall *FUNC_OnChannelStreamInjectedStatus)(
    const char *channelId, const char *url, uid_t uid, int status);
typedef void(__stdcall *FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(
    const char *channelId, uid_t uid, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnChannelConnectionStateChanged)(
    const char *channelId, int state, int reason);
typedef void(__stdcall *FUNC_OnFacePositionChanged)(int imageWidth,
                                                    int imageHeight, int x,
                                                    int y, int width,
                                                    int height, int vecDistance,
                                                    int numFaces);
typedef void(__stdcall *FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnTestEnd)();
#else
typedef void (*FUNC_OnChannelWarning)(const char *channelId, int warn,
                                      const char *msg);
typedef void (*FUNC_OnChannelError)(const char *channelId, int err,
                                    const char *msg);
typedef void (*FUNC_OnChannelJoinChannelSuccess)(const char *channelId,
                                                 uid_t uid, int elapsed);
typedef void (*FUNC_OnChannelReJoinChannelSuccess)(const char *channelId,
                                                   uid_t uid, int elapsed);
typedef void (*FUNC_OnChannelLeaveChannel)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void (*FUNC_OnChannelClientRoleChanged)(const char *channelId,
                                                int oldRole, int newRole);
typedef void (*FUNC_OnChannelUserJoined)(const char *channelId, uid_t uid,
                                         int elapsed);
typedef void (*FUNC_OnChannelUserOffLine)(const char *channelId, uid_t uid,
                                          int reason);
typedef void (*FUNC_OnChannelConnectionLost)(const char *channelId);
typedef void (*FUNC_OnChannelRequestToken)(const char *channelId);
typedef void (*FUNC_OnChannelTokenPrivilegeWillExpire)(const char *channelId,
                                                       const char *token);
typedef void (*FUNC_OnChannelRtcStats)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void (*FUNC_OnChannelNetworkQuality)(const char *channelId, uid_t uid,
                                             int txQuality, int rxQuality);
typedef void (*FUNC_OnChannelRemoteVideoStats)(
    const char *channelId, uid_t uid, int delay, int width, int height,
    int receivedBitrate, int decoderOutputFrameRate,
    int rendererOutputFrameRate, int packetLossRate, int rxStreamType,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnChannelRemoteAudioStats)(
    const char *channelId, uid_t uid, int quality, int networkTransportDelay,
    int jitterBufferDelay, int audioLossRate, int numChannels,
    int receivedSampleRate, int receivedBitrate, int totalFrozenTime,
    int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnChannelRemoteAudioStateChanged)(const char *channelId,
                                                      uid_t uid, int state,
                                                      int reason, int elapsed);
typedef void (*FUNC_OnChannelActiveSpeaker)(const char *channelId, uid_t uid);
typedef void (*FUNC_OnChannelVideoSizeChanged)(const char *channelId, uid_t uid,
                                               int width, int height,
                                               int rotation);
typedef void (*FUNC_OnChannelRemoteVideoStateChanged)(const char *channelId,
                                                      uid_t uid, int state,
                                                      int reason, int elapsed);
typedef void (*FUNC_OnChannelStreamMessage)(const char *channelId, uid_t uid,
                                            int streamId, const char *data,
                                            size_t length);
typedef void (*FUNC_OnChannelStreamMessageError)(const char *channelId,
                                                 uid_t uid, int streamId,
                                                 int code, int missed,
                                                 int cached);
typedef void (*FUNC_OnChannelMediaRelayStateChanged2)(const char *channelId,
                                                      int state, int code);
typedef void (*FUNC_OnChannelMediaRelayEvent2)(const char *channelId, int code);
typedef void (*FUNC_OnChannelRtmpStreamingStateChanged)(const char *channelId,
                                                        const char *url,
                                                        int state, int errCode);
typedef void (*FUNC_OnChannelTranscodingUpdated)(const char *channelId);
typedef void (*FUNC_OnChannelStreamInjectedStatus)(const char *channelId,
                                                   const char *url, uid_t uid,
                                                   int status);
typedef void (*FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(
    const char *channelId, uid_t uid, bool isFallbackOrRecover);
typedef void (*FUNC_OnChannelConnectionStateChanged)(const char *channelId,
                                                     int state, int reason);
typedef void (*FUNC_OnFacePositionChanged)(int imageWidth, int imageHeight,
                                           int x, int y, int width, int height,
                                           int vecDistance, int numFaces);
typedef void (*FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);
typedef void (*FUNC_OnChannelMediaRelayStateChanged)(int state, int code);
typedef void (*FUNC_OnChannelMediaRelayEvent)(int code);
typedef void (*FUNC_OnChannelTestEnd)(const char *channelId);

typedef void (*FUNC_OnJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
typedef void (*FUNC_OnReJoinChannelSuccess)(const char *, uid_t uid,
                                            int elapsed);
typedef void (*FUNC_OnConnectionLost)();
typedef void (*FUNC_OnConnectionInterrupted)();
typedef void (*FUNC_OnLeaveChannel)(
    unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
    unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void (*FUNC_OnRequestToken)();
typedef void (*FUNC_OnUserJoined)(uid_t uid, int elapsed);
typedef void (*FUNC_OnUserOffline)(uid_t uid, int offLineReason);
typedef void (*FUNC_OnAudioVolumeIndication)(uid_t *uid, unsigned int *volume,
                                             unsigned int *vad,
                                             const char **channelId,
                                             int speakerNumber,
                                             int totalVolume);
typedef void (*FUNC_OnUserMuteAudio)(uid_t uid, bool muted);
typedef void (*FUNC_OnWarning)(int warn, const char *msg);
typedef void (*FUNC_OnError)(int error, const char *msg);
typedef void (*FUNC_OnRtcStats)(
    unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
    unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void (*FUNC_OnAudioMixingFinished)();
typedef void (*FUNC_OnAudioRouteChanged)(int route);
typedef void (*FUNC_OnFirstRemoteVideoDecoded)(uid_t uid, int width, int height,
                                               int elapsed);
typedef void (*FUNC_OnVideoSizeChanged)(uid_t uid, int width, int height,
                                        int elapsed);
typedef void (*FUNC_OnClientRoleChanged)(int oldRole, int newRole);
typedef void (*FUNC_OnUserMuteVideo)(uid_t uid, bool muted);
typedef void (*FUNC_OnMicrophoneEnabled)(bool isEnabled);
typedef void (*FUNC_OnApiExecuted)(int err, const char *api,
                                   const char *result);
typedef void (*FUNC_OnFirstLocalAudioFrame)(int elapsed);
typedef void (*FUNC_OnFirstRemoteAudioFrame)(uid_t userId, int elapsed);
typedef void (*FUNC_OnLastmileQuality)(int quality);
typedef void (*FUNC_OnAudioQuality)(uid_t userId, int quality,
                                    unsigned short delay, unsigned short lost);
typedef void (*FUNC_OnStreamInjectedStatus)(const char *url, uid_t userId,
                                            int status);
typedef void (*FUNC_OnStreamUnpublished)(const char *url);
typedef void (*FUNC_OnStreamPublished)(const char *url, int error);
typedef void (*FUNC_OnStreamMessageError)(uid_t userId, int streamId, int code,
                                          int missed, int cached);
typedef void (*FUNC_OnStreamMessage)(uid_t userId, int streamId,
                                     const char *data, size_t length);
typedef void (*FUNC_OnConnectionBanned)();
typedef void (*FUNC_OnRemoteVideoTransportStats)(uid_t uid,
                                                 unsigned short delay,
                                                 unsigned short lost,
                                                 unsigned short rxKBitRate);
typedef void (*FUNC_OnRemoteAudioTransportStats)(uid_t uid,
                                                 unsigned short delay,
                                                 unsigned short lost,
                                                 unsigned short rxKBitRate);
typedef void (*FUNC_OnTranscodingUpdated)();
typedef void (*FUNC_OnAudioDeviceVolumeChanged)(int deviceType, int volume,
                                                bool muted);
typedef void (*FUNC_OnActiveSpeaker)(uid_t userId);
typedef void (*FUNC_OnMediaEngineStartCallSuccess)();
typedef void (*FUNC_OnMediaEngineLoadSuccess)();
typedef void (*FUNC_OnVideoStopped)();
typedef void (*FUNC_OnTokenPrivilegeWillExpire)(const char *token);
typedef void (*FUNC_OnNetworkQuality)(uid_t uid, int txQuality, int rxQuality);
typedef void (*FUNC_OnLocalVideoStats)(
    int sentBitrate, int sentFrameRate, int encoderOutputFrameRate,
    int rendererOutputFrameRate, int targetBitrate, int targetFrameRate,
    int qualityAdaptIndication, int encodedBitrate, int encodedFrameWidth,
    int encodedFrameHeight, int encodedFrameCount, int codecType);
typedef void (*FUNC_OnRemoteVideoStats)(
    uid_t uid, int delay, int width, int height, int receivedBitrate,
    int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate,
    int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnRemoteAudioStats)(
    uid_t uid, int quality, int networkTransportDelay, int jitterBufferDelay,
    int audioLossRate, int numChannels, int receivedSampleRate,
    int receivedBitrate, int totalFrozenTime, int frozenRate,
    int totalActiveTime);
typedef void (*FUNC_OnLocalAudioStats)(int numChannels, int sentSampleRate,
                                       int sentBitrate);
typedef void (*FUNC_OnFirstLocalVideoFrame)(int width, int height, int elapsed);
typedef void (*FUNC_OnFirstRemoteVideoFrame)(uid_t uid, int width, int height,
                                             int elapsed);
typedef void (*FUNC_OnUserEnableVideo)(uid_t uid, bool enabled);
typedef void (*FUNC_OnAudioDeviceStateChanged)(const char *deviceId,
                                               int deviceType, int deviceState);
typedef void (*FUNC_OnCameraReady)();
typedef void (*FUNC_OnCameraFocusAreaChanged)(int x, int y, int width,
                                              int height);
typedef void (*FUNC_OnCameraExposureAreaChanged)(int x, int y, int width,
                                                 int height);
typedef void (*FUNC_OnRemoteAudioMixingBegin)();
typedef void (*FUNC_OnRemoteAudioMixingEnd)();
typedef void (*FUNC_OnAudioEffectFinished)(int soundId);
typedef void (*FUNC_OnVideoDeviceStateChanged)(const char *deviceId,
                                               int deviceType, int deviceState);
typedef void (*FUNC_OnRemoteVideoStateChanged)(uid_t uid, int state, int reason,
                                               int elapsed);
typedef void (*FUNC_OnUserEnableLocalVideo)(uid_t uid, bool enabled);
typedef void (*FUNC_OnLocalPublishFallbackToAudioOnly)(
    bool isFallbackOrRecover);
typedef void (*FUNC_OnRemoteSubscribeFallbackToAudioOnly)(
    uid_t uid, bool isFallbackOrRecover);
typedef void (*FUNC_OnConnectionStateChanged)(int state, int reason);
typedef void (*FUNC_OnRtmpStreamingStateChanged)(const char *url, int state,
                                                 int errCode);
typedef void (*FUNC_OnLocalUserRegistered)(uid_t uid, const char *userAccount);
typedef void (*FUNC_OnUserInfoUpdated)(uid_t uid, uid_t userUid,
                                       char *userAccount);
typedef void (*FUNC_OnLocalAudioStateChanged)(int state, int error);
typedef void (*FUNC_OnRemoteAudioStateChanged)(uid_t uid, int state, int reason,
                                               int elapsed);
typedef void (*FUNC_OnStreamInjectedStatus)(const char *url, uid_t uid,
                                            int status);
typedef void (*FUNC_OnChannelMediaRelayStateChanged)(int state, int code);
typedef void (*FUNC_OnChannelMediaRelayEvent)(int code);
typedef void (*FUNC_OnFacePositionChanged)(int imageWidth, int imageHeight,
                                           int x, int y, int width, int height,
                                           int vecDistance, int numFaces);
typedef void (*FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);

// raw data callback
typedef void (*FUNC_OnCaptureVideoFrame)(int videoFrameType, int width,
                                         int height, int yStride, void *yBuffer,
                                         int rotation, int64_t renderTimeMs);
typedef void (*FUNC_OnRenderVideoFrame)(unsigned int uid, int videoFrameType,
                                        int width, int height, int yStride,
                                        void *yBuffer, int rotation,
                                        int64_t renderTimeMs);
typedef void (*FUNC_OnRecordAudioFrame)(int type, int samples,
                                        int bytesPerSample, int channels,
                                        int samplesPerSec, void *buffer,
                                        int64_t renderTimeMs, int avsync_type);
typedef void (*FUNC_OnPlaybackAudioFrame)(int type, int samples,
                                          int bytesPerSample, int channels,
                                          int samplesPerSec, void *buffer,
                                          int64_t renderTimeMs,
                                          int avsync_type);
typedef void (*FUNC_OnMixedAudioFrame)(int type, int samples,
                                       int bytesPerSample, int channels,
                                       int samplesPerSec, void *buffer,
                                       int64_t renderTimeMs, int avsync_type);
typedef void (*FUNC_OnPlaybackAudioFrameBeforeMixing)(
    unsigned int uid, int type, int samples, int bytesPerSample, int channels,
    int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void (*FUNC_OnPullAudioFrame)(int type, int samples, int bytesPerSample,
                                      int channels, int samplesPerSec,
                                      void *buffer, int64_t renderTimeMs,
                                      int avsync_type);
typedef void (*FUNC_OnAudioMixingStateChanged)(int audioMixingStateType,
                                               int audioMixingErrorType);
typedef void (*FUNC_OnFirstRemoteAudioDecoded)(uid_t uid, int elapsed);
typedef void (*FUNC_OnLocalVideoStateChanged)(int localVideoState, int error);
typedef void (*FUNC_OnNetworkTypeChanged)(int networkType);
typedef void (*FUNC_OnLastmileProbeResult)(
    int state, unsigned int upLinkPacketLossRate, unsigned int upLinkjitter,
    unsigned int upLinkAvailableBandwidth, unsigned int downLinkPacketLossRate,
    unsigned int downLinkJitter, unsigned int downLinkAvailableBandwidth,
    unsigned int rtt);
typedef bool (*FUNC_OnSendAudioPacket)(const unsigned char *buffer, void *size);
typedef bool (*FUNC_OnSendVideoPacket)(const unsigned char *buffer, void *size);
typedef bool (*FUNC_OnReceiveAudioPacket)(const unsigned char *buffer,
                                          void *size);
typedef bool (*FUNC_OnReceiveVideoPacket)(const unsigned char *buffer,
                                          void *size);
typedef bool (*FUNC_OnReadyToSendMetadata)();
typedef void (*FUNC_OnMetadataReceived)(unsigned int uid, unsigned int size,
                                        unsigned char *buffer,
                                        long long timeStampMs);
typedef int (*FUNC_OnGetMaxMetadataSize)();
typedef void (*FUNC_OnTestEnd)();
#endif

struct RtcEventHandler {
  FUNC_OnJoinChannelSuccess onJoinChannelSuccess = NULL;
  FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess = NULL;
  FUNC_OnLeaveChannel onLeaveChannel = NULL;
  FUNC_OnConnectionLost onConnectionLost = NULL;
  FUNC_OnConnectionInterrupted onConnectionInterrupted = NULL;
  FUNC_OnRequestToken onRequestToken = NULL;
  FUNC_OnUserJoined onUserJoined = NULL;
  FUNC_OnUserOffline onUserOffline = NULL;
  FUNC_OnAudioVolumeIndication onAudioVolumeIndication = NULL;
  FUNC_OnUserMuteAudio onUserMuteAudio = NULL;
  FUNC_OnWarning onWarning = NULL;
  FUNC_OnError onError = NULL;
  FUNC_OnRtcStats onRtcStats = NULL;
  FUNC_OnAudioMixingFinished onAudioMixingFinished = NULL;
  FUNC_OnAudioRouteChanged onAudioRouteChanged = NULL;
  FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded = NULL;
  FUNC_OnVideoSizeChanged onVideoSizeChanged = NULL;
  FUNC_OnClientRoleChanged onClientRoleChanged = NULL;
  FUNC_OnUserMuteVideo onUserMuteVideo = NULL;
  FUNC_OnMicrophoneEnabled onMicrophoneEnabled = NULL;
  FUNC_OnApiExecuted onApiCallExecuted = NULL;
  FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame = NULL;
  FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame = NULL;
  FUNC_OnLastmileQuality onLastmileQuality = NULL;
  FUNC_OnAudioQuality onAudioQuality = NULL;
  FUNC_OnStreamInjectedStatus onStreamInjectedStatus = NULL;
  FUNC_OnStreamUnpublished onStreamUnpublished = NULL;
  FUNC_OnStreamPublished onStreamPublished = NULL;
  FUNC_OnStreamMessageError onStreamMessageError = NULL;
  FUNC_OnStreamMessage onStreamMessage = NULL;
  FUNC_OnConnectionBanned onConnectionBanned = NULL;
  FUNC_OnRemoteVideoTransportStats onRemoteVideoTransportStats = NULL;
  FUNC_OnRemoteAudioTransportStats onRemoteAudioTransportStats = NULL;
  FUNC_OnTranscodingUpdated onTranscodingUpdated = NULL;
  FUNC_OnAudioDeviceVolumeChanged onAudioDeviceVolumeChanged = NULL;
  FUNC_OnActiveSpeaker onActiveSpeaker = NULL;
  FUNC_OnMediaEngineStartCallSuccess onMediaEngineStartCallSuccess = NULL;
  FUNC_OnMediaEngineLoadSuccess onMediaEngineLoadSuccess = NULL;
  FUNC_OnConnectionStateChanged onConnectionStateChanged = NULL;
  FUNC_OnRemoteSubscribeFallbackToAudioOnly
      onRemoteSubscribeFallbackToAudioOnly = NULL;
  FUNC_OnLocalPublishFallbackToAudioOnly onLocalPublishFallbackToAudioOnly =
      NULL;
  FUNC_OnUserEnableLocalVideo onUserEnableLocalVideo = NULL;
  FUNC_OnRemoteVideoStateChanged onRemoteVideoStateChanged = NULL;
  FUNC_OnVideoDeviceStateChanged onVideoDeviceStateChanged = NULL;
  FUNC_OnAudioEffectFinished onAudioEffectFinished = NULL;
  FUNC_OnRemoteAudioMixingEnd onRemoteAudioMixingEnd = NULL;
  FUNC_OnRemoteAudioMixingBegin onRemoteAudioMixingBegin = NULL;
  FUNC_OnCameraExposureAreaChanged onCameraExposureAreaChanged = NULL;
  FUNC_OnCameraFocusAreaChanged onCameraFocusAreaChanged = NULL;
  FUNC_OnCameraReady onCameraReady = NULL;
  FUNC_OnAudioDeviceStateChanged onAudioDeviceStateChanged = NULL;
  FUNC_OnUserEnableVideo onUserEnableVideo = NULL;
  FUNC_OnFirstRemoteVideoFrame onFirstRemoteVideoFrame = NULL;
  FUNC_OnFirstLocalVideoFrame onFirstLocalVideoFrame = NULL;
  FUNC_OnRemoteAudioStats onRemoteAudioStats = NULL;
  FUNC_OnRemoteVideoStats onRemoteVideoStats = NULL;
  FUNC_OnLocalVideoStats onLocalVideoStats = NULL;
  FUNC_OnNetworkQuality onNetworkQuality = NULL;
  FUNC_OnTokenPrivilegeWillExpire onTokenPrivilegeWillExpire = NULL;
  FUNC_OnVideoStopped onVideoStopped = NULL;
  FUNC_OnAudioMixingStateChanged onAudioMixingStateChanged = NULL;
  FUNC_OnFirstRemoteAudioDecoded onFirstRemoteAudioDecoded = NULL;
  FUNC_OnLocalVideoStateChanged onLocalVideoStateChanged = NULL;
  FUNC_OnNetworkTypeChanged onNetworkTypeChanged = NULL;
  FUNC_OnRtmpStreamingStateChanged onRtmpStreamingStateChanged = NULL;
  FUNC_OnLastmileProbeResult onLastmileProbeResult = NULL;
  FUNC_OnLocalUserRegistered onLocalUserRegistered = NULL;
  FUNC_OnUserInfoUpdated onUserInfoUpdated = NULL;
  FUNC_OnLocalAudioStateChanged onLocalAudioStateChanged = NULL;
  FUNC_OnRemoteAudioStateChanged onRemoteAudioStateChanged = NULL;
  FUNC_OnLocalAudioStats onLocalAudioStats = NULL;
  FUNC_OnChannelMediaRelayStateChanged onChannelMediaRelayStateChanged = NULL;
  FUNC_OnChannelMediaRelayEvent onChannelMediaRelayEvent = NULL;
  FUNC_OnFacePositionChanged onFacePositionChanged = NULL;
  FUNC_OnTestEnd onTestEnd = NULL;
};

struct ChannelEventHandler {
  FUNC_OnChannelWarning onWarning = NULL;
  FUNC_OnChannelError onError = NULL;
  FUNC_OnChannelJoinChannelSuccess onJoinChannelSuccess = NULL;
  FUNC_OnChannelReJoinChannelSuccess onRejoinChannelSuccess = NULL;
  FUNC_OnChannelLeaveChannel onLeaveChannel = NULL;
  FUNC_OnChannelClientRoleChanged onClientRoleChanged = NULL;
  FUNC_OnChannelUserJoined onUserJoined = NULL;
  FUNC_OnChannelUserOffLine onUserOffLine = NULL;
  FUNC_OnChannelConnectionLost onConnectionLost = NULL;
  FUNC_OnChannelRequestToken onRequestToken = NULL;
  FUNC_OnChannelTokenPrivilegeWillExpire onTokenPrivilegeWillExpire = NULL;
  FUNC_OnChannelRtcStats onRtcStats = NULL;
  FUNC_OnChannelNetworkQuality onNetworkQuality = NULL;
  FUNC_OnChannelRemoteVideoStats onRemoteVideoStats = NULL;
  FUNC_OnChannelRemoteAudioStats onRemoteAudioStats = NULL;
  FUNC_OnChannelRemoteAudioStateChanged onRemoteAudioStateChanged = NULL;
  FUNC_OnChannelActiveSpeaker onActiveSpeaker = NULL;
  FUNC_OnChannelVideoSizeChanged onVideoSizeChanged = NULL;
  FUNC_OnChannelRemoteVideoStateChanged onRemoteVideoStateChanged = NULL;
  FUNC_OnChannelStreamMessage onStreamMessage = NULL;
  FUNC_OnChannelStreamMessageError onStreamMessageError = NULL;
  FUNC_OnChannelMediaRelayStateChanged2 onMediaRelayStateChanged = NULL;
  FUNC_OnChannelMediaRelayEvent2 onMediaRelayEvent = NULL;
  FUNC_OnChannelRtmpStreamingStateChanged onRtmpStreamingStateChanged = NULL;
  FUNC_OnChannelTranscodingUpdated onTranscodingUpdated = NULL;
  FUNC_OnChannelStreamInjectedStatus onStreamInjectedStatus = NULL;
  FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly
      onRemoteSubscribeFallbackToAudioOnly = NULL;
  FUNC_OnChannelConnectionStateChanged onConnectionStateChanged = NULL;
  FUNC_OnChannelLocalPublishFallbackToAudioOnly
      onLocalPublishFallbackToAudioOnly = NULL;
  FUNC_OnChannelTestEnd onTestEnd = NULL;
};

typedef void *IRtcEngineBridge_ptr;
typedef void *IRtcChannelBridge_ptr;
typedef void *IVideoDeviceManager_ptr;
typedef void *IAudioPlaybackDeviceManager_ptr;
typedef void *IAudioRecordingDeviceManager_ptr;

extern IRtcEngineBridge_ptr createRtcBridge();

extern void release(IRtcEngineBridge_ptr apiBridge, BOOL sync);

extern IRtcChannelBridge_ptr createChannel(IRtcEngineBridge_ptr apiBridge,
                                           const char *channelId);

extern void releaseChannel(IRtcChannelBridge_ptr apiBridge);

extern IAudioPlaybackDeviceManager_ptr
createAudioPlaybackDeviceManager(IRtcEngineBridge_ptr apiBridge);

extern void
releaseAudioPlaybackDeviceManager(IAudioPlaybackDeviceManager_ptr apiBridge);

extern IAudioRecordingDeviceManager_ptr
createAudioRecordingDeviceManager(IRtcEngineBridge_ptr apiBridge);

extern void
releaseAudioRecordingDeviceManager(IAudioRecordingDeviceManager_ptr apiBridge);

extern IVideoDeviceManager_ptr
createVideoDeviceManager(IRtcEngineBridge_ptr apiBridge);

extern void releaseVideoDeviceManager(IVideoDeviceManager_ptr apiBridge);

extern enum ERROR_CODE initialize(IRtcEngineBridge_ptr apiBridge,
                                  const char *appId, void *context,
                                  enum AREA_CODE areaCode);

extern void add_C_EventHandler(IRtcEngineBridge_ptr apiBridge,
                               struct RtcEventHandler *handler);

extern void remove_C_EventHandler(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE
setChannelProfile(IRtcEngineBridge_ptr apiBridge,
                  enum CHANNEL_PROFILE_TYPE channel_profile_type);

extern enum ERROR_CODE setClientRole(IRtcEngineBridge_ptr apiBridge,
                                     enum CLIENT_ROLE_TYPE role);

extern enum ERROR_CODE joinChannel(IRtcEngineBridge_ptr apiBridge,
                                   const char *token, const char *channelId,
                                   const char *info, uid_t uid);

extern enum ERROR_CODE switchChannel(IRtcEngineBridge_ptr apiBridge,
                                     const char *token, const char *channelId);

extern enum ERROR_CODE leaveChannel(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE renewToken(IRtcEngineBridge_ptr apiBridge,
                                  const char *token);

extern enum ERROR_CODE registerLocalUserAccount(IRtcEngineBridge_ptr apiBridge,
                                                const char *appId,
                                                const char *userAccount);

extern enum ERROR_CODE
joinChannelWithUserAccount(IRtcEngineBridge_ptr apiBridge, const char *token,
                           const char *channelId, const char *userAccount);

extern enum ERROR_CODE getUserInfoByUserAccount(IRtcEngineBridge_ptr apiBridge,
                                                const char *userAccount,
                                                struct UserInfo *userInfo);

extern enum ERROR_CODE getUserInfoByUid(IRtcEngineBridge_ptr apiBridge,
                                        uid_t uid, struct UserInfo *userInfo);

extern enum ERROR_CODE startEchoTest(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE startEchoTest2(IRtcEngineBridge_ptr apiBridge,
                                      int intervalInSeconds);

extern enum ERROR_CODE stopEchoTest(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE enableVideo(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE disableVideo(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE setVideoProfile(IRtcEngineBridge_ptr apiBridge,
                                       enum VIDEO_PROFILE_TYPE profile,
                                       BOOL swapWidthAndHeight);

extern enum ERROR_CODE
setVideoEncoderConfiguration(IRtcEngineBridge_ptr apiBridge,
                             const struct VideoEncoderConfiguration config);

extern enum ERROR_CODE
setCameraCapturerConfiguration(IRtcEngineBridge_ptr apiBridge,
                               const struct CameraCapturerConfiguration config);

extern enum ERROR_CODE setupLocalVideo(IRtcEngineBridge_ptr apiBridge,
                                       const struct VideoCanvas canvas);

extern enum ERROR_CODE setupRemoteVideo(IRtcEngineBridge_ptr apiBridge,
                                        const struct VideoCanvas canvas);

extern enum ERROR_CODE startPreview(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE setRemoteUserPriority(IRtcEngineBridge_ptr apiBridge,
                                             uid_t uid,
                                             enum PRIORITY_TYPE userPriority);

extern enum ERROR_CODE stopPreview(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE enableAudio(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE enableLocalAudio(IRtcEngineBridge_ptr apiBridge,
                                        BOOL enabled);

extern enum ERROR_CODE disableAudio(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE setAudioProfile(IRtcEngineBridge_ptr apiBridge,
                                       enum AUDIO_PROFILE_TYPE profile,
                                       enum AUDIO_SCENARIO_TYPE scenario);

extern enum ERROR_CODE muteLocalAudioStream(IRtcEngineBridge_ptr apiBridge,
                                            BOOL mute);

extern enum ERROR_CODE muteAllRemoteAudioStreams(IRtcEngineBridge_ptr apiBridge,
                                                 BOOL mute);

extern enum ERROR_CODE
setDefaultMuteAllRemoteVideoStreams(IRtcEngineBridge_ptr apiBridge, BOOL mute);

extern enum ERROR_CODE
adjustUserPlaybackSignalVolume(IRtcEngineBridge_ptr apiBridge, uid_t uid,
                               int volume);

extern enum ERROR_CODE muteRemoteAudioStream(IRtcEngineBridge_ptr apiBridge,
                                             uid_t userId, BOOL mute);

extern enum ERROR_CODE muteLocalVideoStream(IRtcEngineBridge_ptr apiBridge,
                                            BOOL mute);

extern enum ERROR_CODE enableLocalVideo(IRtcEngineBridge_ptr apiBridge,
                                        BOOL enabled);

extern enum ERROR_CODE muteAllRemoteVideoStreams(IRtcEngineBridge_ptr apiBridge,
                                                 BOOL mute);

extern enum ERROR_CODE
setDefaultMuteAllRemoteAudioStreams(IRtcEngineBridge_ptr apiBridge, BOOL mute);

extern enum ERROR_CODE muteRemoteVideoStream(IRtcEngineBridge_ptr apiBridge,
                                             uid_t userId, BOOL mute);

extern enum ERROR_CODE
setRemoteVideoStreamType(IRtcEngineBridge_ptr apiBridge, uid_t userId,
                         enum REMOTE_VIDEO_STREAM_TYPE streamType);

extern enum ERROR_CODE
setRemoteDefaultVideoStreamType(IRtcEngineBridge_ptr apiBridge,
                                enum REMOTE_VIDEO_STREAM_TYPE streamType);

extern enum ERROR_CODE
enableAudioVolumeIndication(IRtcEngineBridge_ptr apiBridge, int interval,
                            int smooth, BOOL report_vad);

extern enum ERROR_CODE
startAudioRecording(IRtcEngineBridge_ptr apiBridge, const char *filePath,
                    enum AUDIO_RECORDING_QUALITY_TYPE quality);

extern enum ERROR_CODE
startAudioRecording2(IRtcEngineBridge_ptr apiBridge, const char *filePath,
                     int sampleRate, enum AUDIO_RECORDING_QUALITY_TYPE quality);

extern enum ERROR_CODE stopAudioRecording(IRtcEngineBridge_ptr apiBridge);

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
extern enum ERROR_CODE enableFaceDetection(IRtcEngineBridge_ptr apiBridge,
                                           BOOL enable);
#endif

extern enum ERROR_CODE setRemoteVoicePosition(IRtcEngineBridge_ptr apiBridge,
                                              uid_t uid, double pan,
                                              double gain);

extern enum ERROR_CODE setLogFile(IRtcEngineBridge_ptr apiBridge,
                                  const char *file);

extern enum ERROR_CODE setLogFilter(IRtcEngineBridge_ptr apiBridge,
                                    unsigned int filter);

extern enum ERROR_CODE setLogFileSize(IRtcEngineBridge_ptr apiBridge,
                                      unsigned int fileSizeInKBytes);

extern enum ERROR_CODE setLocalRenderMode(IRtcEngineBridge_ptr apiBridge,
                                          enum RENDER_MODE_TYPE renderMode);

extern enum ERROR_CODE
setLocalRenderMode2(IRtcEngineBridge_ptr apiBridge,
                    enum RENDER_MODE_TYPE renderMode,
                    enum VIDEO_MIRROR_MODE_TYPE mirrorMode);

extern enum ERROR_CODE setRemoteRenderMode(IRtcEngineBridge_ptr apiBridge,
                                           uid_t userId,
                                           enum RENDER_MODE_TYPE renderMode);

extern enum ERROR_CODE
setRemoteRenderMode2(IRtcEngineBridge_ptr apiBridge, uid_t userId,
                     enum RENDER_MODE_TYPE renderMode,
                     enum VIDEO_MIRROR_MODE_TYPE mirrorMode);

extern enum ERROR_CODE
setLocalVideoMirrorMode(IRtcEngineBridge_ptr apiBridge,
                        enum VIDEO_MIRROR_MODE_TYPE mirrorMode);

extern enum ERROR_CODE enableDualStreamMode(IRtcEngineBridge_ptr apiBridge,
                                            BOOL enabled);

extern enum ERROR_CODE
adjustRecordingSignalVolume(IRtcEngineBridge_ptr apiBridge, int volume);

extern enum ERROR_CODE
adjustPlaybackSignalVolume(IRtcEngineBridge_ptr apiBridge, int volume);

extern enum ERROR_CODE
enableWebSdkInteroperability(IRtcEngineBridge_ptr apiBridge, BOOL enabled);

extern enum ERROR_CODE
setVideoQualityParameters(IRtcEngineBridge_ptr apiBridge,
                          BOOL preferFrameRateOverImageQuality);

extern enum ERROR_CODE
setLocalPublishFallbackOption(IRtcEngineBridge_ptr apiBridge,
                              enum STREAM_FALLBACK_OPTIONS option);

extern enum ERROR_CODE
setRemoteSubscribeFallbackOption(IRtcEngineBridge_ptr apiBridge,
                                 enum STREAM_FALLBACK_OPTIONS option);

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
extern enum ERROR_CODE switchCamera(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE switchCamera2(IRtcEngineBridge_ptr apiBridge,
                                     enum CAMERA_DIRECTION direction);

extern enum ERROR_CODE
setDefaultAudioRouteToSpeakerphone(IRtcEngineBridge_ptr apiBridge,
                                   BOOL defaultToSpeaker);

extern enum ERROR_CODE setEnableSpeakerphone(IRtcEngineBridge_ptr apiBridge,
                                             BOOL speakerOn);

extern enum ERROR_CODE enableInEarMonitoring(IRtcEngineBridge_ptr apiBridge,
                                             BOOL enabled);

extern enum ERROR_CODE setInEarMonitoringVolume(IRtcEngineBridge_ptr apiBridge,
                                                int volume);

extern BOOL isSpeakerphoneEnabled(IRtcEngineBridge_ptr apiBridge);
#endif

#if (defined(__APPLE__) && TARGET_OS_IOS)
extern enum ERROR_CODE setAudioSessionOperationRestriction(
    IRtcEngineBridge_ptr apiBridge,
    enum AUDIO_SESSION_OPERATION_RESTRICTION restriction);
#endif

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE) ||              \
    defined(_WIN32)
extern enum ERROR_CODE enableLoopbackRecording(IRtcEngineBridge_ptr apiBridge,
                                               BOOL enabled,
                                               const char *deviceName = NULL);

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE)
extern enum ERROR_CODE startScreenCaptureByDisplayId(
    IRtcEngineBridge_ptr apiBridge, unsigned int displayId,
    const struct Rectangle *regionRect,
    const struct ScreenCaptureParameters *captureParams);
#endif

#if defined(_WIN32)
extern enum ERROR_CODE startScreenCaptureByScreenRect(
    IRtcEngineBridge_ptr apiBridge, const struct Rectangle *screenRect,
    const struct Rectangle *regionRect,
    const struct ScreenCaptureParameters *captureParams);

extern enum ERROR_CODE startScreenCaptureByWindowId(
    IRtcEngineBridge_ptr apiBridge, view_t windowId,
    const struct Rectangle *regionRect,
    const struct ScreenCaptureParameters *captureParams);

extern enum ERROR_CODE
setScreenCaptureContentHint(IRtcEngineBridge_ptr apiBridge,
                            enum VideoContentHint contentHint);

extern enum ERROR_CODE
updateScreenCaptureParameters(IRtcEngineBridge_ptr apiBridge,
                              struct ScreenCaptureParameters *captureParams);

extern enum ERROR_CODE updateScreenCaptureRegion(IRtcEngineBridge_ptr apiBridge,
                                                 struct Rectangle *regionRect);

#endif

extern enum ERROR_CODE stopScreenCapture(IRtcEngineBridge_ptr apiBridge);
#endif

extern const char *getCallId(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE rate(IRtcEngineBridge_ptr apiBridge, const char *callId,
                            int rating, const char *description);

extern enum ERROR_CODE complain(IRtcEngineBridge_ptr apiBridge,
                                const char *callId, const char *description);

extern const char *getVersion(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE enableLastmileTest(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE disableLastmileTest(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE
startLastmileProbeTest(IRtcEngineBridge_ptr apiBridge,
                       const struct LastmileProbeConfig config);

extern enum ERROR_CODE stopLastmileProbeTest(IRtcEngineBridge_ptr apiBridge);

extern const char *getErrorDescription(IRtcEngineBridge_ptr apiBridge,
                                       int code);

extern enum ERROR_CODE setEncryptionSecret(IRtcEngineBridge_ptr apiBridge,
                                           const char *secret);

extern enum ERROR_CODE setEncryptionMode(IRtcEngineBridge_ptr apiBridge,
                                         const char *encryptionMode);

// extern enum ERROR_CODE
// registerPacketObserver(IRtcEngineBridge_ptr apiBridge,  IPacketObserver*
// observer);

extern enum ERROR_CODE createDataStream(IRtcEngineBridge_ptr apiBridge,
                                        int *streamId, BOOL reliable,
                                        BOOL ordered);

extern enum ERROR_CODE sendStreamMessage(IRtcEngineBridge_ptr apiBridge,
                                         int streamId, const char *data,
                                         long long length);

extern enum ERROR_CODE addPublishStreamUrl(IRtcEngineBridge_ptr apiBridge,
                                           const char *url,
                                           BOOL transcodingEnabled);

extern enum ERROR_CODE removePublishStreamUrl(IRtcEngineBridge_ptr apiBridge,
                                              const char *url);

extern enum ERROR_CODE
setLiveTranscoding(IRtcEngineBridge_ptr apiBridge,
                   const struct LiveTranscoding *transcoding);

extern enum ERROR_CODE addVideoWatermark(IRtcEngineBridge_ptr apiBridge,
                                         const struct RtcImage watermark);

extern enum ERROR_CODE
addVideoWatermark2(IRtcEngineBridge_ptr apiBridge, const char *watermarkUrl,
                   const struct WatermarkOptions options);

extern enum ERROR_CODE clearVideoWatermarks(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE setBeautyEffectOptions(IRtcEngineBridge_ptr apiBridge,
                                              BOOL enabled,
                                              struct BeautyOptions options);

extern enum ERROR_CODE addInjectStreamUrl(IRtcEngineBridge_ptr apiBridge,
                                          const char *url,
                                          struct InjectStreamConfig config);

extern enum ERROR_CODE
startChannelMediaRelay(IRtcEngineBridge_ptr apiBridge,
                       struct ChannelMediaRelayConfiguration configuration);

extern enum ERROR_CODE
updateChannelMediaRelay(IRtcEngineBridge_ptr apiBridge,
                        struct ChannelMediaRelayConfiguration configuration);

extern enum ERROR_CODE stopChannelMediaRelay(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE removeInjectStreamUrl(IRtcEngineBridge_ptr apiBridge,
                                             const char *url);

extern enum CONNECTION_STATE_TYPE
getConnectionState(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE setParameters(IRtcEngineBridge_ptr apiBridge,
                                     const char *parameters);

extern enum ERROR_CODE setPlaybackDeviceVolume(IRtcEngineBridge_ptr apiBridge,
                                               int volume);

// API_TYPE_AUDIO_EFFECT

extern enum ERROR_CODE startAudioMixing(IRtcEngineBridge_ptr apiBridge,
                                        const char *filePath, BOOL loopback,
                                        BOOL replace, int cycle);

extern enum ERROR_CODE stopAudioMixing(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE pauseAudioMixing(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE resumeAudioMixing(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE
setHighQualityAudioParameters(IRtcEngineBridge_ptr apiBridge, BOOL fullband,
                              BOOL stereo, BOOL fullBitrate);

extern enum ERROR_CODE adjustAudioMixingVolume(IRtcEngineBridge_ptr apiBridge,
                                               int volume);

extern enum ERROR_CODE
adjustAudioMixingPlayoutVolume(IRtcEngineBridge_ptr apiBridge, int volume);

extern enum ERROR_CODE
getAudioMixingPlayoutVolume(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE
adjustAudioMixingPublishVolume(IRtcEngineBridge_ptr apiBridge, int volume);

extern enum ERROR_CODE
getAudioMixingPublishVolume(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE getAudioMixingDuration(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE
getAudioMixingCurrentPosition(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE setAudioMixingPosition(IRtcEngineBridge_ptr apiBridge,
                                              int pos /*in ms*/);

extern enum ERROR_CODE setAudioMixingPitch(IRtcEngineBridge_ptr apiBridge,
                                           int pitch);

extern enum ERROR_CODE getEffectsVolume(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE setEffectsVolume(IRtcEngineBridge_ptr apiBridge,
                                        int volume);

extern enum ERROR_CODE setVolumeOfEffect(IRtcEngineBridge_ptr apiBridge,
                                         int soundId, int volume);

extern enum ERROR_CODE playEffect(IRtcEngineBridge_ptr apiBridge, int soundId,
                                  const char *filePath, int loopCount,
                                  double pitch, double pan, int gain,
                                  BOOL publish);

extern enum ERROR_CODE stopEffect(IRtcEngineBridge_ptr apiBridge, int soundId);

extern enum ERROR_CODE stopAllEffects(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE preloadEffect(IRtcEngineBridge_ptr apiBridge,
                                     int soundId, const char *filePath);

extern enum ERROR_CODE unloadEffect(IRtcEngineBridge_ptr apiBridge,
                                    int soundId);

extern enum ERROR_CODE pauseEffect(IRtcEngineBridge_ptr apiBridge, int soundId);

extern enum ERROR_CODE pauseAllEffects(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE resumeEffect(IRtcEngineBridge_ptr apiBridge,
                                    int soundId);

extern enum ERROR_CODE resumeAllEffects(IRtcEngineBridge_ptr apiBridge);

extern enum ERROR_CODE
enableSoundPositionIndication(IRtcEngineBridge_ptr apiBridge, BOOL enabled);

extern enum ERROR_CODE setLocalVoicePitch(IRtcEngineBridge_ptr apiBridge,
                                          double pitch);

extern enum ERROR_CODE
setLocalVoiceEqualization(IRtcEngineBridge_ptr apiBridge,
                          enum AUDIO_EQUALIZATION_BAND_FREQUENCY bandFrequency,
                          int bandGain);

extern enum ERROR_CODE setLocalVoiceReverb(IRtcEngineBridge_ptr apiBridge,
                                           enum AUDIO_REVERB_TYPE reverbKey,
                                           int value);

extern enum ERROR_CODE
setLocalVoiceChanger(IRtcEngineBridge_ptr apiBridge,
                     enum VOICE_CHANGER_PRESET voiceChanger);

extern enum ERROR_CODE
setLocalVoiceReverbPreset(IRtcEngineBridge_ptr apiBridge,
                          enum AUDIO_REVERB_PRESET reverbPreset);

extern enum ERROR_CODE setExternalAudioSource(IRtcEngineBridge_ptr apiBridge,
                                              BOOL enabled, int sampleRate,
                                              int channels);

extern enum ERROR_CODE setExternalAudioSink(IRtcEngineBridge_ptr apiBridge,
                                            BOOL enabled, int sampleRate,
                                            int channels);

extern enum ERROR_CODE setRecordingAudioFrameParameters(
    IRtcEngineBridge_ptr apiBridge, int sampleRate, int channel,
    enum RAW_AUDIO_FRAME_OP_MODE_TYPE mode, int samplesPerCall);

extern enum ERROR_CODE setPlaybackAudioFrameParameters(
    IRtcEngineBridge_ptr apiBridge, int sampleRate, int channel,
    enum RAW_AUDIO_FRAME_OP_MODE_TYPE mode, int samplesPerCall);

extern enum ERROR_CODE
setMixedAudioFrameParameters(IRtcEngineBridge_ptr apiBridge, int sampleRate,
                             int samplesPerCall);

// extern enum ERROR_CODE
// registerMediaMetadataObserver(IRtcEngineBridge_ptr apiBridge, struct
// IMetadataObserver *observer, rtc::IMetadataObserver::METADATA_TYPE type,  bool
// useSdkDefault = true);

// extern enum ERROR_CODE
// sendMetadata(IRtcEngineBridge_ptr apiBridge, struct
// IMetadataObserver::Metadata *metadata);

// extern enum ERROR_CODE
// setMaxMetadataSize(IRtcEngineBridge_ptr apiBridge, int size);

extern enum ERROR_CODE pushAudioFrame(IRtcEngineBridge_ptr apiBridge,
                                      enum MEDIA_SOURCE_TYPE type,
                                      struct AudioFrame *frame, BOOL wrap);

extern enum ERROR_CODE pushAudioFrame2(IRtcEngineBridge_ptr apiBridge,
                                       struct AudioFrame *frame);

extern enum ERROR_CODE pullAudioFrame(IRtcEngineBridge_ptr apiBridge,
                                      struct AudioFrame *frame);

extern enum ERROR_CODE setExternalVideoSource(IRtcEngineBridge_ptr apiBridge,
                                              BOOL enable, BOOL useTexture);

extern enum ERROR_CODE pushVideoFrame(IRtcEngineBridge_ptr apiBridge,
                                      struct ExternalVideoFrame *frame);

extern enum ERROR_CODE enableEncryption(IRtcEngineBridge_ptr apiBridge,
                                        BOOL enabled,
                                        const struct EncryptionConfig config);

extern enum ERROR_CODE sendCustomReportMessage(IRtcEngineBridge_ptr apiBridge,
                                               const char *id,
                                               const char *category,
                                               const char *event,
                                               const char *label, int value);

extern void channel_add_C_ChannelEventHandler(
    IRtcChannelBridge_ptr apiBridge,
    struct ChannelEventHandler *channelEventHandler);

extern void
channel_remove_C_ChannelEventHandler(IRtcChannelBridge_ptr apiBridge);

extern enum ERROR_CODE
channel_joinChannel(IRtcChannelBridge_ptr apiBridge, const char *token,
                    const char *info, uid_t uid,
                    const struct ChannelMediaOptions options);

extern enum ERROR_CODE
channel_joinChannelWithUserAccount(IRtcChannelBridge_ptr apiBridge,
                                   const char *token, const char *userAccount,
                                   const struct ChannelMediaOptions options);

extern enum ERROR_CODE channel_leaveChannel(IRtcChannelBridge_ptr apiBridge);

extern enum ERROR_CODE channel_publish(IRtcChannelBridge_ptr apiBridge);

extern enum ERROR_CODE channel_unpublish(IRtcChannelBridge_ptr apiBridge);

extern const char *channel_channelId(IRtcChannelBridge_ptr apiBridge);

extern const char *channel_getCallId(IRtcChannelBridge_ptr apiBridge);

extern enum ERROR_CODE channel_renewToken(IRtcChannelBridge_ptr apiBridge,
                                          const char *token);

extern enum ERROR_CODE
channel_setEncryptionSecret(IRtcChannelBridge_ptr apiBridge,
                            const char *secret);

extern enum ERROR_CODE
channel_setEncryptionMode(IRtcChannelBridge_ptr apiBridge,
                          const char *encryptionMode);

// int
// registerPacketObserver(rtc::IPacketObserver* observer);

extern enum ERROR_CODE channel_setClientRole(IRtcChannelBridge_ptr apiBridge,
                                             enum CLIENT_ROLE_TYPE role);

extern enum ERROR_CODE
channel_setRemoteUserPriority(IRtcChannelBridge_ptr apiBridge, uid_t uid,
                              enum PRIORITY_TYPE userPriority);

extern enum ERROR_CODE
channel_setRemoteVoicePosition(IRtcChannelBridge_ptr apiBridge, uid_t uid,
                               double pan, double gain);

extern enum ERROR_CODE
channel_setRemoteRenderMode(IRtcChannelBridge_ptr apiBridge, uid_t userId,
                            enum RENDER_MODE_TYPE renderMode,
                            enum VIDEO_MIRROR_MODE_TYPE mirrorMode);

extern enum ERROR_CODE
channel_setDefaultMuteAllRemoteAudioStreams(IRtcChannelBridge_ptr apiBridge,
                                            BOOL mute);

extern enum ERROR_CODE
channel_setDefaultMuteAllRemoteVideoStreams(IRtcChannelBridge_ptr apiBridge,
                                            BOOL mute);

extern enum ERROR_CODE
channel_muteAllRemoteAudioStreams(IRtcChannelBridge_ptr apiBridge, BOOL mute);

extern enum ERROR_CODE
channel_adjustUserPlaybackSignalVolume(IRtcChannelBridge_ptr apiBridge,
                                       uid_t userId, int volume);

extern enum ERROR_CODE
channel_muteRemoteAudioStream(IRtcChannelBridge_ptr apiBridge, uid_t userId,
                              BOOL mute);

extern enum ERROR_CODE
channel_muteAllRemoteVideoStreams(IRtcChannelBridge_ptr apiBridge, BOOL mute);

extern enum ERROR_CODE
channel_muteRemoteVideoStream(IRtcChannelBridge_ptr apiBridge, uid_t userId,
                              BOOL mute);

extern enum ERROR_CODE
channel_setRemoteVideoStreamType(IRtcChannelBridge_ptr apiBridge, uid_t userId,
                                 enum REMOTE_VIDEO_STREAM_TYPE streamType);

extern enum ERROR_CODE channel_setRemoteDefaultVideoStreamType(
    IRtcChannelBridge_ptr apiBridge, enum REMOTE_VIDEO_STREAM_TYPE streamType);

extern enum ERROR_CODE
channel_addPublishStreamUrl(IRtcChannelBridge_ptr apiBridge, const char *url,
                            BOOL transcodingEnabled);

extern enum ERROR_CODE
channel_removePublishStreamUrl(IRtcChannelBridge_ptr apiBridge,
                               const char *url);

extern enum ERROR_CODE
channel_setLiveTranscoding(IRtcChannelBridge_ptr apiBridge,
                           const struct LiveTranscoding *transcoding);

extern enum ERROR_CODE
channel_addInjectStreamUrl(IRtcChannelBridge_ptr apiBridge, const char *url,
                           const struct InjectStreamConfig config);

extern enum ERROR_CODE
channel_removeInjectStreamUrl(IRtcChannelBridge_ptr apiBridge, const char *url);

extern enum ERROR_CODE channel_startChannelMediaRelay(
    IRtcChannelBridge_ptr apiBridge,
    struct ChannelMediaRelayConfiguration configuration);

extern enum ERROR_CODE channel_updateChannelMediaRelay(
    IRtcChannelBridge_ptr apiBridge,
    struct ChannelMediaRelayConfiguration configuration);

extern enum ERROR_CODE
channel_stopChannelMediaRelay(IRtcChannelBridge_ptr apiBridge);

extern enum ERROR_CODE channel_createDataStream(IRtcChannelBridge_ptr apiBridge,
                                                int *streamId, BOOL reliable,
                                                BOOL ordered);

extern enum ERROR_CODE
channel_sendStreamMessage(IRtcChannelBridge_ptr apiBridge, int streamId,
                          const char *data, long long length);

extern enum CONNECTION_STATE_TYPE
channel_getConnectionState(IRtcChannelBridge_ptr apiBridge);

extern int audio_device_getCount(void *apiBridge, enum DEVICE_TYPE type);

extern enum ERROR_CODE
audio_device_getDevice(void *apiBridge, enum DEVICE_TYPE type, int index,
                       char deviceName[MAX_DEVICE_ID_LENGTH],
                       char deviceId[MAX_DEVICE_ID_LENGTH]);

extern enum ERROR_CODE
audio_device_getCurrentDevice(void *apiBridge, enum DEVICE_TYPE type,
                              char deviceId[MAX_DEVICE_ID_LENGTH]);

extern enum ERROR_CODE
audio_device_getCurrentDeviceInfo(void *apiBridge, enum DEVICE_TYPE type,
                                  char deviceId[MAX_DEVICE_ID_LENGTH],
                                  char deviceName[MAX_DEVICE_ID_LENGTH]);

extern enum ERROR_CODE
audio_device_setDevice(void *apiBridge, enum DEVICE_TYPE type,
                       const char deviceId[MAX_DEVICE_ID_LENGTH]);

extern enum ERROR_CODE audio_device_setDeviceVolume(void *apiBridge,
                                                    enum DEVICE_TYPE type,
                                                    int volume);

extern enum ERROR_CODE audio_device_getDeviceVolume(void *apiBridge,
                                                    enum DEVICE_TYPE type,
                                                    int *volume);

extern enum ERROR_CODE
audio_device_setDeviceMute(void *apiBridge, enum DEVICE_TYPE type, BOOL mute);

extern enum ERROR_CODE
audio_device_getDeviceMute(void *apiBridge, enum DEVICE_TYPE type, BOOL *mute);

extern enum ERROR_CODE
audio_device_startDeviceTest(void *apiBridge, enum DEVICE_TYPE type,
                             const char *testAudioFilePath, int indicationInterval);

extern enum ERROR_CODE audio_device_stopDeviceTest(void *apiBridge,
                                                   enum DEVICE_TYPE type);

extern enum ERROR_CODE audio_device_startAudioDeviceLoopbackTest(
    void *apiBridge, enum DEVICE_TYPE type, int indicationInterval);

extern enum ERROR_CODE
audio_device_stopAudioDeviceLoopbackTest(void *apiBridge,
                                         enum DEVICE_TYPE type);

extern enum ERROR_CODE startDeviceTest(IVideoDeviceManager_ptr apiBridge,
                                       view_t hwnd);

extern enum ERROR_CODE stopDeviceTest(IVideoDeviceManager_ptr apiBridge);

extern enum ERROR_CODE setDevice(IVideoDeviceManager_ptr apiBridge,
                                 const char deviceId[MAX_DEVICE_ID_LENGTH]);

extern enum ERROR_CODE getDevice(IVideoDeviceManager_ptr apiBridge, int index,
                                 char deviceName[MAX_DEVICE_ID_LENGTH],
                                 char deviceId[MAX_DEVICE_ID_LENGTH]);

extern enum ERROR_CODE getCurrentDevice(IVideoDeviceManager_ptr apiBridge,
                                        char deviceId[MAX_DEVICE_ID_LENGTH]);

// int
// channel_registerMediaMetadataObserver(IRtcChannelBridge_ptr apiBridge,
// IMetadataObserver *observer, rtc::IMetadataObserver::METADATA_TYPE type,  bool
// useSdkDefault = true);

// int
// channel_sendMetadata(rtc::IMetadataObserver::Metadata *metadata);
//
// int
// channel_setMaxMetadataSize(int size);

#ifdef __cplusplus
};
#endif
