cdef extern from "ptr_convert.cpp":
	void* py2voidptr(object)
	void* int2voidptr(unsigned int)
	unsigned int voidptr2int(void* a)
	void** py2voidptrptr(object)
	object voidptr2py (void*)
	IRtcEngineEventHandler* convert(EventHandler* e)
	EventHandler* convertBack(IRtcEngineEventHandler* e)
	IVideoFrameObserver* convert2(VideoFrameObserver* e)
from libcpp cimport bool
cdef extern from "include/AgoraBase.h"namespace "agora::util":
	cdef cppclass IString:
		bool empty()
		char * c_str()
		char * data()
		size_t length()
		void release()
cdef extern from "include/AgoraBase.h"namespace "agora::util":
	cdef cppclass AString:
		AString() except +
		AString(IString*x1) except +
		IString * get()
		IString * release()
		void reset(IString*x1)
cdef extern from "include/AgoraBase.h"namespace "agora":
	cdef enum INTERFACE_ID_TYPE:
		AGORA_IID_AUDIO_DEVICE_MANAGER = 1
		AGORA_IID_VIDEO_DEVICE_MANAGER = 2
		AGORA_IID_RTC_ENGINE_PARAMETER = 3
		AGORA_IID_MEDIA_ENGINE = 4
		AGORA_IID_SIGNALING_ENGINE = 8
cdef extern from "include/AgoraBase.h"namespace "agora":
	cdef enum WARN_CODE_TYPE:
		WARN_INVALID_VIEW = 8
		WARN_INIT_VIDEO = 16
		WARN_PENDING = 20
		WARN_NO_AVAILABLE_CHANNEL = 103
		WARN_LOOKUP_CHANNEL_TIMEOUT = 104
		WARN_LOOKUP_CHANNEL_REJECTED = 105
		WARN_OPEN_CHANNEL_TIMEOUT = 106
		WARN_OPEN_CHANNEL_REJECTED = 107
		WARN_SWITCH_LIVE_VIDEO_TIMEOUT = 111
		WARN_SET_CLIENT_ROLE_TIMEOUT = 118
		WARN_OPEN_CHANNEL_INVALID_TICKET = 121
		WARN_OPEN_CHANNEL_TRY_NEXT_VOS = 122
		WARN_AUDIO_MIXING_OPEN_ERROR = 701
		WARN_ADM_RUNTIME_PLAYOUT_WARNING = 1014
		WARN_ADM_RUNTIME_RECORDING_WARNING = 1016
		WARN_ADM_RECORD_AUDIO_SILENCE = 1019
		WARN_ADM_PLAYOUT_MALFUNCTION = 1020
		WARN_ADM_RECORD_MALFUNCTION = 1021
		WARN_ADM_IOS_CATEGORY_NOT_PLAYANDRECORD = 1029
		WARN_ADM_IOS_SAMPLERATE_CHANGE = 1030
		WARN_ADM_RECORD_AUDIO_LOWLEVEL = 1031
		WARN_ADM_PLAYOUT_AUDIO_LOWLEVEL = 1032
		WARN_ADM_WINDOWS_NO_DATA_READY_EVENT = 1040
		WARN_APM_HOWLING = 1051
		WARN_ADM_GLITCH_STATE = 1052
		WARN_ADM_IMPROPER_SETTINGS = 1053
		WARN_ADM_WIN_CORE_NO_RECORDING_DEVICE = 1322
		WARN_ADM_WIN_CORE_NO_PLAYOUT_DEVICE = 1323
		WARN_ADM_WIN_CORE_IMPROPER_CAPTURE_RELEASE = 1324
		WARN_SUPER_RESOLUTION_STREAM_OVER_LIMITATION = 1610
		WARN_SUPER_RESOLUTION_USER_COUNT_OVER_LIMITATION = 1611
		WARN_SUPER_RESOLUTION_DEVICE_NOT_SUPPORTED = 1612
cdef extern from "include/AgoraBase.h"namespace "agora":
	cdef enum ERROR_CODE_TYPE:
		ERR_OK = 0
		ERR_FAILED = 1
		ERR_INVALID_ARGUMENT = 2
		ERR_NOT_READY = 3
		ERR_NOT_SUPPORTED = 4
		ERR_REFUSED = 5
		ERR_BUFFER_TOO_SMALL = 6
		ERR_NOT_INITIALIZED = 7
		ERR_NO_PERMISSION = 9
		ERR_TIMEDOUT = 10
		ERR_CANCELED = 11
		ERR_TOO_OFTEN = 12
		ERR_BIND_SOCKET = 13
		ERR_NET_DOWN = 14
		ERR_NET_NOBUFS = 15
		ERR_JOIN_CHANNEL_REJECTED = 17
		ERR_LEAVE_CHANNEL_REJECTED = 18
		ERR_ALREADY_IN_USE = 19
		ERR_ABORTED = 20
		ERR_INIT_NET_ENGINE = 21
		ERR_RESOURCE_LIMITED = 22
		ERR_INVALID_APP_ID = 101
		ERR_INVALID_CHANNEL_NAME = 102
		ERR_TOKEN_EXPIRED = 109
		ERR_INVALID_TOKEN = 110
		ERR_CONNECTION_INTERRUPTED = 111
		ERR_CONNECTION_LOST = 112
		ERR_NOT_IN_CHANNEL = 113
		ERR_SIZE_TOO_LARGE = 114
		ERR_BITRATE_LIMIT = 115
		ERR_TOO_MANY_DATA_STREAMS = 116
		ERR_STREAM_MESSAGE_TIMEOUT = 117
		ERR_SET_CLIENT_ROLE_NOT_AUTHORIZED = 119
		ERR_DECRYPTION_FAILED = 120
		ERR_CLIENT_IS_BANNED_BY_SERVER = 123
		ERR_WATERMARK_PARAM = 124
		ERR_WATERMARK_PATH = 125
		ERR_WATERMARK_PNG = 126
		ERR_WATERMARKR_INFO = 127
		ERR_WATERMARK_ARGB = 128
		ERR_WATERMARK_READ = 129
		ERR_ENCRYPTED_STREAM_NOT_ALLOWED_PUBLISH = 130
		ERR_LOGOUT_OTHER = 400
		ERR_LOGOUT_USER = 401
		ERR_LOGOUT_NET = 402
		ERR_LOGOUT_KICKED = 403
		ERR_LOGOUT_PACKET = 404
		ERR_LOGOUT_TOKEN_EXPIRED = 405
		ERR_LOGOUT_OLDVERSION = 406
		ERR_LOGOUT_TOKEN_WRONG = 407
		ERR_LOGOUT_ALREADY_LOGOUT = 408
		ERR_LOGIN_OTHER = 420
		ERR_LOGIN_NET = 421
		ERR_LOGIN_FAILED = 422
		ERR_LOGIN_CANCELED = 423
		ERR_LOGIN_TOKEN_EXPIRED = 424
		ERR_LOGIN_OLD_VERSION = 425
		ERR_LOGIN_TOKEN_WRONG = 426
		ERR_LOGIN_TOKEN_KICKED = 427
		ERR_LOGIN_ALREADY_LOGIN = 428
		ERR_JOIN_CHANNEL_OTHER = 440
		ERR_SEND_MESSAGE_OTHER = 440
		ERR_SEND_MESSAGE_TIMEOUT = 441
		ERR_QUERY_USERNUM_OTHER = 450
		ERR_QUERY_USERNUM_TIMEOUT = 451
		ERR_QUERY_USERNUM_BYUSER = 452
		ERR_LEAVE_CHANNEL_OTHER = 460
		ERR_LEAVE_CHANNEL_KICKED = 461
		ERR_LEAVE_CHANNEL_BYUSER = 462
		ERR_LEAVE_CHANNEL_LOGOUT = 463
		ERR_LEAVE_CHANNEL_DISCONNECTED = 464
		ERR_INVITE_OTHER = 470
		ERR_INVITE_REINVITE = 471
		ERR_INVITE_NET = 472
		ERR_INVITE_PEER_OFFLINE = 473
		ERR_INVITE_TIMEOUT = 474
		ERR_INVITE_CANT_RECV = 475
		ERR_LOAD_MEDIA_ENGINE = 1001
		ERR_START_CALL = 1002
		ERR_START_CAMERA = 1003
		ERR_START_VIDEO_RENDER = 1004
		ERR_ADM_GENERAL_ERROR = 1005
		ERR_ADM_JAVA_RESOURCE = 1006
		ERR_ADM_SAMPLE_RATE = 1007
		ERR_ADM_INIT_PLAYOUT = 1008
		ERR_ADM_START_PLAYOUT = 1009
		ERR_ADM_STOP_PLAYOUT = 1010
		ERR_ADM_INIT_RECORDING = 1011
		ERR_ADM_START_RECORDING = 1012
		ERR_ADM_STOP_RECORDING = 1013
		ERR_ADM_RUNTIME_PLAYOUT_ERROR = 1015
		ERR_ADM_RUNTIME_RECORDING_ERROR = 1017
		ERR_ADM_RECORD_AUDIO_FAILED = 1018
		ERR_ADM_INIT_LOOPBACK = 1022
		ERR_ADM_START_LOOPBACK = 1023
		ERR_ADM_NO_PERMISSION = 1027
		ERR_ADM_RECORD_AUDIO_IS_ACTIVE = 1033
		ERR_ADM_ANDROID_JNI_JAVA_RESOURCE = 1101
		ERR_ADM_ANDROID_JNI_NO_RECORD_FREQUENCY = 1108
		ERR_ADM_ANDROID_JNI_NO_PLAYBACK_FREQUENCY = 1109
		ERR_ADM_ANDROID_JNI_JAVA_START_RECORD = 1111
		ERR_ADM_ANDROID_JNI_JAVA_START_PLAYBACK = 1112
		ERR_ADM_ANDROID_JNI_JAVA_RECORD_ERROR = 1115
		ERR_ADM_ANDROID_OPENSL_CREATE_ENGINE = 1151
		ERR_ADM_ANDROID_OPENSL_CREATE_AUDIO_RECORDER = 1153
		ERR_ADM_ANDROID_OPENSL_START_RECORDER_THREAD = 1156
		ERR_ADM_ANDROID_OPENSL_CREATE_AUDIO_PLAYER = 1157
		ERR_ADM_ANDROID_OPENSL_START_PLAYER_THREAD = 1160
		ERR_ADM_IOS_INPUT_NOT_AVAILABLE = 1201
		ERR_ADM_IOS_ACTIVATE_SESSION_FAIL = 1206
		ERR_ADM_IOS_VPIO_INIT_FAIL = 1210
		ERR_ADM_IOS_VPIO_REINIT_FAIL = 1213
		ERR_ADM_IOS_VPIO_RESTART_FAIL = 1214
		ERR_ADM_IOS_SET_RENDER_CALLBACK_FAIL = 1219
		ERR_ADM_IOS_SESSION_SAMPLERATR_ZERO = 1221
		ERR_ADM_WIN_CORE_INIT = 1301
		ERR_ADM_WIN_CORE_INIT_RECORDING = 1303
		ERR_ADM_WIN_CORE_INIT_PLAYOUT = 1306
		ERR_ADM_WIN_CORE_INIT_PLAYOUT_NULL = 1307
		ERR_ADM_WIN_CORE_START_RECORDING = 1309
		ERR_ADM_WIN_CORE_CREATE_REC_THREAD = 1311
		ERR_ADM_WIN_CORE_CAPTURE_NOT_STARTUP = 1314
		ERR_ADM_WIN_CORE_CREATE_RENDER_THREAD = 1319
		ERR_ADM_WIN_CORE_RENDER_NOT_STARTUP = 1320
		ERR_ADM_WIN_CORE_NO_RECORDING_DEVICE = 1322
		ERR_ADM_WIN_CORE_NO_PLAYOUT_DEVICE = 1323
		ERR_ADM_WIN_WAVE_INIT = 1351
		ERR_ADM_WIN_WAVE_INIT_RECORDING = 1353
		ERR_ADM_WIN_WAVE_INIT_MICROPHONE = 1354
		ERR_ADM_WIN_WAVE_INIT_PLAYOUT = 1355
		ERR_ADM_WIN_WAVE_INIT_SPEAKER = 1356
		ERR_ADM_WIN_WAVE_START_RECORDING = 1357
		ERR_ADM_WIN_WAVE_START_PLAYOUT = 1358
		ERR_ADM_NO_RECORDING_DEVICE = 1359
		ERR_ADM_NO_PLAYOUT_DEVICE = 1360
		ERR_VDM_CAMERA_NOT_AUTHORIZED = 1501
		ERR_VDM_WIN_DEVICE_IN_USE = 1502
		ERR_VCM_UNKNOWN_ERROR = 1600
		ERR_VCM_ENCODER_INIT_ERROR = 1601
		ERR_VCM_ENCODER_ENCODE_ERROR = 1602
		ERR_VCM_ENCODER_SET_ERROR = 1603
cdef extern from "include/AgoraBase.h"namespace "agora":
	cdef enum LOG_FILTER_TYPE:
		LOG_FILTER_OFF = 0
		LOG_FILTER_DEBUG = 0x080f
		LOG_FILTER_INFO = 0x000f
		LOG_FILTER_WARN = 0x000e
		LOG_FILTER_ERROR = 0x000c
		LOG_FILTER_CRITICAL = 0x0008
		LOG_FILTER_MASK = 0x80f
cdef extern from "include/IAgoraService.h"namespace "agora::signaling":
	cdef cppclass ISignalingEngine:
		bool addition
cdef extern from "include/IAgoraService.h"namespace "agora::base":
	cdef cppclass AgoraServiceContext:
		pass
cdef extern from "include/IAgoraService.h"namespace "agora::base":
	cdef cppclass IAgoraService:
		void release()
		int initialize(AgoraServiceContext& x1)
		char * getVersion(int *x1)
		IRtcEngine * createRtcEngine()
		ISignalingEngine * createSignalingEngine()
cdef extern from "include/IAgoraService.h":
	char * getAgoraSdkVersion(int *x1)
cdef extern from "include/IAgoraService.h":
	char * getAgoraSdkErrorDescription(int x1)
cdef extern from "include/IAgoraService.h":
	IAgoraService * createAgoraService()
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	ctypedef unsigned int uid_t
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	ctypedef void * view_t
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum MAX_DEVICE_ID_LENGTH_TYPE:
		MAX_DEVICE_ID_LENGTH = 512
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum QUALITY_REPORT_FORMAT_TYPE:
		QUALITY_REPORT_JSON = 0
		QUALITY_REPORT_HTML = 1
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum MEDIA_ENGINE_EVENT_CODE_TYPE:
		MEDIA_ENGINE_RECORDING_ERROR = 0
		MEDIA_ENGINE_PLAYOUT_ERROR = 1
		MEDIA_ENGINE_RECORDING_WARNING = 2
		MEDIA_ENGINE_PLAYOUT_WARNING = 3
		MEDIA_ENGINE_AUDIO_FILE_MIX_FINISH = 10
		MEDIA_ENGINE_AUDIO_FAREND_MUSIC_BEGINS = 12
		MEDIA_ENGINE_AUDIO_FAREND_MUSIC_ENDS = 13
		MEDIA_ENGINE_LOCAL_AUDIO_RECORD_ENABLED = 14
		MEDIA_ENGINE_LOCAL_AUDIO_RECORD_DISABLED = 15
		MEDIA_ENGINE_ROLE_BROADCASTER_SOLO = 20
		MEDIA_ENGINE_ROLE_BROADCASTER_INTERACTIVE = 21
		MEDIA_ENGINE_ROLE_AUDIENCE = 22
		MEDIA_ENGINE_ROLE_COMM_PEER = 23
		MEDIA_ENGINE_ROLE_GAME_PEER = 24
		MEDIA_ENGINE_AUDIO_ADM_REQUIRE_RESTART = 110
		MEDIA_ENGINE_AUDIO_ADM_SPECIAL_RESTART = 111
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_PLAY = 710
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_PAUSED = 711
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_RESTART = 712
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_STOPPED = 713
		MEDIA_ENGINE_AUDIO_EVENT_MIXING_ERROR = 714
		MEDIA_ENGINE_AUDIO_ERROR_MIXING_OPEN = 701
		MEDIA_ENGINE_AUDIO_ERROR_MIXING_TOO_FREQUENT = 702
		MEDIA_ENGINE_AUDIO_ERROR_MIXING_INTERRUPTED_EOF = 703
		MEDIA_ENGINE_AUDIO_ERROR_MIXING_NO_ERROR = 0
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_MIXING_STATE_TYPE:
		AUDIO_MIXING_STATE_PLAYING = 710
		AUDIO_MIXING_STATE_PAUSED = 711
		AUDIO_MIXING_STATE_STOPPED = 713
		AUDIO_MIXING_STATE_FAILED = 714
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_MIXING_ERROR_TYPE:
		AUDIO_MIXING_ERROR_CAN_NOT_OPEN = 701
		AUDIO_MIXING_ERROR_TOO_FREQUENT_CALL = 702
		AUDIO_MIXING_ERROR_INTERRUPTED_EOF = 703
		AUDIO_MIXING_ERROR_OK = 0
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum MEDIA_DEVICE_STATE_TYPE:
		MEDIA_DEVICE_STATE_ACTIVE = 1
		MEDIA_DEVICE_STATE_DISABLED = 2
		MEDIA_DEVICE_STATE_NOT_PRESENT = 4
		MEDIA_DEVICE_STATE_UNPLUGGED = 8
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum MEDIA_DEVICE_TYPE:
		UNKNOWN_AUDIO_DEVICE = -1
		AUDIO_PLAYOUT_DEVICE = 0
		AUDIO_RECORDING_DEVICE = 1
		VIDEO_RENDER_DEVICE = 2
		VIDEO_CAPTURE_DEVICE = 3
		AUDIO_APPLICATION_PLAYOUT_DEVICE = 4
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_RECORDING_QUALITY_TYPE:
		AUDIO_RECORDING_QUALITY_LOW = 0
		AUDIO_RECORDING_QUALITY_MEDIUM = 1
		AUDIO_RECORDING_QUALITY_HIGH = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum QUALITY_TYPE:
		QUALITY_UNKNOWN = 0
		QUALITY_EXCELLENT = 1
		QUALITY_GOOD = 2
		QUALITY_POOR = 3
		QUALITY_BAD = 4
		QUALITY_VBAD = 5
		QUALITY_DOWN = 6
		QUALITY_UNSUPPORTED = 7
		QUALITY_DETECTING = 8
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum RENDER_MODE_TYPE:
		RENDER_MODE_HIDDEN = 1
		RENDER_MODE_FIT = 2
		RENDER_MODE_ADAPTIVE = 3
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum VIDEO_MIRROR_MODE_TYPE:
		VIDEO_MIRROR_MODE_AUTO = 0
		VIDEO_MIRROR_MODE_ENABLED = 1
		VIDEO_MIRROR_MODE_DISABLED = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum VIDEO_PROFILE_TYPE:
		VIDEO_PROFILE_LANDSCAPE_120P = 0
		VIDEO_PROFILE_LANDSCAPE_120P_3 = 2
		VIDEO_PROFILE_LANDSCAPE_180P = 10
		VIDEO_PROFILE_LANDSCAPE_180P_3 = 12
		VIDEO_PROFILE_LANDSCAPE_180P_4 = 13
		VIDEO_PROFILE_LANDSCAPE_240P = 20
		VIDEO_PROFILE_LANDSCAPE_240P_3 = 22
		VIDEO_PROFILE_LANDSCAPE_240P_4 = 23
		VIDEO_PROFILE_LANDSCAPE_360P = 30
		VIDEO_PROFILE_LANDSCAPE_360P_3 = 32
		VIDEO_PROFILE_LANDSCAPE_360P_4 = 33
		VIDEO_PROFILE_LANDSCAPE_360P_6 = 35
		VIDEO_PROFILE_LANDSCAPE_360P_7 = 36
		VIDEO_PROFILE_LANDSCAPE_360P_8 = 37
		VIDEO_PROFILE_LANDSCAPE_360P_9 = 38
		VIDEO_PROFILE_LANDSCAPE_360P_10 = 39
		VIDEO_PROFILE_LANDSCAPE_360P_11 = 100
		VIDEO_PROFILE_LANDSCAPE_480P = 40
		VIDEO_PROFILE_LANDSCAPE_480P_3 = 42
		VIDEO_PROFILE_LANDSCAPE_480P_4 = 43
		VIDEO_PROFILE_LANDSCAPE_480P_6 = 45
		VIDEO_PROFILE_LANDSCAPE_480P_8 = 47
		VIDEO_PROFILE_LANDSCAPE_480P_9 = 48
		VIDEO_PROFILE_LANDSCAPE_480P_10 = 49
		VIDEO_PROFILE_LANDSCAPE_720P = 50
		VIDEO_PROFILE_LANDSCAPE_720P_3 = 52
		VIDEO_PROFILE_LANDSCAPE_720P_5 = 54
		VIDEO_PROFILE_LANDSCAPE_720P_6 = 55
		VIDEO_PROFILE_LANDSCAPE_1080P = 60
		VIDEO_PROFILE_LANDSCAPE_1080P_3 = 62
		VIDEO_PROFILE_LANDSCAPE_1080P_5 = 64
		VIDEO_PROFILE_LANDSCAPE_1440P = 66
		VIDEO_PROFILE_LANDSCAPE_1440P_2 = 67
		VIDEO_PROFILE_LANDSCAPE_4K = 70
		VIDEO_PROFILE_LANDSCAPE_4K_3 = 72
		VIDEO_PROFILE_PORTRAIT_120P = 1000
		VIDEO_PROFILE_PORTRAIT_120P_3 = 1002
		VIDEO_PROFILE_PORTRAIT_180P = 1010
		VIDEO_PROFILE_PORTRAIT_180P_3 = 1012
		VIDEO_PROFILE_PORTRAIT_180P_4 = 1013
		VIDEO_PROFILE_PORTRAIT_240P = 1020
		VIDEO_PROFILE_PORTRAIT_240P_3 = 1022
		VIDEO_PROFILE_PORTRAIT_240P_4 = 1023
		VIDEO_PROFILE_PORTRAIT_360P = 1030
		VIDEO_PROFILE_PORTRAIT_360P_3 = 1032
		VIDEO_PROFILE_PORTRAIT_360P_4 = 1033
		VIDEO_PROFILE_PORTRAIT_360P_6 = 1035
		VIDEO_PROFILE_PORTRAIT_360P_7 = 1036
		VIDEO_PROFILE_PORTRAIT_360P_8 = 1037
		VIDEO_PROFILE_PORTRAIT_360P_9 = 1038
		VIDEO_PROFILE_PORTRAIT_360P_10 = 1039
		VIDEO_PROFILE_PORTRAIT_360P_11 = 1100
		VIDEO_PROFILE_PORTRAIT_480P = 1040
		VIDEO_PROFILE_PORTRAIT_480P_3 = 1042
		VIDEO_PROFILE_PORTRAIT_480P_4 = 1043
		VIDEO_PROFILE_PORTRAIT_480P_6 = 1045
		VIDEO_PROFILE_PORTRAIT_480P_8 = 1047
		VIDEO_PROFILE_PORTRAIT_480P_9 = 1048
		VIDEO_PROFILE_PORTRAIT_480P_10 = 1049
		VIDEO_PROFILE_PORTRAIT_720P = 1050
		VIDEO_PROFILE_PORTRAIT_720P_3 = 1052
		VIDEO_PROFILE_PORTRAIT_720P_5 = 1054
		VIDEO_PROFILE_PORTRAIT_720P_6 = 1055
		VIDEO_PROFILE_PORTRAIT_1080P = 1060
		VIDEO_PROFILE_PORTRAIT_1080P_3 = 1062
		VIDEO_PROFILE_PORTRAIT_1080P_5 = 1064
		VIDEO_PROFILE_PORTRAIT_1440P = 1066
		VIDEO_PROFILE_PORTRAIT_1440P_2 = 1067
		VIDEO_PROFILE_PORTRAIT_4K = 1070
		VIDEO_PROFILE_PORTRAIT_4K_3 = 1072
		VIDEO_PROFILE_DEFAULT = VIDEO_PROFILE_LANDSCAPE_360P
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_PROFILE_TYPE:
		AUDIO_PROFILE_DEFAULT = 0
		AUDIO_PROFILE_SPEECH_STANDARD = 1
		AUDIO_PROFILE_MUSIC_STANDARD = 2
		AUDIO_PROFILE_MUSIC_STANDARD_STEREO = 3
		AUDIO_PROFILE_MUSIC_HIGH_QUALITY = 4
		AUDIO_PROFILE_MUSIC_HIGH_QUALITY_STEREO = 5
		AUDIO_PROFILE_IOT = 6
		AUDIO_PROFILE_NUM = 7
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_SCENARIO_TYPE:
		AUDIO_SCENARIO_DEFAULT = 0
		AUDIO_SCENARIO_CHATROOM_ENTERTAINMENT = 1
		AUDIO_SCENARIO_EDUCATION = 2
		AUDIO_SCENARIO_GAME_STREAMING = 3
		AUDIO_SCENARIO_SHOWROOM = 4
		AUDIO_SCENARIO_CHATROOM_GAMING = 5
		AUDIO_SCENARIO_IOT = 6
		AUDIO_SCENARIO_NUM = 7
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum CHANNEL_PROFILE_TYPE:
		CHANNEL_PROFILE_COMMUNICATION = 0
		CHANNEL_PROFILE_LIVE_BROADCASTING = 1
		CHANNEL_PROFILE_GAME = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum CLIENT_ROLE_TYPE:
		CLIENT_ROLE_BROADCASTER = 1
		CLIENT_ROLE_AUDIENCE = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum USER_OFFLINE_REASON_TYPE:
		USER_OFFLINE_QUIT = 0
		USER_OFFLINE_DROPPED = 1
		USER_OFFLINE_BECOME_AUDIENCE = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum INJECT_STREAM_STATUS:
		INJECT_STREAM_STATUS_START_SUCCESS = 0
		INJECT_STREAM_STATUS_START_ALREADY_EXISTS = 1
		INJECT_STREAM_STATUS_START_UNAUTHORIZED = 2
		INJECT_STREAM_STATUS_START_TIMEDOUT = 3
		INJECT_STREAM_STATUS_START_FAILED = 4
		INJECT_STREAM_STATUS_STOP_SUCCESS = 5
		INJECT_STREAM_STATUS_STOP_NOT_FOUND = 6
		INJECT_STREAM_STATUS_STOP_UNAUTHORIZED = 7
		INJECT_STREAM_STATUS_STOP_TIMEDOUT = 8
		INJECT_STREAM_STATUS_STOP_FAILED = 9
		INJECT_STREAM_STATUS_BROKEN = 10
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum REMOTE_VIDEO_STREAM_TYPE:
		REMOTE_VIDEO_STREAM_HIGH = 0
		REMOTE_VIDEO_STREAM_LOW = 1
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum RAW_AUDIO_FRAME_OP_MODE_TYPE:
		RAW_AUDIO_FRAME_OP_MODE_READ_ONLY = 0
		RAW_AUDIO_FRAME_OP_MODE_WRITE_ONLY = 1
		RAW_AUDIO_FRAME_OP_MODE_READ_WRITE = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_SAMPLE_RATE_TYPE:
		AUDIO_SAMPLE_RATE_32000 = 32000
		AUDIO_SAMPLE_RATE_44100 = 44100
		AUDIO_SAMPLE_RATE_48000 = 48000
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum VIDEO_CODEC_PROFILE_TYPE:
		VIDEO_CODEC_PROFILE_BASELINE = 66
		VIDEO_CODEC_PROFILE_MAIN = 77
		VIDEO_CODEC_PROFILE_HIGH = 100
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_EQUALIZATION_BAND_FREQUENCY:
		AUDIO_EQUALIZATION_BAND_31 = 0
		AUDIO_EQUALIZATION_BAND_62 = 1
		AUDIO_EQUALIZATION_BAND_125 = 2
		AUDIO_EQUALIZATION_BAND_250 = 3
		AUDIO_EQUALIZATION_BAND_500 = 4
		AUDIO_EQUALIZATION_BAND_1K = 5
		AUDIO_EQUALIZATION_BAND_2K = 6
		AUDIO_EQUALIZATION_BAND_4K = 7
		AUDIO_EQUALIZATION_BAND_8K = 8
		AUDIO_EQUALIZATION_BAND_16K = 9
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_REVERB_TYPE:
		AUDIO_REVERB_DRY_LEVEL = 0
		AUDIO_REVERB_WET_LEVEL = 1
		AUDIO_REVERB_ROOM_SIZE = 2
		AUDIO_REVERB_WET_DELAY = 3
		AUDIO_REVERB_STRENGTH = 4
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum VOICE_CHANGER_PRESET:
		VOICE_CHANGER_OFF = 0
		VOICE_CHANGER_OLDMAN = 1
		VOICE_CHANGER_BABYBOY = 2
		VOICE_CHANGER_BABYGIRL = 3
		VOICE_CHANGER_ZHUBAJIE = 4
		VOICE_CHANGER_ETHEREAL = 5
		VOICE_CHANGER_HULK = 6
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum AUDIO_REVERB_PRESET:
		AUDIO_REVERB_OFF = 0
		AUDIO_REVERB_POPULAR = 1
		AUDIO_REVERB_RNB = 2
		AUDIO_REVERB_ROCK = 3
		AUDIO_REVERB_HIPHOP = 4
		AUDIO_REVERB_VOCAL_CONCERT = 5
		AUDIO_REVERB_KTV = 6
		AUDIO_REVERB_STUDIO = 7
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum REMOTE_VIDEO_STATE:
		REMOTE_VIDEO_STATE_RUNNING = 1
		REMOTE_VIDEO_STATE_FROZEN = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum FRAME_RATE:
		FRAME_RATE_FPS_1 = 1
		FRAME_RATE_FPS_7 = 7
		FRAME_RATE_FPS_10 = 10
		FRAME_RATE_FPS_15 = 15
		FRAME_RATE_FPS_24 = 24
		FRAME_RATE_FPS_30 = 30
		FRAME_RATE_FPS_60 = 60
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum ORIENTATION_MODE:
		ORIENTATION_MODE_ADAPTIVE = 0
		ORIENTATION_MODE_FIXED_LANDSCAPE = 1
		ORIENTATION_MODE_FIXED_PORTRAIT = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum DEGRADATION_PREFERENCE:
		MAINTAIN_QUALITY = 0
		MAINTAIN_FRAMERATE = 1
		MAINTAIN_BALANCED = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum STREAM_FALLBACK_OPTIONS:
		STREAM_FALLBACK_OPTION_DISABLED = 0
		STREAM_FALLBACK_OPTION_VIDEO_STREAM_LOW = 1
		STREAM_FALLBACK_OPTION_AUDIO_ONLY = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum CAPTURER_OUTPUT_PREFERENCE:
		CAPTURER_OUTPUT_PREFERENCE_AUTO = 0
		CAPTURER_OUTPUT_PREFERENCE_PERFORMANCE = 1
		CAPTURER_OUTPUT_PREFERENCE_PREVIEW = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum PRIORITY_TYPE:
		PRIORITY_HIGH = 50
		PRIORITY_NORMAL = 100
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum CONNECTION_STATE_TYPE:
		CONNECTION_STATE_DISCONNECTED = 1
		CONNECTION_STATE_CONNECTING = 2
		CONNECTION_STATE_CONNECTED = 3
		CONNECTION_STATE_RECONNECTING = 4
		CONNECTION_STATE_FAILED = 5
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum CONNECTION_CHANGED_REASON_TYPE:
		CONNECTION_CHANGED_CONNECTING = 0
		CONNECTION_CHANGED_JOIN_SUCCESS = 1
		CONNECTION_CHANGED_INTERRUPTED = 2
		CONNECTION_CHANGED_BANNED_BY_SERVER = 3
		CONNECTION_CHANGED_JOIN_FAILED = 4
		CONNECTION_CHANGED_LEAVE_CHANNEL = 5
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum LASTMILE_PROBE_RESULT_STATE:
		LASTMILE_PROBE_RESULT_COMPLETE = 1
		LASTMILE_PROBE_RESULT_INCOMPLETE_NO_BWE = 2
		LASTMILE_PROBE_RESULT_UNAVAILABLE = 3
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass LastmileProbeOneWayResult:
		unsigned int packetLossRate
		unsigned int jitter
		unsigned int availableBandwidth
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass LastmileProbeResult:
		LASTMILE_PROBE_RESULT_STATE state
		LastmileProbeOneWayResult uplinkReport
		LastmileProbeOneWayResult downlinkReport
		unsigned int rtt
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass LastmileProbeConfig:
		bool probeUplink
		bool probeDownlink
		unsigned int expectedUplinkBitrate
		unsigned int expectedDownlinkBitrate
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass AudioVolumeInfo:
		uid_t uid
		unsigned int volume
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass RtcStats:
		unsigned int duration
		unsigned int txBytes
		unsigned int rxBytes
		unsigned short txKBitRate
		unsigned short rxKBitRate
		unsigned short rxAudioKBitRate
		unsigned short txAudioKBitRate
		unsigned short rxVideoKBitRate
		unsigned short txVideoKBitRate
		unsigned short lastmileDelay
		unsigned int userCount
		double cpuAppUsage
		double cpuTotalUsage
		RtcStats() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum QUALITY_ADAPT_INDICATION:
		ADAPT_NONE = 0
		ADAPT_UP_BANDWIDTH = 1
		ADAPT_DOWN_BANDWIDTH = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass LocalVideoStats:
		int sentBitrate
		int sentFrameRate
		int targetBitrate
		int targetFrameRate
		QUALITY_ADAPT_INDICATION qualityAdaptIndication
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass RemoteVideoStats:
		uid_t uid
		int delay
		int width
		int height
		int receivedBitrate
		int receivedFrameRate
		REMOTE_VIDEO_STREAM_TYPE rxStreamType
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass RemoteAudioStats:
		uid_t uid
		int quality
		int networkTransportDelay
		int jitterBufferDelay
		int audioLossRate
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass VideoCompositingLayout:
		cppclass Region:
			uid_t uid
			double x
			double y
			double width
			double height
			int zOrder
			double alpha
			RENDER_MODE_TYPE renderMode
			Region() except +
		int canvasWidth
		int canvasHeight
		char* backgroundColor
		Region* regions
		int regionCount
		char* appData
		int appDataLength
		VideoCompositingLayout() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc::VideoCompositingLayout":
	cppclass Region:
		uid_t uid
		double x
		double y
		double width
		double height
		int zOrder
		double alpha
		RENDER_MODE_TYPE renderMode
		Region() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass VideoDimensions:
		int width
		int height
		VideoDimensions() except +
		VideoDimensions(int x1,int x2) except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass VideoEncoderConfiguration:
		VideoDimensions dimensions
		FRAME_RATE frameRate
		int minFrameRate
		int bitrate
		int minBitrate
		ORIENTATION_MODE orientationMode
		DEGRADATION_PREFERENCE degradationPreference
		VideoEncoderConfiguration(VideoDimensions& x1,FRAME_RATE x2,int x3,ORIENTATION_MODE x4) except +
		VideoEncoderConfiguration(int x1,int x2,FRAME_RATE x3,int x4,ORIENTATION_MODE x5) except +
		VideoEncoderConfiguration() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass TranscodingUser:
		uid_t uid
		int x
		int y
		int width
		int height
		int zOrder
		double alpha
		int audioChannel
		TranscodingUser() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass RtcImage:
		RtcImage() except +
		char* url
		int x
		int y
		int width
		int height
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass LiveTranscoding:
		int width
		int height
		int videoBitrate
		int videoFramerate
		bool lowLatency
		int videoGop
		VIDEO_CODEC_PROFILE_TYPE videoCodecProfile
		unsigned int backgroundColor
		unsigned int userCount
		TranscodingUser* transcodingUsers
		char* transcodingExtraInfo
		char* metadata
		RtcImage* watermark
		RtcImage* backgroundImage
		AUDIO_SAMPLE_RATE_TYPE audioSampleRate
		int audioBitrate
		int audioChannels
		LiveTranscoding() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass CameraCapturerConfiguration:
		CAPTURER_OUTPUT_PREFERENCE preference
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass InjectStreamConfig:
		int width
		int height
		int videoGop
		int videoFramerate
		int videoBitrate
		AUDIO_SAMPLE_RATE_TYPE audioSampleRate
		int audioBitrate
		int audioChannels
		InjectStreamConfig() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum RTMP_STREAM_LIFE_CYCLE_TYPE:
		RTMP_STREAM_LIFE_CYCLE_BIND2CHANNEL = 1
		RTMP_STREAM_LIFE_CYCLE_BIND2OWNER = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass PublisherConfiguration:
		int width
		int height
		int framerate
		int bitrate
		int defaultLayout
		int lifecycle
		bool owner
		int injectStreamWidth
		int injectStreamHeight
		char* injectStreamUrl
		char* publishUrl
		char* rawStreamUrl
		char* extraInfo
		PublisherConfiguration() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef enum VideoContentHint:
		CONTENT_HINT_NONE = 0
		CONTENT_HINT_MOTION = 1
		CONTENT_HINT_DETAILS = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass Rectangle:
		int x
		int y
		int width
		int height
		Rectangle() except +
		Rectangle(int x1,int x2,int x3,int x4) except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass Rect:
		int top
		int left
		int bottom
		int right
		Rect() except +
		Rect(int x1,int x2,int x3,int x4) except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass ScreenCaptureParameters:
		VideoDimensions dimensions
		int frameRate
		int bitrate
		ScreenCaptureParameters() except +
		ScreenCaptureParameters(VideoDimensions& x1,int x2,int x3) except +
		ScreenCaptureParameters(int x1,int x2,int x3,int x4) except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass VideoCanvas:
		view_t view
		int renderMode
		uid_t uid
		void* priv
		VideoCanvas() except +
		VideoCanvas(view_t x1,int x2,uid_t x3) except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass BeautyOptions:
		enum LIGHTENING_CONTRAST_LEVEL:
			LIGHTENING_CONTRAST_LOW = 0
			LIGHTENING_CONTRAST_NORMAL = 1
			LIGHTENING_CONTRAST_HIGH = 2
		LIGHTENING_CONTRAST_LEVEL lighteningContrastLevel
		float lighteningLevel
		float smoothnessLevel
		float rednessLevel
		BeautyOptions(LIGHTENING_CONTRAST_LEVEL x1,float x2,float x3,float x4) except +
		BeautyOptions() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc::BeautyOptions":
		enum LIGHTENING_CONTRAST_LEVEL:
			LIGHTENING_CONTRAST_LOW = 0
			LIGHTENING_CONTRAST_NORMAL = 1
			LIGHTENING_CONTRAST_HIGH = 2
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass IPacketObserver:
		cppclass Packet:
			unsigned char* buffer
			unsigned int size
		bool onSendAudioPacket(Packet& x1)
		bool onSendVideoPacket(Packet& x1)
		bool onReceiveAudioPacket(Packet& x1)
		bool onReceiveVideoPacket(Packet& x1)
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc::IPacketObserver":
	cppclass Packet:
		unsigned char* buffer
		unsigned int size
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass IRtcEngineEventHandler:
		void onWarning(int x1,char *x2)
		void onError(int x1,char *x2)
		void onJoinChannelSuccess(char *x1,uid_t x2,int x3)
		void onRejoinChannelSuccess(char *x1,uid_t x2,int x3)
		void onLeaveChannel(RtcStats& x1)
		void onClientRoleChanged(CLIENT_ROLE_TYPE x1,CLIENT_ROLE_TYPE x2)
		void onUserJoined(uid_t x1,int x2)
		void onUserOffline(uid_t x1,USER_OFFLINE_REASON_TYPE x2)
		void onLastmileQuality(int x1)
		void onLastmileProbeResult(LastmileProbeResult& x1)
		void onConnectionInterrupted()
		void onConnectionLost()
		void onConnectionBanned()
		void onApiCallExecuted(int x1,char *x2,char *x3)
		void onRequestToken()
		void onTokenPrivilegeWillExpire(char *x1)
		void onAudioQuality(uid_t x1,int x2,unsigned short x3,unsigned short x4)
		void onRtcStats(RtcStats& x1)
		void onNetworkQuality(uid_t x1,int x2,int x3)
		void onLocalVideoStats(LocalVideoStats& x1)
		void onRemoteVideoStats(RemoteVideoStats& x1)
		void onRemoteAudioStats(RemoteAudioStats& x1)
		void onAudioVolumeIndication(AudioVolumeInfo*x1,unsigned int x2,int x3)
		void onActiveSpeaker(uid_t x1)
		void onVideoStopped()
		void onFirstLocalVideoFrame(int x1,int x2,int x3)
		void onFirstRemoteVideoDecoded(uid_t x1,int x2,int x3,int x4)
		void onFirstRemoteVideoFrame(uid_t x1,int x2,int x3,int x4)
		void onUserMuteAudio(uid_t x1,bool x2)
		void onUserMuteVideo(uid_t x1,bool x2)
		void onUserEnableVideo(uid_t x1,bool x2)
		void onAudioDeviceStateChanged(char *x1,int x2,int x3)
		void onAudioDeviceVolumeChanged(MEDIA_DEVICE_TYPE x1,int x2,bool x3)
		void onCameraReady()
		void onCameraFocusAreaChanged(int x1,int x2,int x3,int x4)
		void onCameraExposureAreaChanged(int x1,int x2,int x3,int x4)
		void onAudioMixingFinished()
		void onAudioMixingStateChanged(AUDIO_MIXING_STATE_TYPE x1,AUDIO_MIXING_ERROR_TYPE x2)
		void onRemoteAudioMixingBegin()
		void onRemoteAudioMixingEnd()
		void onAudioEffectFinished(int x1)
		void onVideoDeviceStateChanged(char *x1,int x2,int x3)
		void onVideoSizeChanged(uid_t x1,int x2,int x3,int x4)
		void onRemoteVideoStateChanged(uid_t x1,REMOTE_VIDEO_STATE x2)
		void onUserEnableLocalVideo(uid_t x1,bool x2)
		void onStreamMessage(uid_t x1,int x2,char *x3,int x4)
		void onStreamMessageError(uid_t x1,int x2,int x3,int x4,int x5)
		void onMediaEngineLoadSuccess()
		void onMediaEngineStartCallSuccess()
		void onFirstLocalAudioFrame(int x1)
		void onFirstRemoteAudioFrame(uid_t x1,int x2)
		void onStreamPublished(char *x1,int x2)
		void onStreamUnpublished(char *x1)
		void onTranscodingUpdated()
		void onStreamInjectedStatus(char *x1,uid_t x2,int x3)
		void onLocalPublishFallbackToAudioOnly(bool x1)
		void onRemoteSubscribeFallbackToAudioOnly(uid_t x1,bool x2)
		void onRemoteAudioTransportStats(uid_t x1,unsigned short x2,unsigned short x3,unsigned short x4)
		void onRemoteVideoTransportStats(uid_t x1,unsigned short x2,unsigned short x3,unsigned short x4)
		void onMicrophoneEnabled(bool x1)
		void onConnectionStateChanged(CONNECTION_STATE_TYPE x1,CONNECTION_CHANGED_REASON_TYPE x2)
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass IVideoDeviceCollection:
		int getCount()
		int getDevice(int x1,char *x2,char *x3)
		int setDevice(char *x1)
		void release()
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass IVideoDeviceManager:
		IVideoDeviceCollection * enumerateVideoDevices()
		int startDeviceTest(view_t x1)
		int stopDeviceTest()
		int setDevice(char *x1)
		int getDevice(char *x1)
		void release()
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass IAudioDeviceCollection:
		int getCount()
		int getDevice(int x1,char *x2,char *x3)
		int setDevice(char *x1)
		int setApplicationVolume(int x1)
		int getApplicationVolume(int& x1)
		int setApplicationMute(bool x1)
		int isApplicationMute(bool& x1)
		void release()
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass IAudioDeviceManager:
		IAudioDeviceCollection * enumeratePlaybackDevices()
		IAudioDeviceCollection * enumerateRecordingDevices()
		int setPlaybackDevice(char *x1)
		int setRecordingDevice(char *x1)
		int startPlaybackDeviceTest(char *x1)
		int stopPlaybackDeviceTest()
		int setPlaybackDeviceVolume(int x1)
		int getPlaybackDeviceVolume(int *x1)
		int setRecordingDeviceVolume(int x1)
		int getRecordingDeviceVolume(int *x1)
		int setPlaybackDeviceMute(bool x1)
		int getPlaybackDeviceMute(bool *x1)
		int setRecordingDeviceMute(bool x1)
		int getRecordingDeviceMute(bool *x1)
		int startRecordingDeviceTest(int x1)
		int stopRecordingDeviceTest()
		int getPlaybackDevice(char *x1)
		int getPlaybackDeviceInfo(char *x1,char *x2)
		int getRecordingDevice(char *x1)
		int getRecordingDeviceInfo(char *x1,char *x2)
		int startAudioDeviceLoopbackTest(int x1)
		int stopAudioDeviceLoopbackTest()
		void release()
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass RtcEngineContext:
		IRtcEngineEventHandler* eventHandler
		char* appId
		RtcEngineContext() except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass IRtcEngine:
		int initialize(RtcEngineContext& x1)
		void release(bool x1)
		int setChannelProfile(CHANNEL_PROFILE_TYPE x1)
		int setClientRole(CLIENT_ROLE_TYPE x1)
		int joinChannel(char *x1,char *x2,char *x3,uid_t x4)
		int leaveChannel()
		int renewToken(char *x1)
		int queryInterface(INTERFACE_ID_TYPE x1,void * *x2)
		int startEchoTest()
		int startEchoTest(int x1)
		int stopEchoTest()
		int enableVideo()
		int disableVideo()
		int setVideoProfile(VIDEO_PROFILE_TYPE x1,bool x2)
		int setVideoEncoderConfiguration(VideoEncoderConfiguration& x1)
		int setupLocalVideo(VideoCanvas& x1)
		int setupRemoteVideo(VideoCanvas& x1)
		int startPreview()
		int setRemoteUserPriority(uid_t x1,PRIORITY_TYPE x2)
		int stopPreview()
		int enableAudio()
		int enableLocalAudio(bool x1)
		int disableAudio()
		int setAudioProfile(AUDIO_PROFILE_TYPE x1,AUDIO_SCENARIO_TYPE x2)
		int startScreenCaptureByDisplayId(unsigned int x1,Rectangle& x2,ScreenCaptureParameters& x3)
		int startScreenCaptureByWindowId(view_t x1,Rectangle& x2,ScreenCaptureParameters& x3)
		int setScreenCaptureContentHint(VideoContentHint x1)
		int updateScreenCaptureParameters(ScreenCaptureParameters& x1)
		int updateScreenCaptureRegion(Rectangle& x1)
		int stopScreenCapture()
		ctypedef unsigned int WindowIDType
		int startScreenCapture(WindowIDType x1,int x2,Rect*x3,int x4)
		int updateScreenCaptureRegion(Rect*x1)
		int getCallId(AString& x1)
		int rate(char *x1,int x2,char *x3)
		int complain(char *x1,char *x2)
		char * getVersion(int *x1)
		int enableLastmileTest()
		int disableLastmileTest()
		int startLastmileProbeTest(LastmileProbeConfig& x1)
		int stopLastmileProbeTest()
		char * getErrorDescription(int x1)
		int setEncryptionSecret(char *x1)
		int setEncryptionMode(char *x1)
		int registerPacketObserver(IPacketObserver*x1)
		int createDataStream(int *x1,bool x2,bool x3)
		int sendStreamMessage(int x1,char *x2,int x3)
		int addPublishStreamUrl(char *x1,bool x2)
		int removePublishStreamUrl(char *x1)
		int setLiveTranscoding(LiveTranscoding& x1)
		int configPublisher(PublisherConfiguration& x1)
		int setVideoCompositingLayout(VideoCompositingLayout& x1)
		int clearVideoCompositingLayout()
		int addVideoWatermark(RtcImage& x1)
		int clearVideoWatermarks()
		int setBeautyEffectOptions(bool x1,BeautyOptions x2)
		int addInjectStreamUrl(char *x1,InjectStreamConfig& x2)
		int removeInjectStreamUrl(char *x1)
		bool registerEventHandler(IRtcEngineEventHandler*x1)
		bool unregisterEventHandler(IRtcEngineEventHandler*x1)
		CONNECTION_STATE_TYPE getConnectionState()
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass IRtcEngineParameter:
		void release()
		int setBool(char *x1,bool x2)
		int setInt(char *x1,int x2)
		int setUInt(char *x1,unsigned int x2)
		int setNumber(char *x1,double x2)
		int setString(char *x1,char *x2)
		int setObject(char *x1,char *x2)
		int getBool(char *x1,bool& x2)
		int getInt(char *x1,int& x2)
		int getUInt(char *x1,unsigned int& x2)
		int getNumber(char *x1,double& x2)
		int getString(char *x1,AString& x2)
		int getObject(char *x1,AString& x2)
		int getArray(char *x1,AString& x2)
		int setParameters(char *x1)
		int setProfile(char *x1,bool x2)
		int convertPath(char *x1,AString& x2)
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass AAudioDeviceManager:
		AAudioDeviceManager() except +
		AAudioDeviceManager(IRtcEngine*x1) except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass AVideoDeviceManager:
		AVideoDeviceManager() except +
		AVideoDeviceManager(IRtcEngine*x1) except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass AParameter:
		AParameter() except +
		AParameter(IRtcEngine& x1) except +
		AParameter(IRtcEngine*x1) except +
		AParameter(IRtcEngineParameter*x1) except +
cdef extern from "include/IAgoraRtcEngine.h"namespace "agora::rtc":
	cdef cppclass RtcEngineParameters:
		RtcEngineParameters() except +
		RtcEngineParameters(IRtcEngine& x1) except +
		RtcEngineParameters(IRtcEngine*x1) except +
		int enableLocalVideo(bool x1)
		int muteLocalVideoStream(bool x1)
		int muteAllRemoteVideoStreams(bool x1)
		int setDefaultMuteAllRemoteVideoStreams(bool x1)
		int muteRemoteVideoStream(uid_t x1,bool x2)
		int setPlaybackDeviceVolume(int x1)
		int startAudioRecording(char *x1,AUDIO_RECORDING_QUALITY_TYPE x2)
		int stopAudioRecording()
		int startAudioMixing(char *x1,bool x2,bool x3,int x4)
		int stopAudioMixing()
		int pauseAudioMixing()
		int resumeAudioMixing()
		int adjustAudioMixingVolume(int x1)
		int adjustAudioMixingPlayoutVolume(int x1)
		int adjustAudioMixingPublishVolume(int x1)
		int getAudioMixingDuration()
		int getAudioMixingCurrentPosition()
		int setAudioMixingPosition(int x1)
		int getEffectsVolume()
		int setEffectsVolume(int x1)
		int setVolumeOfEffect(int x1,int x2)
		int playEffect(int x1,char *x2,int x3,double x4,double x5,int x6,bool x7)
		int stopEffect(int x1)
		int stopAllEffects()
		int preloadEffect(int x1,char *x2)
		int unloadEffect(int x1)
		int pauseEffect(int x1)
		int pauseAllEffects()
		int resumeEffect(int x1)
		int resumeAllEffects()
		int enableSoundPositionIndication(bool x1)
		int setRemoteVoicePosition(int x1,double x2,double x3)
		int setLocalVoicePitch(double x1)
		int setLocalVoiceEqualization(AUDIO_EQUALIZATION_BAND_FREQUENCY x1,int x2)
		int setLocalVoiceReverb(AUDIO_REVERB_TYPE x1,int x2)
		int setLocalVoiceChanger(VOICE_CHANGER_PRESET x1)
		int setLocalVoiceReverbPreset(AUDIO_REVERB_PRESET x1)
		int pauseAudio()
		int resumeAudio()
		int setHighQualityAudioParameters(bool x1,bool x2,bool x3)
		int adjustRecordingSignalVolume(int x1)
		int adjustPlaybackSignalVolume(int x1)
		int enableAudioVolumeIndication(int x1,int x2)
		int muteLocalAudioStream(bool x1)
		int muteRemoteAudioStream(uid_t x1,bool x2)
		int muteAllRemoteAudioStreams(bool x1)
		int setDefaultMuteAllRemoteAudioStreams(bool x1)
		int setExternalAudioSource(bool x1,int x2,int x3)
		int setExternalAudioSink(bool x1,int x2,int x3)
		int setLogFile(char *x1)
		int setLogFilter(unsigned int x1)
		int setLogFileSize(unsigned int x1)
		int setLocalRenderMode(RENDER_MODE_TYPE x1)
		int setRemoteRenderMode(uid_t x1,RENDER_MODE_TYPE x2)
		int setCameraCapturerConfiguration(CameraCapturerConfiguration& x1)
		int enableDualStreamMode(bool x1)
		int setRemoteVideoStreamType(uid_t x1,REMOTE_VIDEO_STREAM_TYPE x2)
		int setRemoteDefaultVideoStreamType(REMOTE_VIDEO_STREAM_TYPE x1)
		int setRecordingAudioFrameParameters(int x1,int x2,RAW_AUDIO_FRAME_OP_MODE_TYPE x3,int x4)
		int setPlaybackAudioFrameParameters(int x1,int x2,RAW_AUDIO_FRAME_OP_MODE_TYPE x3,int x4)
		int setMixedAudioFrameParameters(int x1,int x2)
		int enableWebSdkInteroperability(bool x1)
		int setVideoQualityParameters(bool x1)
		int setLocalVideoMirrorMode(VIDEO_MIRROR_MODE_TYPE x1)
		int setLocalPublishFallbackOption(STREAM_FALLBACK_OPTIONS x1)
		int setRemoteSubscribeFallbackOption(STREAM_FALLBACK_OPTIONS x1)
		int enableLoopbackRecording(bool x1,char *x2)
		int setInEarMonitoringVolume(int x1)
cdef extern from "include/IAgoraRtcEngine.h":
	IRtcEngine * createAgoraRtcEngine()
cdef extern from "EventHandlerWrapper.h":
	cdef cppclass EventHandler:
		EventHandler() except +
		void onJoinChannelSuccess(char *x1,uid_t x2,int x3)
		void onRejoinChannelSuccess(char *x1,uid_t x2,int x3)
		void onLeaveChannel(RtcStats& x1)
		void onUserJoined(uid_t x1,int x2)
		void onClientRoleChanged(CLIENT_ROLE_TYPE x1,CLIENT_ROLE_TYPE x2)
		void onUserOffline(uid_t x1,USER_OFFLINE_REASON_TYPE x2)
		void onLastmileQuality(int x1)
		void onConnectionInterrupted()
		void onConnectionLost()
		void onApiCallExecuted(int x1,char *x2,char *x3)
		void onRequestToken()
		void onTokenPrivilegeWillExpire(char *x1)
		void onAudioQuality(uid_t x1,int x2,unsigned short x3,unsigned short x4)
		void onRtcStats(RtcStats& x1)
		void onNetworkQuality(uid_t x1,int x2,int x3)
		void onLocalVideoStats(LocalVideoStats& x1)
		void onRemoteVideoStats(RemoteVideoStats& x1)
		void onRemoteAudioStats(RemoteAudioStats& x1)
		void onAudioVolumeIndication(AudioVolumeInfo*x1,unsigned int x2,int x3)
		void onActiveSpeaker(uid_t x1)
		void onVideoStopped()
		void onFirstLocalVideoFrame(int x1,int x2,int x3)
		void onFirstRemoteVideoDecoded(uid_t x1,int x2,int x3,int x4)
		void onFirstRemoteVideoFrame(uid_t x1,int x2,int x3,int x4)
		void onUserMuteAudio(uid_t x1,bool x2)
		void onUserMuteVideo(uid_t x1,bool x2)
		void onUserEnableVideo(uid_t x1,bool x2)
		void onAudioDeviceStateChanged(char *x1,int x2,int x3)
		void onCameraReady()
		void onVideoDeviceStateChanged(char *x1,int x2,int x3)
		void onStreamMessage(uid_t x1,int x2,char *x3,int x4)
		void onConnectionStateChanged(CONNECTION_STATE_TYPE x1,CONNECTION_CHANGED_REASON_TYPE x2)
		void onFirstLocalAudioFrame(int x1)
		void onMicrophoneEnabled(bool x1)
		void onRemoteVideoStateChanged(uid_t x1,REMOTE_VIDEO_STATE x2)
		void onUserEnableLocalVideo(uid_t x1,bool x2)
		void onFirstRemoteAudioFrame(uid_t x1,int x2)
		void onRemoteAudioTransportStats(uid_t x1,unsigned short x2,unsigned short x3,unsigned short x4)
		void onRemoteVideoTransportStats(uid_t x1,unsigned short x2,unsigned short x3,unsigned short x4)
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef enum MEDIA_SOURCE_TYPE:
		AUDIO_PLAYOUT_SOURCE = 0
		AUDIO_RECORDING_SOURCE = 1
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass IAudioFrameObserver:
		enum AUDIO_FRAME_TYPE:
			FRAME_TYPE_PCM16 = 0
		cppclass AudioFrame:
			AUDIO_FRAME_TYPE type
			int samples
			int bytesPerSample
			int channels
			int samplesPerSec
			void* buffer
			int renderTimeMs
			int avsync_type
		bool onRecordAudioFrame(AudioFrame& x1)
		bool onPlaybackAudioFrame(AudioFrame& x1)
		bool onMixedAudioFrame(AudioFrame& x1)
		bool onPlaybackAudioFrameBeforeMixing(unsigned int x1,AudioFrame& x2)
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media::IAudioFrameObserver":
		enum AUDIO_FRAME_TYPE:
			FRAME_TYPE_PCM16 = 0
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media::IAudioFrameObserver":
	cppclass AudioFrame:
		AUDIO_FRAME_TYPE type
		int samples
		int bytesPerSample
		int channels
		int samplesPerSec
		void* buffer
		int renderTimeMs
		int avsync_type
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass IVideoFrameObserver:
		enum VIDEO_FRAME_TYPE:
			FRAME_TYPE_YUV420 = 0
		cppclass VideoFrame:
			VIDEO_FRAME_TYPE type
			int width
			int height
			int yStride
			int uStride
			int vStride
			void* yBuffer
			void* uBuffer
			void* vBuffer
			int rotation
			int renderTimeMs
			int avsync_type
		bool onCaptureVideoFrame(VideoFrame& x1)
		bool onRenderVideoFrame(unsigned int x1,VideoFrame& x2)
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media::IVideoFrameObserver":
		enum VIDEO_FRAME_TYPE:
			FRAME_TYPE_YUV420 = 0
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media::IVideoFrameObserver":
	cppclass VideoFrame:
		VIDEO_FRAME_TYPE type
		int width
		int height
		int yStride
		int uStride
		int vStride
		void* yBuffer
		void* uBuffer
		void* vBuffer
		int rotation
		int renderTimeMs
		int avsync_type
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass IVideoFrame:
		enum PLANE_TYPE:
			Y_PLANE = 0
			U_PLANE = 1
			V_PLANE = 2
			NUM_OF_PLANES = 3
		enum VIDEO_TYPE:
			VIDEO_TYPE_UNKNOWN = 0
			VIDEO_TYPE_I420 = 1
			VIDEO_TYPE_IYUV = 2
			VIDEO_TYPE_RGB24 = 3
			VIDEO_TYPE_ABGR = 4
			VIDEO_TYPE_ARGB = 5
			VIDEO_TYPE_ARGB4444 = 6
			VIDEO_TYPE_RGB565 = 7
			VIDEO_TYPE_ARGB1555 = 8
			VIDEO_TYPE_YUY2 = 9
			VIDEO_TYPE_YV12 = 10
			VIDEO_TYPE_UYVY = 11
			VIDEO_TYPE_MJPG = 12
			VIDEO_TYPE_NV21 = 13
			VIDEO_TYPE_NV12 = 14
			VIDEO_TYPE_BGRA = 15
			VIDEO_TYPE_RGBA = 16
		void release()
		unsigned char * buffer(PLANE_TYPE x1)
		int convertFrame(VIDEO_TYPE x1,int x2,unsigned char *x3)
		int allocated_size(PLANE_TYPE x1)
		int stride(PLANE_TYPE x1)
		int width()
		int height()
		unsigned int timestamp()
		long long render_time_ms()
		bool IsZeroSize()
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media::IVideoFrame":
		enum PLANE_TYPE:
			Y_PLANE = 0
			U_PLANE = 1
			V_PLANE = 2
			NUM_OF_PLANES = 3
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media::IVideoFrame":
		enum VIDEO_TYPE:
			VIDEO_TYPE_UNKNOWN = 0
			VIDEO_TYPE_I420 = 1
			VIDEO_TYPE_IYUV = 2
			VIDEO_TYPE_RGB24 = 3
			VIDEO_TYPE_ABGR = 4
			VIDEO_TYPE_ARGB = 5
			VIDEO_TYPE_ARGB4444 = 6
			VIDEO_TYPE_RGB565 = 7
			VIDEO_TYPE_ARGB1555 = 8
			VIDEO_TYPE_YUY2 = 9
			VIDEO_TYPE_YV12 = 10
			VIDEO_TYPE_UYVY = 11
			VIDEO_TYPE_MJPG = 12
			VIDEO_TYPE_NV21 = 13
			VIDEO_TYPE_NV12 = 14
			VIDEO_TYPE_BGRA = 15
			VIDEO_TYPE_RGBA = 16
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass IExternalVideoRenderCallback:
		void onViewSizeChanged(int x1,int x2)
		void onViewDestroyed()
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass ExternalVideoRenerContext:
		IExternalVideoRenderCallback* renderCallback
		void* view
		int renderMode
		int zOrder
		float left
		float top
		float right
		float bottom
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass IExternalVideoRender:
		void release()
		int initialize()
		int deliverFrame(IVideoFrame& x1,int x2,bool x3)
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass IExternalVideoRenderFactory:
		IExternalVideoRender * createRenderInstance(ExternalVideoRenerContext& x1)
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass ExternalVideoFrame:
		enum VIDEO_BUFFER_TYPE:
			VIDEO_BUFFER_RAW_DATA = 1
		enum VIDEO_PIXEL_FORMAT:
			VIDEO_PIXEL_UNKNOWN = 0
			VIDEO_PIXEL_I420 = 1
			VIDEO_PIXEL_BGRA = 2
			VIDEO_PIXEL_NV12 = 8
		VIDEO_BUFFER_TYPE type
		VIDEO_PIXEL_FORMAT format
		void* buffer
		int stride
		int height
		int cropLeft
		int cropTop
		int cropRight
		int cropBottom
		int rotation
		long long timestamp
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media::ExternalVideoFrame":
		enum VIDEO_BUFFER_TYPE:
			VIDEO_BUFFER_RAW_DATA = 1
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media::ExternalVideoFrame":
		enum VIDEO_PIXEL_FORMAT:
			VIDEO_PIXEL_UNKNOWN = 0
			VIDEO_PIXEL_I420 = 1
			VIDEO_PIXEL_BGRA = 2
			VIDEO_PIXEL_NV12 = 8
cdef extern from "include/IAgoraMediaEngine.h"namespace "agora::media":
	cdef cppclass IMediaEngine:
		void release()
		int registerAudioFrameObserver(IAudioFrameObserver*x1)
		int registerVideoFrameObserver(IVideoFrameObserver*x1)
		int registerVideoRenderFactory(IExternalVideoRenderFactory*x1)
		int pushAudioFrame(MEDIA_SOURCE_TYPE x1,AudioFrame*x2,bool x3)
		int pushAudioFrame(AudioFrame*x1)
		int pullAudioFrame(AudioFrame*x1)
		int setExternalVideoSource(bool x1,bool x2)
		int pushVideoFrame(ExternalVideoFrame*x1)
cdef extern from "VideoFrameObserverWrapper.h":
	cdef cppclass VideoFrameObserver:
		VideoFrameObserver() except +
		bool onCaptureVideoFrame(VideoFrame& x1)
		bool onRenderVideoFrame(unsigned int x1,VideoFrame& x2)
cdef extern from "ptr_convert.cpp":
	IMediaEngine* getMediaEngine(IRtcEngine*)