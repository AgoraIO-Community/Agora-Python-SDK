# distutils: language=c++
import cython
from libc.stdlib cimport free
cimport IAgoraRtcEngine
from libcpp cimport bool
from IAgoraRtcEngine cimport IString
cdef class pyIString:
	cdef IString *c_IString
	def empty(self):
		return self.c_IString.empty()
	def c_str(self):
		return cython.operator.dereference(self.c_IString.c_str())
	def data(self):
		return cython.operator.dereference(self.c_IString.data())
	def length(self):
		return self.c_IString.length()
	def release(self):
		return self.c_IString.release()
from IAgoraRtcEngine cimport AString
cdef class pyAString:
	cdef AString *c_AString
	def get(self):
		tmp = pyIString()
		tmp.c_IString=(self.c_AString.get())
		return tmp
	def release(self):
		tmp = pyIString()
		tmp.c_IString=(self.c_AString.release())
		return tmp
	def reset(self,pyIString x1):
		self.c_AString.reset(x1.c_IString)
	def __cinit__(self):
		self.c_AString = new AString()
	def destruct(self):
		free(self.c_AString)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_AString = new AString()
	def construct_2(self,pyIString x1):
		self.c_AString = new AString(x1.c_IString)
class pyINTERFACE_ID_TYPE:
	AGORA_IID_AUDIO_DEVICE_MANAGER = 1
	AGORA_IID_VIDEO_DEVICE_MANAGER = 2
	AGORA_IID_RTC_ENGINE_PARAMETER = 3
	AGORA_IID_MEDIA_ENGINE = 4
	AGORA_IID_SIGNALING_ENGINE = 8
class pyWARN_CODE_TYPE:
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
class pyERROR_CODE_TYPE:
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
class pyLOG_FILTER_TYPE:
	LOG_FILTER_OFF = 0
	LOG_FILTER_DEBUG = 0x080f
	LOG_FILTER_INFO = 0x000f
	LOG_FILTER_WARN = 0x000e
	LOG_FILTER_ERROR = 0x000c
	LOG_FILTER_CRITICAL = 0x0008
	LOG_FILTER_MASK = 0x80f
from IAgoraRtcEngine cimport ISignalingEngine
cdef class pyISignalingEngine:
	cdef ISignalingEngine *c_ISignalingEngine
	@property
	def addition(self):
		return self.c_ISignalingEngine.addition
	@addition.setter
	def addition(self, bool addition):
		self.c_ISignalingEngine.addition=addition
	def __cinit__(self):
		self.c_ISignalingEngine = new ISignalingEngine()
	def destruct(self):
		free(self.c_ISignalingEngine)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport AgoraServiceContext
cdef class pyAgoraServiceContext:
	cdef AgoraServiceContext *c_AgoraServiceContext
	def __cinit__(self):
		self.c_AgoraServiceContext = new AgoraServiceContext()
	def destruct(self):
		free(self.c_AgoraServiceContext)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport IAgoraService
cdef class pyIAgoraService:
	cdef IAgoraService *c_IAgoraService
	def release(self):
		return self.c_IAgoraService.release()
	def initialize(self,pyAgoraServiceContext x1):
		return self.c_IAgoraService.initialize(cython.operator.dereference(x1.c_AgoraServiceContext))
	def getVersion(self,int x1):
		return cython.operator.dereference(self.c_IAgoraService.getVersion(&x1))
	def createRtcEngine(self):
		tmp = pyIRtcEngine()
		tmp.c_IRtcEngine=(self.c_IAgoraService.createRtcEngine())
		return tmp
	def createSignalingEngine(self):
		tmp = pyISignalingEngine()
		tmp.c_ISignalingEngine=(self.c_IAgoraService.createSignalingEngine())
		return tmp
def pygetAgoraSdkVersion(int x1):
	return (getAgoraSdkVersion(&x1))
def pygetAgoraSdkErrorDescription(int x1):
	return (getAgoraSdkErrorDescription(x1))
def pycreateAgoraService():
	tmp = pyIAgoraService()
	tmp.c_IAgoraService = (createAgoraService())
	return tmp
class pyMAX_DEVICE_ID_LENGTH_TYPE:
	MAX_DEVICE_ID_LENGTH = 512
class pyQUALITY_REPORT_FORMAT_TYPE:
	QUALITY_REPORT_JSON = 0
	QUALITY_REPORT_HTML = 1
class pyMEDIA_ENGINE_EVENT_CODE_TYPE:
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
class pyAUDIO_MIXING_STATE_TYPE:
	AUDIO_MIXING_STATE_PLAYING = 710
	AUDIO_MIXING_STATE_PAUSED = 711
	AUDIO_MIXING_STATE_STOPPED = 713
	AUDIO_MIXING_STATE_FAILED = 714
class pyAUDIO_MIXING_ERROR_TYPE:
	AUDIO_MIXING_ERROR_CAN_NOT_OPEN = 701
	AUDIO_MIXING_ERROR_TOO_FREQUENT_CALL = 702
	AUDIO_MIXING_ERROR_INTERRUPTED_EOF = 703
	AUDIO_MIXING_ERROR_OK = 0
class pyMEDIA_DEVICE_STATE_TYPE:
	MEDIA_DEVICE_STATE_ACTIVE = 1
	MEDIA_DEVICE_STATE_DISABLED = 2
	MEDIA_DEVICE_STATE_NOT_PRESENT = 4
	MEDIA_DEVICE_STATE_UNPLUGGED = 8
class pyMEDIA_DEVICE_TYPE:
	UNKNOWN_AUDIO_DEVICE = -1
	AUDIO_PLAYOUT_DEVICE = 0
	AUDIO_RECORDING_DEVICE = 1
	VIDEO_RENDER_DEVICE = 2
	VIDEO_CAPTURE_DEVICE = 3
	AUDIO_APPLICATION_PLAYOUT_DEVICE = 4
class pyAUDIO_RECORDING_QUALITY_TYPE:
	AUDIO_RECORDING_QUALITY_LOW = 0
	AUDIO_RECORDING_QUALITY_MEDIUM = 1
	AUDIO_RECORDING_QUALITY_HIGH = 2
class pyQUALITY_TYPE:
	QUALITY_UNKNOWN = 0
	QUALITY_EXCELLENT = 1
	QUALITY_GOOD = 2
	QUALITY_POOR = 3
	QUALITY_BAD = 4
	QUALITY_VBAD = 5
	QUALITY_DOWN = 6
	QUALITY_UNSUPPORTED = 7
	QUALITY_DETECTING = 8
class pyRENDER_MODE_TYPE:
	RENDER_MODE_HIDDEN = 1
	RENDER_MODE_FIT = 2
	RENDER_MODE_ADAPTIVE = 3
class pyVIDEO_MIRROR_MODE_TYPE:
	VIDEO_MIRROR_MODE_AUTO = 0
	VIDEO_MIRROR_MODE_ENABLED = 1
	VIDEO_MIRROR_MODE_DISABLED = 2
class pyVIDEO_PROFILE_TYPE:
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
class pyAUDIO_PROFILE_TYPE:
	AUDIO_PROFILE_DEFAULT = 0
	AUDIO_PROFILE_SPEECH_STANDARD = 1
	AUDIO_PROFILE_MUSIC_STANDARD = 2
	AUDIO_PROFILE_MUSIC_STANDARD_STEREO = 3
	AUDIO_PROFILE_MUSIC_HIGH_QUALITY = 4
	AUDIO_PROFILE_MUSIC_HIGH_QUALITY_STEREO = 5
	AUDIO_PROFILE_IOT = 6
	AUDIO_PROFILE_NUM = 7
class pyAUDIO_SCENARIO_TYPE:
	AUDIO_SCENARIO_DEFAULT = 0
	AUDIO_SCENARIO_CHATROOM_ENTERTAINMENT = 1
	AUDIO_SCENARIO_EDUCATION = 2
	AUDIO_SCENARIO_GAME_STREAMING = 3
	AUDIO_SCENARIO_SHOWROOM = 4
	AUDIO_SCENARIO_CHATROOM_GAMING = 5
	AUDIO_SCENARIO_IOT = 6
	AUDIO_SCENARIO_NUM = 7
class pyCHANNEL_PROFILE_TYPE:
	CHANNEL_PROFILE_COMMUNICATION = 0
	CHANNEL_PROFILE_LIVE_BROADCASTING = 1
	CHANNEL_PROFILE_GAME = 2
class pyCLIENT_ROLE_TYPE:
	CLIENT_ROLE_BROADCASTER = 1
	CLIENT_ROLE_AUDIENCE = 2
class pyUSER_OFFLINE_REASON_TYPE:
	USER_OFFLINE_QUIT = 0
	USER_OFFLINE_DROPPED = 1
	USER_OFFLINE_BECOME_AUDIENCE = 2
class pyINJECT_STREAM_STATUS:
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
class pyREMOTE_VIDEO_STREAM_TYPE:
	REMOTE_VIDEO_STREAM_HIGH = 0
	REMOTE_VIDEO_STREAM_LOW = 1
class pyRAW_AUDIO_FRAME_OP_MODE_TYPE:
	RAW_AUDIO_FRAME_OP_MODE_READ_ONLY = 0
	RAW_AUDIO_FRAME_OP_MODE_WRITE_ONLY = 1
	RAW_AUDIO_FRAME_OP_MODE_READ_WRITE = 2
class pyAUDIO_SAMPLE_RATE_TYPE:
	AUDIO_SAMPLE_RATE_32000 = 32000
	AUDIO_SAMPLE_RATE_44100 = 44100
	AUDIO_SAMPLE_RATE_48000 = 48000
class pyVIDEO_CODEC_PROFILE_TYPE:
	VIDEO_CODEC_PROFILE_BASELINE = 66
	VIDEO_CODEC_PROFILE_MAIN = 77
	VIDEO_CODEC_PROFILE_HIGH = 100
class pyAUDIO_EQUALIZATION_BAND_FREQUENCY:
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
class pyAUDIO_REVERB_TYPE:
	AUDIO_REVERB_DRY_LEVEL = 0
	AUDIO_REVERB_WET_LEVEL = 1
	AUDIO_REVERB_ROOM_SIZE = 2
	AUDIO_REVERB_WET_DELAY = 3
	AUDIO_REVERB_STRENGTH = 4
class pyVOICE_CHANGER_PRESET:
	VOICE_CHANGER_OFF = 0
	VOICE_CHANGER_OLDMAN = 1
	VOICE_CHANGER_BABYBOY = 2
	VOICE_CHANGER_BABYGIRL = 3
	VOICE_CHANGER_ZHUBAJIE = 4
	VOICE_CHANGER_ETHEREAL = 5
	VOICE_CHANGER_HULK = 6
class pyAUDIO_REVERB_PRESET:
	AUDIO_REVERB_OFF = 0
	AUDIO_REVERB_POPULAR = 1
	AUDIO_REVERB_RNB = 2
	AUDIO_REVERB_ROCK = 3
	AUDIO_REVERB_HIPHOP = 4
	AUDIO_REVERB_VOCAL_CONCERT = 5
	AUDIO_REVERB_KTV = 6
	AUDIO_REVERB_STUDIO = 7
class pyREMOTE_VIDEO_STATE:
	REMOTE_VIDEO_STATE_RUNNING = 1
	REMOTE_VIDEO_STATE_FROZEN = 2
class pyFRAME_RATE:
	FRAME_RATE_FPS_1 = 1
	FRAME_RATE_FPS_7 = 7
	FRAME_RATE_FPS_10 = 10
	FRAME_RATE_FPS_15 = 15
	FRAME_RATE_FPS_24 = 24
	FRAME_RATE_FPS_30 = 30
	FRAME_RATE_FPS_60 = 60
class pyORIENTATION_MODE:
	ORIENTATION_MODE_ADAPTIVE = 0
	ORIENTATION_MODE_FIXED_LANDSCAPE = 1
	ORIENTATION_MODE_FIXED_PORTRAIT = 2
class pyDEGRADATION_PREFERENCE:
	MAINTAIN_QUALITY = 0
	MAINTAIN_FRAMERATE = 1
	MAINTAIN_BALANCED = 2
class pySTREAM_FALLBACK_OPTIONS:
	STREAM_FALLBACK_OPTION_DISABLED = 0
	STREAM_FALLBACK_OPTION_VIDEO_STREAM_LOW = 1
	STREAM_FALLBACK_OPTION_AUDIO_ONLY = 2
class pyCAPTURER_OUTPUT_PREFERENCE:
	CAPTURER_OUTPUT_PREFERENCE_AUTO = 0
	CAPTURER_OUTPUT_PREFERENCE_PERFORMANCE = 1
	CAPTURER_OUTPUT_PREFERENCE_PREVIEW = 2
class pyPRIORITY_TYPE:
	PRIORITY_HIGH = 50
	PRIORITY_NORMAL = 100
class pyCONNECTION_STATE_TYPE:
	CONNECTION_STATE_DISCONNECTED = 1
	CONNECTION_STATE_CONNECTING = 2
	CONNECTION_STATE_CONNECTED = 3
	CONNECTION_STATE_RECONNECTING = 4
	CONNECTION_STATE_FAILED = 5
class pyCONNECTION_CHANGED_REASON_TYPE:
	CONNECTION_CHANGED_CONNECTING = 0
	CONNECTION_CHANGED_JOIN_SUCCESS = 1
	CONNECTION_CHANGED_INTERRUPTED = 2
	CONNECTION_CHANGED_BANNED_BY_SERVER = 3
	CONNECTION_CHANGED_JOIN_FAILED = 4
	CONNECTION_CHANGED_LEAVE_CHANNEL = 5
class pyLASTMILE_PROBE_RESULT_STATE:
	LASTMILE_PROBE_RESULT_COMPLETE = 1
	LASTMILE_PROBE_RESULT_INCOMPLETE_NO_BWE = 2
	LASTMILE_PROBE_RESULT_UNAVAILABLE = 3
from IAgoraRtcEngine cimport LastmileProbeOneWayResult
cdef class pyLastmileProbeOneWayResult:
	cdef LastmileProbeOneWayResult *c_LastmileProbeOneWayResult
	@property
	def packetLossRate(self):
		return self.c_LastmileProbeOneWayResult.packetLossRate
	@packetLossRate.setter
	def packetLossRate(self, unsigned int packetLossRate):
		self.c_LastmileProbeOneWayResult.packetLossRate=packetLossRate
	@property
	def jitter(self):
		return self.c_LastmileProbeOneWayResult.jitter
	@jitter.setter
	def jitter(self, unsigned int jitter):
		self.c_LastmileProbeOneWayResult.jitter=jitter
	@property
	def availableBandwidth(self):
		return self.c_LastmileProbeOneWayResult.availableBandwidth
	@availableBandwidth.setter
	def availableBandwidth(self, unsigned int availableBandwidth):
		self.c_LastmileProbeOneWayResult.availableBandwidth=availableBandwidth
	def __cinit__(self):
		self.c_LastmileProbeOneWayResult = new LastmileProbeOneWayResult()
	def destruct(self):
		free(self.c_LastmileProbeOneWayResult)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport LastmileProbeResult
cdef class pyLastmileProbeResult:
	cdef LastmileProbeResult *c_LastmileProbeResult
	@property
	def state(self):
		return self.c_LastmileProbeResult.state
	@state.setter
	def state(self, LASTMILE_PROBE_RESULT_STATE state):
		self.c_LastmileProbeResult.state=state
	@property
	def uplinkReport(self):
		tmp = pyLastmileProbeOneWayResult()
		tmp.c_LastmileProbeOneWayResult = &self.c_LastmileProbeResult.uplinkReport
		return tmp
	@uplinkReport.setter
	def uplinkReport(self,pyLastmileProbeOneWayResult uplinkReport):
		self.c_LastmileProbeResult.uplinkReport=cython.operator.dereference(uplinkReport.c_LastmileProbeOneWayResult)
	@property
	def downlinkReport(self):
		tmp = pyLastmileProbeOneWayResult()
		tmp.c_LastmileProbeOneWayResult = &self.c_LastmileProbeResult.downlinkReport
		return tmp
	@downlinkReport.setter
	def downlinkReport(self,pyLastmileProbeOneWayResult downlinkReport):
		self.c_LastmileProbeResult.downlinkReport=cython.operator.dereference(downlinkReport.c_LastmileProbeOneWayResult)
	@property
	def rtt(self):
		return self.c_LastmileProbeResult.rtt
	@rtt.setter
	def rtt(self, unsigned int rtt):
		self.c_LastmileProbeResult.rtt=rtt
	def __cinit__(self):
		self.c_LastmileProbeResult = new LastmileProbeResult()
	def destruct(self):
		free(self.c_LastmileProbeResult)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport LastmileProbeConfig
cdef class pyLastmileProbeConfig:
	cdef LastmileProbeConfig *c_LastmileProbeConfig
	@property
	def probeUplink(self):
		return self.c_LastmileProbeConfig.probeUplink
	@probeUplink.setter
	def probeUplink(self, bool probeUplink):
		self.c_LastmileProbeConfig.probeUplink=probeUplink
	@property
	def probeDownlink(self):
		return self.c_LastmileProbeConfig.probeDownlink
	@probeDownlink.setter
	def probeDownlink(self, bool probeDownlink):
		self.c_LastmileProbeConfig.probeDownlink=probeDownlink
	@property
	def expectedUplinkBitrate(self):
		return self.c_LastmileProbeConfig.expectedUplinkBitrate
	@expectedUplinkBitrate.setter
	def expectedUplinkBitrate(self, unsigned int expectedUplinkBitrate):
		self.c_LastmileProbeConfig.expectedUplinkBitrate=expectedUplinkBitrate
	@property
	def expectedDownlinkBitrate(self):
		return self.c_LastmileProbeConfig.expectedDownlinkBitrate
	@expectedDownlinkBitrate.setter
	def expectedDownlinkBitrate(self, unsigned int expectedDownlinkBitrate):
		self.c_LastmileProbeConfig.expectedDownlinkBitrate=expectedDownlinkBitrate
	def __cinit__(self):
		self.c_LastmileProbeConfig = new LastmileProbeConfig()
	def destruct(self):
		free(self.c_LastmileProbeConfig)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport AudioVolumeInfo
cdef class pyAudioVolumeInfo:
	cdef AudioVolumeInfo *c_AudioVolumeInfo
	@property
	def uid(self):
		return self.c_AudioVolumeInfo.uid
	@uid.setter
	def uid(self, unsigned int uid):
		self.c_AudioVolumeInfo.uid=uid
	@property
	def volume(self):
		return self.c_AudioVolumeInfo.volume
	@volume.setter
	def volume(self, unsigned int volume):
		self.c_AudioVolumeInfo.volume=volume
	def __cinit__(self):
		self.c_AudioVolumeInfo = new AudioVolumeInfo()
	def destruct(self):
		free(self.c_AudioVolumeInfo)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport RtcStats
cdef class pyRtcStats:
	cdef RtcStats *c_RtcStats
	@property
	def duration(self):
		return self.c_RtcStats.duration
	@duration.setter
	def duration(self, unsigned int duration):
		self.c_RtcStats.duration=duration
	@property
	def txBytes(self):
		return self.c_RtcStats.txBytes
	@txBytes.setter
	def txBytes(self, unsigned int txBytes):
		self.c_RtcStats.txBytes=txBytes
	@property
	def rxBytes(self):
		return self.c_RtcStats.rxBytes
	@rxBytes.setter
	def rxBytes(self, unsigned int rxBytes):
		self.c_RtcStats.rxBytes=rxBytes
	@property
	def txKBitRate(self):
		return self.c_RtcStats.txKBitRate
	@txKBitRate.setter
	def txKBitRate(self, unsigned short txKBitRate):
		self.c_RtcStats.txKBitRate=txKBitRate
	@property
	def rxKBitRate(self):
		return self.c_RtcStats.rxKBitRate
	@rxKBitRate.setter
	def rxKBitRate(self, unsigned short rxKBitRate):
		self.c_RtcStats.rxKBitRate=rxKBitRate
	@property
	def rxAudioKBitRate(self):
		return self.c_RtcStats.rxAudioKBitRate
	@rxAudioKBitRate.setter
	def rxAudioKBitRate(self, unsigned short rxAudioKBitRate):
		self.c_RtcStats.rxAudioKBitRate=rxAudioKBitRate
	@property
	def txAudioKBitRate(self):
		return self.c_RtcStats.txAudioKBitRate
	@txAudioKBitRate.setter
	def txAudioKBitRate(self, unsigned short txAudioKBitRate):
		self.c_RtcStats.txAudioKBitRate=txAudioKBitRate
	@property
	def rxVideoKBitRate(self):
		return self.c_RtcStats.rxVideoKBitRate
	@rxVideoKBitRate.setter
	def rxVideoKBitRate(self, unsigned short rxVideoKBitRate):
		self.c_RtcStats.rxVideoKBitRate=rxVideoKBitRate
	@property
	def txVideoKBitRate(self):
		return self.c_RtcStats.txVideoKBitRate
	@txVideoKBitRate.setter
	def txVideoKBitRate(self, unsigned short txVideoKBitRate):
		self.c_RtcStats.txVideoKBitRate=txVideoKBitRate
	@property
	def lastmileDelay(self):
		return self.c_RtcStats.lastmileDelay
	@lastmileDelay.setter
	def lastmileDelay(self, unsigned short lastmileDelay):
		self.c_RtcStats.lastmileDelay=lastmileDelay
	@property
	def userCount(self):
		return self.c_RtcStats.userCount
	@userCount.setter
	def userCount(self, unsigned int userCount):
		self.c_RtcStats.userCount=userCount
	@property
	def cpuAppUsage(self):
		return self.c_RtcStats.cpuAppUsage
	@cpuAppUsage.setter
	def cpuAppUsage(self, double cpuAppUsage):
		self.c_RtcStats.cpuAppUsage=cpuAppUsage
	@property
	def cpuTotalUsage(self):
		return self.c_RtcStats.cpuTotalUsage
	@cpuTotalUsage.setter
	def cpuTotalUsage(self, double cpuTotalUsage):
		self.c_RtcStats.cpuTotalUsage=cpuTotalUsage
	def __cinit__(self):
		self.c_RtcStats = new RtcStats()
	def destruct(self):
		free(self.c_RtcStats)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_RtcStats = new RtcStats()
class pyQUALITY_ADAPT_INDICATION:
	ADAPT_NONE = 0
	ADAPT_UP_BANDWIDTH = 1
	ADAPT_DOWN_BANDWIDTH = 2
from IAgoraRtcEngine cimport LocalVideoStats
cdef class pyLocalVideoStats:
	cdef LocalVideoStats *c_LocalVideoStats
	@property
	def sentBitrate(self):
		return self.c_LocalVideoStats.sentBitrate
	@sentBitrate.setter
	def sentBitrate(self, int sentBitrate):
		self.c_LocalVideoStats.sentBitrate=sentBitrate
	@property
	def sentFrameRate(self):
		return self.c_LocalVideoStats.sentFrameRate
	@sentFrameRate.setter
	def sentFrameRate(self, int sentFrameRate):
		self.c_LocalVideoStats.sentFrameRate=sentFrameRate
	@property
	def targetBitrate(self):
		return self.c_LocalVideoStats.targetBitrate
	@targetBitrate.setter
	def targetBitrate(self, int targetBitrate):
		self.c_LocalVideoStats.targetBitrate=targetBitrate
	@property
	def targetFrameRate(self):
		return self.c_LocalVideoStats.targetFrameRate
	@targetFrameRate.setter
	def targetFrameRate(self, int targetFrameRate):
		self.c_LocalVideoStats.targetFrameRate=targetFrameRate
	@property
	def qualityAdaptIndication(self):
		return self.c_LocalVideoStats.qualityAdaptIndication
	@qualityAdaptIndication.setter
	def qualityAdaptIndication(self, QUALITY_ADAPT_INDICATION qualityAdaptIndication):
		self.c_LocalVideoStats.qualityAdaptIndication=qualityAdaptIndication
	def __cinit__(self):
		self.c_LocalVideoStats = new LocalVideoStats()
	def destruct(self):
		free(self.c_LocalVideoStats)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport RemoteVideoStats
cdef class pyRemoteVideoStats:
	cdef RemoteVideoStats *c_RemoteVideoStats
	@property
	def uid(self):
		return self.c_RemoteVideoStats.uid
	@uid.setter
	def uid(self, unsigned int uid):
		self.c_RemoteVideoStats.uid=uid
	@property
	def delay(self):
		return self.c_RemoteVideoStats.delay
	@delay.setter
	def delay(self, int delay):
		self.c_RemoteVideoStats.delay=delay
	@property
	def width(self):
		return self.c_RemoteVideoStats.width
	@width.setter
	def width(self, int width):
		self.c_RemoteVideoStats.width=width
	@property
	def height(self):
		return self.c_RemoteVideoStats.height
	@height.setter
	def height(self, int height):
		self.c_RemoteVideoStats.height=height
	@property
	def receivedBitrate(self):
		return self.c_RemoteVideoStats.receivedBitrate
	@receivedBitrate.setter
	def receivedBitrate(self, int receivedBitrate):
		self.c_RemoteVideoStats.receivedBitrate=receivedBitrate
	@property
	def receivedFrameRate(self):
		return self.c_RemoteVideoStats.receivedFrameRate
	@receivedFrameRate.setter
	def receivedFrameRate(self, int receivedFrameRate):
		self.c_RemoteVideoStats.receivedFrameRate=receivedFrameRate
	@property
	def rxStreamType(self):
		return self.c_RemoteVideoStats.rxStreamType
	@rxStreamType.setter
	def rxStreamType(self, REMOTE_VIDEO_STREAM_TYPE rxStreamType):
		self.c_RemoteVideoStats.rxStreamType=rxStreamType
	def __cinit__(self):
		self.c_RemoteVideoStats = new RemoteVideoStats()
	def destruct(self):
		free(self.c_RemoteVideoStats)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport RemoteAudioStats
cdef class pyRemoteAudioStats:
	cdef RemoteAudioStats *c_RemoteAudioStats
	@property
	def uid(self):
		return self.c_RemoteAudioStats.uid
	@uid.setter
	def uid(self, unsigned int uid):
		self.c_RemoteAudioStats.uid=uid
	@property
	def quality(self):
		return self.c_RemoteAudioStats.quality
	@quality.setter
	def quality(self, int quality):
		self.c_RemoteAudioStats.quality=quality
	@property
	def networkTransportDelay(self):
		return self.c_RemoteAudioStats.networkTransportDelay
	@networkTransportDelay.setter
	def networkTransportDelay(self, int networkTransportDelay):
		self.c_RemoteAudioStats.networkTransportDelay=networkTransportDelay
	@property
	def jitterBufferDelay(self):
		return self.c_RemoteAudioStats.jitterBufferDelay
	@jitterBufferDelay.setter
	def jitterBufferDelay(self, int jitterBufferDelay):
		self.c_RemoteAudioStats.jitterBufferDelay=jitterBufferDelay
	@property
	def audioLossRate(self):
		return self.c_RemoteAudioStats.audioLossRate
	@audioLossRate.setter
	def audioLossRate(self, int audioLossRate):
		self.c_RemoteAudioStats.audioLossRate=audioLossRate
	def __cinit__(self):
		self.c_RemoteAudioStats = new RemoteAudioStats()
	def destruct(self):
		free(self.c_RemoteAudioStats)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport VideoCompositingLayout
cdef class pyVideoCompositingLayout:
	cdef VideoCompositingLayout *c_VideoCompositingLayout
	@property
	def canvasWidth(self):
		return self.c_VideoCompositingLayout.canvasWidth
	@canvasWidth.setter
	def canvasWidth(self, int canvasWidth):
		self.c_VideoCompositingLayout.canvasWidth=canvasWidth
	@property
	def canvasHeight(self):
		return self.c_VideoCompositingLayout.canvasHeight
	@canvasHeight.setter
	def canvasHeight(self, int canvasHeight):
		self.c_VideoCompositingLayout.canvasHeight=canvasHeight
	@property
	def backgroundColor(self):
		return cython.operator.dereference(self.c_VideoCompositingLayout.backgroundColor)
	@backgroundColor.setter
	def backgroundColor(self, backgroundColor):
		self.c_VideoCompositingLayout.backgroundColor=backgroundColor
	@property
	def regions(self):
		tmp = pyRegion()
		tmp.c_Region = (self.c_VideoCompositingLayout.regions)
		return tmp
	@regions.setter
	def regions(self,pyRegion regions):
		self.c_VideoCompositingLayout.regions=regions.c_Region
	@property
	def regionCount(self):
		return self.c_VideoCompositingLayout.regionCount
	@regionCount.setter
	def regionCount(self, int regionCount):
		self.c_VideoCompositingLayout.regionCount=regionCount
	@property
	def appData(self):
		return cython.operator.dereference(self.c_VideoCompositingLayout.appData)
	@appData.setter
	def appData(self, appData):
		self.c_VideoCompositingLayout.appData=appData
	@property
	def appDataLength(self):
		return self.c_VideoCompositingLayout.appDataLength
	@appDataLength.setter
	def appDataLength(self, int appDataLength):
		self.c_VideoCompositingLayout.appDataLength=appDataLength
	def __cinit__(self):
		self.c_VideoCompositingLayout = new VideoCompositingLayout()
	def destruct(self):
		free(self.c_VideoCompositingLayout)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_VideoCompositingLayout = new VideoCompositingLayout()
from IAgoraRtcEngine cimport Region
cdef class pyRegion:
	cdef Region *c_Region
	@property
	def uid(self):
		return self.c_Region.uid
	@uid.setter
	def uid(self, unsigned int uid):
		self.c_Region.uid=uid
	@property
	def x(self):
		return self.c_Region.x
	@x.setter
	def x(self, double x):
		self.c_Region.x=x
	@property
	def y(self):
		return self.c_Region.y
	@y.setter
	def y(self, double y):
		self.c_Region.y=y
	@property
	def width(self):
		return self.c_Region.width
	@width.setter
	def width(self, double width):
		self.c_Region.width=width
	@property
	def height(self):
		return self.c_Region.height
	@height.setter
	def height(self, double height):
		self.c_Region.height=height
	@property
	def zOrder(self):
		return self.c_Region.zOrder
	@zOrder.setter
	def zOrder(self, int zOrder):
		self.c_Region.zOrder=zOrder
	@property
	def alpha(self):
		return self.c_Region.alpha
	@alpha.setter
	def alpha(self, double alpha):
		self.c_Region.alpha=alpha
	@property
	def renderMode(self):
		return self.c_Region.renderMode
	@renderMode.setter
	def renderMode(self, RENDER_MODE_TYPE renderMode):
		self.c_Region.renderMode=renderMode
	def construct_1(self):
		self.c_Region = new Region()
from IAgoraRtcEngine cimport VideoDimensions
cdef class pyVideoDimensions:
	cdef VideoDimensions *c_VideoDimensions
	@property
	def width(self):
		return self.c_VideoDimensions.width
	@width.setter
	def width(self, int width):
		self.c_VideoDimensions.width=width
	@property
	def height(self):
		return self.c_VideoDimensions.height
	@height.setter
	def height(self, int height):
		self.c_VideoDimensions.height=height
	def __cinit__(self):
		self.c_VideoDimensions = new VideoDimensions()
	def destruct(self):
		free(self.c_VideoDimensions)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_VideoDimensions = new VideoDimensions()
	def construct_2(self,int x1,int x2):
		self.c_VideoDimensions = new VideoDimensions(x1,x2)
STANDARD_BITRATE = 0
COMPATIBLE_BITRATE = -1
DEFAULT_MIN_BITRATE = -1
from IAgoraRtcEngine cimport VideoEncoderConfiguration
cdef class pyVideoEncoderConfiguration:
	cdef VideoEncoderConfiguration *c_VideoEncoderConfiguration
	@property
	def dimensions(self):
		tmp = pyVideoDimensions()
		tmp.c_VideoDimensions = &self.c_VideoEncoderConfiguration.dimensions
		return tmp
	@dimensions.setter
	def dimensions(self,pyVideoDimensions dimensions):
		self.c_VideoEncoderConfiguration.dimensions=cython.operator.dereference(dimensions.c_VideoDimensions)
	@property
	def frameRate(self):
		return self.c_VideoEncoderConfiguration.frameRate
	@frameRate.setter
	def frameRate(self, FRAME_RATE frameRate):
		self.c_VideoEncoderConfiguration.frameRate=frameRate
	@property
	def minFrameRate(self):
		return self.c_VideoEncoderConfiguration.minFrameRate
	@minFrameRate.setter
	def minFrameRate(self, int minFrameRate):
		self.c_VideoEncoderConfiguration.minFrameRate=minFrameRate
	@property
	def bitrate(self):
		return self.c_VideoEncoderConfiguration.bitrate
	@bitrate.setter
	def bitrate(self, int bitrate):
		self.c_VideoEncoderConfiguration.bitrate=bitrate
	@property
	def minBitrate(self):
		return self.c_VideoEncoderConfiguration.minBitrate
	@minBitrate.setter
	def minBitrate(self, int minBitrate):
		self.c_VideoEncoderConfiguration.minBitrate=minBitrate
	@property
	def orientationMode(self):
		return self.c_VideoEncoderConfiguration.orientationMode
	@orientationMode.setter
	def orientationMode(self, ORIENTATION_MODE orientationMode):
		self.c_VideoEncoderConfiguration.orientationMode=orientationMode
	@property
	def degradationPreference(self):
		return self.c_VideoEncoderConfiguration.degradationPreference
	@degradationPreference.setter
	def degradationPreference(self, DEGRADATION_PREFERENCE degradationPreference):
		self.c_VideoEncoderConfiguration.degradationPreference=degradationPreference
	def __cinit__(self):
		self.c_VideoEncoderConfiguration = new VideoEncoderConfiguration()
	def destruct(self):
		free(self.c_VideoEncoderConfiguration)
	def __dealloc__(self):
		pass
	def construct_1(self,pyVideoDimensions x1,FRAME_RATE x2,int x3,ORIENTATION_MODE x4):
		self.c_VideoEncoderConfiguration = new VideoEncoderConfiguration(cython.operator.dereference(x1.c_VideoDimensions),x2,x3,x4)
	def construct_2(self,int x1,int x2,FRAME_RATE x3,int x4,ORIENTATION_MODE x5):
		self.c_VideoEncoderConfiguration = new VideoEncoderConfiguration(x1,x2,x3,x4,x5)
	def construct_3(self):
		self.c_VideoEncoderConfiguration = new VideoEncoderConfiguration()
from IAgoraRtcEngine cimport TranscodingUser
cdef class pyTranscodingUser:
	cdef TranscodingUser *c_TranscodingUser
	@property
	def uid(self):
		return self.c_TranscodingUser.uid
	@uid.setter
	def uid(self, unsigned int uid):
		self.c_TranscodingUser.uid=uid
	@property
	def x(self):
		return self.c_TranscodingUser.x
	@x.setter
	def x(self, int x):
		self.c_TranscodingUser.x=x
	@property
	def y(self):
		return self.c_TranscodingUser.y
	@y.setter
	def y(self, int y):
		self.c_TranscodingUser.y=y
	@property
	def width(self):
		return self.c_TranscodingUser.width
	@width.setter
	def width(self, int width):
		self.c_TranscodingUser.width=width
	@property
	def height(self):
		return self.c_TranscodingUser.height
	@height.setter
	def height(self, int height):
		self.c_TranscodingUser.height=height
	@property
	def zOrder(self):
		return self.c_TranscodingUser.zOrder
	@zOrder.setter
	def zOrder(self, int zOrder):
		self.c_TranscodingUser.zOrder=zOrder
	@property
	def alpha(self):
		return self.c_TranscodingUser.alpha
	@alpha.setter
	def alpha(self, double alpha):
		self.c_TranscodingUser.alpha=alpha
	@property
	def audioChannel(self):
		return self.c_TranscodingUser.audioChannel
	@audioChannel.setter
	def audioChannel(self, int audioChannel):
		self.c_TranscodingUser.audioChannel=audioChannel
	def __cinit__(self):
		self.c_TranscodingUser = new TranscodingUser()
	def destruct(self):
		free(self.c_TranscodingUser)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_TranscodingUser = new TranscodingUser()
from IAgoraRtcEngine cimport RtcImage
cdef class pyRtcImage:
	cdef RtcImage *c_RtcImage
	@property
	def url(self):
		return cython.operator.dereference(self.c_RtcImage.url)
	@url.setter
	def url(self, url):
		self.c_RtcImage.url=url
	@property
	def x(self):
		return self.c_RtcImage.x
	@x.setter
	def x(self, int x):
		self.c_RtcImage.x=x
	@property
	def y(self):
		return self.c_RtcImage.y
	@y.setter
	def y(self, int y):
		self.c_RtcImage.y=y
	@property
	def width(self):
		return self.c_RtcImage.width
	@width.setter
	def width(self, int width):
		self.c_RtcImage.width=width
	@property
	def height(self):
		return self.c_RtcImage.height
	@height.setter
	def height(self, int height):
		self.c_RtcImage.height=height
	def __cinit__(self):
		self.c_RtcImage = new RtcImage()
	def destruct(self):
		free(self.c_RtcImage)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_RtcImage = new RtcImage()
from IAgoraRtcEngine cimport LiveTranscoding
cdef class pyLiveTranscoding:
	cdef LiveTranscoding *c_LiveTranscoding
	@property
	def width(self):
		return self.c_LiveTranscoding.width
	@width.setter
	def width(self, int width):
		self.c_LiveTranscoding.width=width
	@property
	def height(self):
		return self.c_LiveTranscoding.height
	@height.setter
	def height(self, int height):
		self.c_LiveTranscoding.height=height
	@property
	def videoBitrate(self):
		return self.c_LiveTranscoding.videoBitrate
	@videoBitrate.setter
	def videoBitrate(self, int videoBitrate):
		self.c_LiveTranscoding.videoBitrate=videoBitrate
	@property
	def videoFramerate(self):
		return self.c_LiveTranscoding.videoFramerate
	@videoFramerate.setter
	def videoFramerate(self, int videoFramerate):
		self.c_LiveTranscoding.videoFramerate=videoFramerate
	@property
	def lowLatency(self):
		return self.c_LiveTranscoding.lowLatency
	@lowLatency.setter
	def lowLatency(self, bool lowLatency):
		self.c_LiveTranscoding.lowLatency=lowLatency
	@property
	def videoGop(self):
		return self.c_LiveTranscoding.videoGop
	@videoGop.setter
	def videoGop(self, int videoGop):
		self.c_LiveTranscoding.videoGop=videoGop
	@property
	def videoCodecProfile(self):
		return self.c_LiveTranscoding.videoCodecProfile
	@videoCodecProfile.setter
	def videoCodecProfile(self, VIDEO_CODEC_PROFILE_TYPE videoCodecProfile):
		self.c_LiveTranscoding.videoCodecProfile=videoCodecProfile
	@property
	def backgroundColor(self):
		return self.c_LiveTranscoding.backgroundColor
	@backgroundColor.setter
	def backgroundColor(self, unsigned int backgroundColor):
		self.c_LiveTranscoding.backgroundColor=backgroundColor
	@property
	def userCount(self):
		return self.c_LiveTranscoding.userCount
	@userCount.setter
	def userCount(self, unsigned int userCount):
		self.c_LiveTranscoding.userCount=userCount
	@property
	def transcodingUsers(self):
		tmp = pyTranscodingUser()
		tmp.c_TranscodingUser = (self.c_LiveTranscoding.transcodingUsers)
		return tmp
	@transcodingUsers.setter
	def transcodingUsers(self,pyTranscodingUser transcodingUsers):
		self.c_LiveTranscoding.transcodingUsers=transcodingUsers.c_TranscodingUser
	@property
	def transcodingExtraInfo(self):
		return cython.operator.dereference(self.c_LiveTranscoding.transcodingExtraInfo)
	@transcodingExtraInfo.setter
	def transcodingExtraInfo(self, transcodingExtraInfo):
		self.c_LiveTranscoding.transcodingExtraInfo=transcodingExtraInfo
	@property
	def metadata(self):
		return cython.operator.dereference(self.c_LiveTranscoding.metadata)
	@metadata.setter
	def metadata(self, metadata):
		self.c_LiveTranscoding.metadata=metadata
	@property
	def watermark(self):
		tmp = pyRtcImage()
		tmp.c_RtcImage = (self.c_LiveTranscoding.watermark)
		return tmp
	@watermark.setter
	def watermark(self,pyRtcImage watermark):
		self.c_LiveTranscoding.watermark=watermark.c_RtcImage
	@property
	def backgroundImage(self):
		tmp = pyRtcImage()
		tmp.c_RtcImage = (self.c_LiveTranscoding.backgroundImage)
		return tmp
	@backgroundImage.setter
	def backgroundImage(self,pyRtcImage backgroundImage):
		self.c_LiveTranscoding.backgroundImage=backgroundImage.c_RtcImage
	@property
	def audioSampleRate(self):
		return self.c_LiveTranscoding.audioSampleRate
	@audioSampleRate.setter
	def audioSampleRate(self, AUDIO_SAMPLE_RATE_TYPE audioSampleRate):
		self.c_LiveTranscoding.audioSampleRate=audioSampleRate
	@property
	def audioBitrate(self):
		return self.c_LiveTranscoding.audioBitrate
	@audioBitrate.setter
	def audioBitrate(self, int audioBitrate):
		self.c_LiveTranscoding.audioBitrate=audioBitrate
	@property
	def audioChannels(self):
		return self.c_LiveTranscoding.audioChannels
	@audioChannels.setter
	def audioChannels(self, int audioChannels):
		self.c_LiveTranscoding.audioChannels=audioChannels
	def __cinit__(self):
		self.c_LiveTranscoding = new LiveTranscoding()
	def destruct(self):
		free(self.c_LiveTranscoding)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_LiveTranscoding = new LiveTranscoding()
from IAgoraRtcEngine cimport CameraCapturerConfiguration
cdef class pyCameraCapturerConfiguration:
	cdef CameraCapturerConfiguration *c_CameraCapturerConfiguration
	@property
	def preference(self):
		return self.c_CameraCapturerConfiguration.preference
	@preference.setter
	def preference(self, CAPTURER_OUTPUT_PREFERENCE preference):
		self.c_CameraCapturerConfiguration.preference=preference
	def __cinit__(self):
		self.c_CameraCapturerConfiguration = new CameraCapturerConfiguration()
	def destruct(self):
		free(self.c_CameraCapturerConfiguration)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport InjectStreamConfig
cdef class pyInjectStreamConfig:
	cdef InjectStreamConfig *c_InjectStreamConfig
	@property
	def width(self):
		return self.c_InjectStreamConfig.width
	@width.setter
	def width(self, int width):
		self.c_InjectStreamConfig.width=width
	@property
	def height(self):
		return self.c_InjectStreamConfig.height
	@height.setter
	def height(self, int height):
		self.c_InjectStreamConfig.height=height
	@property
	def videoGop(self):
		return self.c_InjectStreamConfig.videoGop
	@videoGop.setter
	def videoGop(self, int videoGop):
		self.c_InjectStreamConfig.videoGop=videoGop
	@property
	def videoFramerate(self):
		return self.c_InjectStreamConfig.videoFramerate
	@videoFramerate.setter
	def videoFramerate(self, int videoFramerate):
		self.c_InjectStreamConfig.videoFramerate=videoFramerate
	@property
	def videoBitrate(self):
		return self.c_InjectStreamConfig.videoBitrate
	@videoBitrate.setter
	def videoBitrate(self, int videoBitrate):
		self.c_InjectStreamConfig.videoBitrate=videoBitrate
	@property
	def audioSampleRate(self):
		return self.c_InjectStreamConfig.audioSampleRate
	@audioSampleRate.setter
	def audioSampleRate(self, AUDIO_SAMPLE_RATE_TYPE audioSampleRate):
		self.c_InjectStreamConfig.audioSampleRate=audioSampleRate
	@property
	def audioBitrate(self):
		return self.c_InjectStreamConfig.audioBitrate
	@audioBitrate.setter
	def audioBitrate(self, int audioBitrate):
		self.c_InjectStreamConfig.audioBitrate=audioBitrate
	@property
	def audioChannels(self):
		return self.c_InjectStreamConfig.audioChannels
	@audioChannels.setter
	def audioChannels(self, int audioChannels):
		self.c_InjectStreamConfig.audioChannels=audioChannels
	def __cinit__(self):
		self.c_InjectStreamConfig = new InjectStreamConfig()
	def destruct(self):
		free(self.c_InjectStreamConfig)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_InjectStreamConfig = new InjectStreamConfig()
class pyRTMP_STREAM_LIFE_CYCLE_TYPE:
	RTMP_STREAM_LIFE_CYCLE_BIND2CHANNEL = 1
	RTMP_STREAM_LIFE_CYCLE_BIND2OWNER = 2
from IAgoraRtcEngine cimport PublisherConfiguration
cdef class pyPublisherConfiguration:
	cdef PublisherConfiguration *c_PublisherConfiguration
	@property
	def width(self):
		return self.c_PublisherConfiguration.width
	@width.setter
	def width(self, int width):
		self.c_PublisherConfiguration.width=width
	@property
	def height(self):
		return self.c_PublisherConfiguration.height
	@height.setter
	def height(self, int height):
		self.c_PublisherConfiguration.height=height
	@property
	def framerate(self):
		return self.c_PublisherConfiguration.framerate
	@framerate.setter
	def framerate(self, int framerate):
		self.c_PublisherConfiguration.framerate=framerate
	@property
	def bitrate(self):
		return self.c_PublisherConfiguration.bitrate
	@bitrate.setter
	def bitrate(self, int bitrate):
		self.c_PublisherConfiguration.bitrate=bitrate
	@property
	def defaultLayout(self):
		return self.c_PublisherConfiguration.defaultLayout
	@defaultLayout.setter
	def defaultLayout(self, int defaultLayout):
		self.c_PublisherConfiguration.defaultLayout=defaultLayout
	@property
	def lifecycle(self):
		return self.c_PublisherConfiguration.lifecycle
	@lifecycle.setter
	def lifecycle(self, int lifecycle):
		self.c_PublisherConfiguration.lifecycle=lifecycle
	@property
	def owner(self):
		return self.c_PublisherConfiguration.owner
	@owner.setter
	def owner(self, bool owner):
		self.c_PublisherConfiguration.owner=owner
	@property
	def injectStreamWidth(self):
		return self.c_PublisherConfiguration.injectStreamWidth
	@injectStreamWidth.setter
	def injectStreamWidth(self, int injectStreamWidth):
		self.c_PublisherConfiguration.injectStreamWidth=injectStreamWidth
	@property
	def injectStreamHeight(self):
		return self.c_PublisherConfiguration.injectStreamHeight
	@injectStreamHeight.setter
	def injectStreamHeight(self, int injectStreamHeight):
		self.c_PublisherConfiguration.injectStreamHeight=injectStreamHeight
	@property
	def injectStreamUrl(self):
		return cython.operator.dereference(self.c_PublisherConfiguration.injectStreamUrl)
	@injectStreamUrl.setter
	def injectStreamUrl(self, injectStreamUrl):
		self.c_PublisherConfiguration.injectStreamUrl=injectStreamUrl
	@property
	def publishUrl(self):
		return cython.operator.dereference(self.c_PublisherConfiguration.publishUrl)
	@publishUrl.setter
	def publishUrl(self, publishUrl):
		self.c_PublisherConfiguration.publishUrl=publishUrl
	@property
	def rawStreamUrl(self):
		return cython.operator.dereference(self.c_PublisherConfiguration.rawStreamUrl)
	@rawStreamUrl.setter
	def rawStreamUrl(self, rawStreamUrl):
		self.c_PublisherConfiguration.rawStreamUrl=rawStreamUrl
	@property
	def extraInfo(self):
		return cython.operator.dereference(self.c_PublisherConfiguration.extraInfo)
	@extraInfo.setter
	def extraInfo(self, extraInfo):
		self.c_PublisherConfiguration.extraInfo=extraInfo
	def __cinit__(self):
		self.c_PublisherConfiguration = new PublisherConfiguration()
	def destruct(self):
		free(self.c_PublisherConfiguration)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_PublisherConfiguration = new PublisherConfiguration()
class pyVideoContentHint:
	CONTENT_HINT_NONE = 0
	CONTENT_HINT_MOTION = 1
	CONTENT_HINT_DETAILS = 2
from IAgoraRtcEngine cimport Rectangle
cdef class pyRectangle:
	cdef Rectangle *c_Rectangle
	@property
	def x(self):
		return self.c_Rectangle.x
	@x.setter
	def x(self, int x):
		self.c_Rectangle.x=x
	@property
	def y(self):
		return self.c_Rectangle.y
	@y.setter
	def y(self, int y):
		self.c_Rectangle.y=y
	@property
	def width(self):
		return self.c_Rectangle.width
	@width.setter
	def width(self, int width):
		self.c_Rectangle.width=width
	@property
	def height(self):
		return self.c_Rectangle.height
	@height.setter
	def height(self, int height):
		self.c_Rectangle.height=height
	def __cinit__(self):
		self.c_Rectangle = new Rectangle()
	def destruct(self):
		free(self.c_Rectangle)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_Rectangle = new Rectangle()
	def construct_2(self,int x1,int x2,int x3,int x4):
		self.c_Rectangle = new Rectangle(x1,x2,x3,x4)
from IAgoraRtcEngine cimport Rect
cdef class pyRect:
	cdef Rect *c_Rect
	@property
	def top(self):
		return self.c_Rect.top
	@top.setter
	def top(self, int top):
		self.c_Rect.top=top
	@property
	def left(self):
		return self.c_Rect.left
	@left.setter
	def left(self, int left):
		self.c_Rect.left=left
	@property
	def bottom(self):
		return self.c_Rect.bottom
	@bottom.setter
	def bottom(self, int bottom):
		self.c_Rect.bottom=bottom
	@property
	def right(self):
		return self.c_Rect.right
	@right.setter
	def right(self, int right):
		self.c_Rect.right=right
	def __cinit__(self):
		self.c_Rect = new Rect()
	def destruct(self):
		free(self.c_Rect)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_Rect = new Rect()
	def construct_2(self,int x1,int x2,int x3,int x4):
		self.c_Rect = new Rect(x1,x2,x3,x4)
from IAgoraRtcEngine cimport ScreenCaptureParameters
cdef class pyScreenCaptureParameters:
	cdef ScreenCaptureParameters *c_ScreenCaptureParameters
	@property
	def dimensions(self):
		tmp = pyVideoDimensions()
		tmp.c_VideoDimensions = &self.c_ScreenCaptureParameters.dimensions
		return tmp
	@dimensions.setter
	def dimensions(self,pyVideoDimensions dimensions):
		self.c_ScreenCaptureParameters.dimensions=cython.operator.dereference(dimensions.c_VideoDimensions)
	@property
	def frameRate(self):
		return self.c_ScreenCaptureParameters.frameRate
	@frameRate.setter
	def frameRate(self, int frameRate):
		self.c_ScreenCaptureParameters.frameRate=frameRate
	@property
	def bitrate(self):
		return self.c_ScreenCaptureParameters.bitrate
	@bitrate.setter
	def bitrate(self, int bitrate):
		self.c_ScreenCaptureParameters.bitrate=bitrate
	def __cinit__(self):
		self.c_ScreenCaptureParameters = new ScreenCaptureParameters()
	def destruct(self):
		free(self.c_ScreenCaptureParameters)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_ScreenCaptureParameters = new ScreenCaptureParameters()
	def construct_2(self,pyVideoDimensions x1,int x2,int x3):
		self.c_ScreenCaptureParameters = new ScreenCaptureParameters(cython.operator.dereference(x1.c_VideoDimensions),x2,x3)
	def construct_3(self,int x1,int x2,int x3,int x4):
		self.c_ScreenCaptureParameters = new ScreenCaptureParameters(x1,x2,x3,x4)
from IAgoraRtcEngine cimport VideoCanvas
cdef class pyVideoCanvas:
	cdef VideoCanvas *c_VideoCanvas
	@property
	def view(self):
		return voidptr2int(self.c_VideoCanvas.view)
	@view.setter
	def view(self, unsigned long long view):
		self.c_VideoCanvas.view=int2voidptr(view)
	@property
	def renderMode(self):
		return self.c_VideoCanvas.renderMode
	@renderMode.setter
	def renderMode(self, int renderMode):
		self.c_VideoCanvas.renderMode=renderMode
	@property
	def uid(self):
		return self.c_VideoCanvas.uid
	@uid.setter
	def uid(self, unsigned int uid):
		self.c_VideoCanvas.uid=uid
	@property
	def priv(self):
		return voidptr2py(self.c_VideoCanvas.priv)
	@priv.setter
	def priv(self, priv):
		self.c_VideoCanvas.priv=py2voidptr(priv)
	def __cinit__(self):
		self.c_VideoCanvas = new VideoCanvas()
	def destruct(self):
		free(self.c_VideoCanvas)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_VideoCanvas = new VideoCanvas()
	def construct_2(self, unsigned long long x1,int x2,unsigned int x3):
		self.c_VideoCanvas = new VideoCanvas(int2voidptr(x1),x2,x3)
from IAgoraRtcEngine cimport BeautyOptions
cdef class pyBeautyOptions:
	cdef BeautyOptions *c_BeautyOptions
	@property
	def lighteningContrastLevel(self):
		return self.c_BeautyOptions.lighteningContrastLevel
	@lighteningContrastLevel.setter
	def lighteningContrastLevel(self, LIGHTENING_CONTRAST_LEVEL lighteningContrastLevel):
		self.c_BeautyOptions.lighteningContrastLevel=lighteningContrastLevel
	@property
	def lighteningLevel(self):
		return self.c_BeautyOptions.lighteningLevel
	@lighteningLevel.setter
	def lighteningLevel(self, float lighteningLevel):
		self.c_BeautyOptions.lighteningLevel=lighteningLevel
	@property
	def smoothnessLevel(self):
		return self.c_BeautyOptions.smoothnessLevel
	@smoothnessLevel.setter
	def smoothnessLevel(self, float smoothnessLevel):
		self.c_BeautyOptions.smoothnessLevel=smoothnessLevel
	@property
	def rednessLevel(self):
		return self.c_BeautyOptions.rednessLevel
	@rednessLevel.setter
	def rednessLevel(self, float rednessLevel):
		self.c_BeautyOptions.rednessLevel=rednessLevel
	def __cinit__(self):
		self.c_BeautyOptions = new BeautyOptions()
	def destruct(self):
		free(self.c_BeautyOptions)
	def __dealloc__(self):
		pass
	def construct_1(self,LIGHTENING_CONTRAST_LEVEL x1,float x2,float x3,float x4):
		self.c_BeautyOptions = new BeautyOptions(x1,x2,x3,x4)
	def construct_2(self):
		self.c_BeautyOptions = new BeautyOptions()
class pyLIGHTENING_CONTRAST_LEVEL:
	LIGHTENING_CONTRAST_LOW = 0
	LIGHTENING_CONTRAST_NORMAL = 1
	LIGHTENING_CONTRAST_HIGH = 2
from IAgoraRtcEngine cimport IPacketObserver
cdef class pyIPacketObserver:
	cdef IPacketObserver *c_IPacketObserver
	def onSendAudioPacket(self,pyPacket x1):
		return self.c_IPacketObserver.onSendAudioPacket(cython.operator.dereference(x1.c_Packet))
	def onSendVideoPacket(self,pyPacket x1):
		return self.c_IPacketObserver.onSendVideoPacket(cython.operator.dereference(x1.c_Packet))
	def onReceiveAudioPacket(self,pyPacket x1):
		return self.c_IPacketObserver.onReceiveAudioPacket(cython.operator.dereference(x1.c_Packet))
	def onReceiveVideoPacket(self,pyPacket x1):
		return self.c_IPacketObserver.onReceiveVideoPacket(cython.operator.dereference(x1.c_Packet))
from IAgoraRtcEngine cimport Packet
cdef class pyPacket:
	cdef Packet *c_Packet
	@property
	def buffer(self):
		return cython.operator.dereference(self.c_Packet.buffer)
	@buffer.setter
	def buffer(self, buffer):
		self.c_Packet.buffer=buffer
	@property
	def size(self):
		return self.c_Packet.size
	@size.setter
	def size(self, unsigned int size):
		self.c_Packet.size=size
	def __cinit__(self):
		self.c_Packet = new Packet()
	def destruct(self):
		free(self.c_Packet)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport IRtcEngineEventHandler
cdef class pyIRtcEngineEventHandler:
	cdef IRtcEngineEventHandler *c_IRtcEngineEventHandler
	def onWarning(self,int x1,char*x2):
		return self.c_IRtcEngineEventHandler.onWarning(x1,x2)
	def onError(self,int x1,char*x2):
		return self.c_IRtcEngineEventHandler.onError(x1,x2)
	def onJoinChannelSuccess(self,char*x1,unsigned int x2,int x3):
		return self.c_IRtcEngineEventHandler.onJoinChannelSuccess(x1,x2,x3)
	def onRejoinChannelSuccess(self,char*x1,unsigned int x2,int x3):
		return self.c_IRtcEngineEventHandler.onRejoinChannelSuccess(x1,x2,x3)
	def onLeaveChannel(self,pyRtcStats x1):
		return self.c_IRtcEngineEventHandler.onLeaveChannel(cython.operator.dereference(x1.c_RtcStats))
	def onClientRoleChanged(self,CLIENT_ROLE_TYPE x1,CLIENT_ROLE_TYPE x2):
		return self.c_IRtcEngineEventHandler.onClientRoleChanged(x1,x2)
	def onUserJoined(self,unsigned int x1,int x2):
		return self.c_IRtcEngineEventHandler.onUserJoined(x1,x2)
	def onUserOffline(self,unsigned int x1,USER_OFFLINE_REASON_TYPE x2):
		return self.c_IRtcEngineEventHandler.onUserOffline(x1,x2)
	def onLastmileQuality(self,int x1):
		return self.c_IRtcEngineEventHandler.onLastmileQuality(x1)
	def onLastmileProbeResult(self,pyLastmileProbeResult x1):
		return self.c_IRtcEngineEventHandler.onLastmileProbeResult(cython.operator.dereference(x1.c_LastmileProbeResult))
	def onConnectionInterrupted(self):
		return self.c_IRtcEngineEventHandler.onConnectionInterrupted()
	def onConnectionLost(self):
		return self.c_IRtcEngineEventHandler.onConnectionLost()
	def onConnectionBanned(self):
		return self.c_IRtcEngineEventHandler.onConnectionBanned()
	def onApiCallExecuted(self,int x1,char*x2,char*x3):
		return self.c_IRtcEngineEventHandler.onApiCallExecuted(x1,x2,x3)
	def onRequestToken(self):
		return self.c_IRtcEngineEventHandler.onRequestToken()
	def onTokenPrivilegeWillExpire(self,char*x1):
		return self.c_IRtcEngineEventHandler.onTokenPrivilegeWillExpire(x1)
	def onAudioQuality(self,unsigned int x1,int x2,unsigned short x3,unsigned short x4):
		return self.c_IRtcEngineEventHandler.onAudioQuality(x1,x2,x3,x4)
	def onRtcStats(self,pyRtcStats x1):
		return self.c_IRtcEngineEventHandler.onRtcStats(cython.operator.dereference(x1.c_RtcStats))
	def onNetworkQuality(self,unsigned int x1,int x2,int x3):
		return self.c_IRtcEngineEventHandler.onNetworkQuality(x1,x2,x3)
	def onLocalVideoStats(self,pyLocalVideoStats x1):
		return self.c_IRtcEngineEventHandler.onLocalVideoStats(cython.operator.dereference(x1.c_LocalVideoStats))
	def onRemoteVideoStats(self,pyRemoteVideoStats x1):
		return self.c_IRtcEngineEventHandler.onRemoteVideoStats(cython.operator.dereference(x1.c_RemoteVideoStats))
	def onRemoteAudioStats(self,pyRemoteAudioStats x1):
		return self.c_IRtcEngineEventHandler.onRemoteAudioStats(cython.operator.dereference(x1.c_RemoteAudioStats))
	def onAudioVolumeIndication(self,pyAudioVolumeInfo x1,unsigned int x2,int x3):
		return self.c_IRtcEngineEventHandler.onAudioVolumeIndication(x1.c_AudioVolumeInfo,x2,x3)
	def onActiveSpeaker(self,unsigned int x1):
		return self.c_IRtcEngineEventHandler.onActiveSpeaker(x1)
	def onVideoStopped(self):
		return self.c_IRtcEngineEventHandler.onVideoStopped()
	def onFirstLocalVideoFrame(self,int x1,int x2,int x3):
		return self.c_IRtcEngineEventHandler.onFirstLocalVideoFrame(x1,x2,x3)
	def onFirstRemoteVideoDecoded(self,unsigned int x1,int x2,int x3,int x4):
		return self.c_IRtcEngineEventHandler.onFirstRemoteVideoDecoded(x1,x2,x3,x4)
	def onFirstRemoteVideoFrame(self,unsigned int x1,int x2,int x3,int x4):
		return self.c_IRtcEngineEventHandler.onFirstRemoteVideoFrame(x1,x2,x3,x4)
	def onUserMuteAudio(self,unsigned int x1,bool x2):
		return self.c_IRtcEngineEventHandler.onUserMuteAudio(x1,x2)
	def onUserMuteVideo(self,unsigned int x1,bool x2):
		return self.c_IRtcEngineEventHandler.onUserMuteVideo(x1,x2)
	def onUserEnableVideo(self,unsigned int x1,bool x2):
		return self.c_IRtcEngineEventHandler.onUserEnableVideo(x1,x2)
	def onAudioDeviceStateChanged(self,char*x1,int x2,int x3):
		return self.c_IRtcEngineEventHandler.onAudioDeviceStateChanged(x1,x2,x3)
	def onAudioDeviceVolumeChanged(self,MEDIA_DEVICE_TYPE x1,int x2,bool x3):
		return self.c_IRtcEngineEventHandler.onAudioDeviceVolumeChanged(x1,x2,x3)
	def onCameraReady(self):
		return self.c_IRtcEngineEventHandler.onCameraReady()
	def onCameraFocusAreaChanged(self,int x1,int x2,int x3,int x4):
		return self.c_IRtcEngineEventHandler.onCameraFocusAreaChanged(x1,x2,x3,x4)
	def onCameraExposureAreaChanged(self,int x1,int x2,int x3,int x4):
		return self.c_IRtcEngineEventHandler.onCameraExposureAreaChanged(x1,x2,x3,x4)
	def onAudioMixingFinished(self):
		return self.c_IRtcEngineEventHandler.onAudioMixingFinished()
	def onAudioMixingStateChanged(self,AUDIO_MIXING_STATE_TYPE x1,AUDIO_MIXING_ERROR_TYPE x2):
		return self.c_IRtcEngineEventHandler.onAudioMixingStateChanged(x1,x2)
	def onRemoteAudioMixingBegin(self):
		return self.c_IRtcEngineEventHandler.onRemoteAudioMixingBegin()
	def onRemoteAudioMixingEnd(self):
		return self.c_IRtcEngineEventHandler.onRemoteAudioMixingEnd()
	def onAudioEffectFinished(self,int x1):
		return self.c_IRtcEngineEventHandler.onAudioEffectFinished(x1)
	def onVideoDeviceStateChanged(self,char*x1,int x2,int x3):
		return self.c_IRtcEngineEventHandler.onVideoDeviceStateChanged(x1,x2,x3)
	def onVideoSizeChanged(self,unsigned int x1,int x2,int x3,int x4):
		return self.c_IRtcEngineEventHandler.onVideoSizeChanged(x1,x2,x3,x4)
	def onRemoteVideoStateChanged(self,unsigned int x1,REMOTE_VIDEO_STATE x2):
		return self.c_IRtcEngineEventHandler.onRemoteVideoStateChanged(x1,x2)
	def onUserEnableLocalVideo(self,unsigned int x1,bool x2):
		return self.c_IRtcEngineEventHandler.onUserEnableLocalVideo(x1,x2)
	def onStreamMessage(self,unsigned int x1,int x2,char*x3,int x4):
		return self.c_IRtcEngineEventHandler.onStreamMessage(x1,x2,x3,x4)
	def onStreamMessageError(self,unsigned int x1,int x2,int x3,int x4,int x5):
		return self.c_IRtcEngineEventHandler.onStreamMessageError(x1,x2,x3,x4,x5)
	def onMediaEngineLoadSuccess(self):
		return self.c_IRtcEngineEventHandler.onMediaEngineLoadSuccess()
	def onMediaEngineStartCallSuccess(self):
		return self.c_IRtcEngineEventHandler.onMediaEngineStartCallSuccess()
	def onFirstLocalAudioFrame(self,int x1):
		return self.c_IRtcEngineEventHandler.onFirstLocalAudioFrame(x1)
	def onFirstRemoteAudioFrame(self,unsigned int x1,int x2):
		return self.c_IRtcEngineEventHandler.onFirstRemoteAudioFrame(x1,x2)
	def onStreamPublished(self,char*x1,int x2):
		return self.c_IRtcEngineEventHandler.onStreamPublished(x1,x2)
	def onStreamUnpublished(self,char*x1):
		return self.c_IRtcEngineEventHandler.onStreamUnpublished(x1)
	def onTranscodingUpdated(self):
		return self.c_IRtcEngineEventHandler.onTranscodingUpdated()
	def onStreamInjectedStatus(self,char*x1,unsigned int x2,int x3):
		return self.c_IRtcEngineEventHandler.onStreamInjectedStatus(x1,x2,x3)
	def onLocalPublishFallbackToAudioOnly(self,bool x1):
		return self.c_IRtcEngineEventHandler.onLocalPublishFallbackToAudioOnly(x1)
	def onRemoteSubscribeFallbackToAudioOnly(self,unsigned int x1,bool x2):
		return self.c_IRtcEngineEventHandler.onRemoteSubscribeFallbackToAudioOnly(x1,x2)
	def onRemoteAudioTransportStats(self,unsigned int x1,unsigned short x2,unsigned short x3,unsigned short x4):
		return self.c_IRtcEngineEventHandler.onRemoteAudioTransportStats(x1,x2,x3,x4)
	def onRemoteVideoTransportStats(self,unsigned int x1,unsigned short x2,unsigned short x3,unsigned short x4):
		return self.c_IRtcEngineEventHandler.onRemoteVideoTransportStats(x1,x2,x3,x4)
	def onMicrophoneEnabled(self,bool x1):
		return self.c_IRtcEngineEventHandler.onMicrophoneEnabled(x1)
	def onConnectionStateChanged(self,CONNECTION_STATE_TYPE x1,CONNECTION_CHANGED_REASON_TYPE x2):
		return self.c_IRtcEngineEventHandler.onConnectionStateChanged(x1,x2)
	def __cinit__(self):
		self.c_IRtcEngineEventHandler = new IRtcEngineEventHandler()
	def destruct(self):
		free(self.c_IRtcEngineEventHandler)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport IVideoDeviceCollection
cdef class pyIVideoDeviceCollection:
	cdef IVideoDeviceCollection *c_IVideoDeviceCollection
	def getCount(self):
		return self.c_IVideoDeviceCollection.getCount()
	def getDevice(self,int x1,char*x2,char*x3):
		return self.c_IVideoDeviceCollection.getDevice(x1,x2,x3)
	def setDevice(self,char*x1):
		return self.c_IVideoDeviceCollection.setDevice(x1)
	def release(self):
		return self.c_IVideoDeviceCollection.release()
from IAgoraRtcEngine cimport IVideoDeviceManager
cdef class pyIVideoDeviceManager:
	cdef IVideoDeviceManager *c_IVideoDeviceManager
	def enumerateVideoDevices(self):
		tmp = pyIVideoDeviceCollection()
		tmp.c_IVideoDeviceCollection=(self.c_IVideoDeviceManager.enumerateVideoDevices())
		return tmp
	def startDeviceTest(self, x1):
		return self.c_IVideoDeviceManager.startDeviceTest(py2voidptr(x1))
	def stopDeviceTest(self):
		return self.c_IVideoDeviceManager.stopDeviceTest()
	def setDevice(self,char*x1):
		return self.c_IVideoDeviceManager.setDevice(x1)
	def getDevice(self,char*x1):
		return self.c_IVideoDeviceManager.getDevice(x1)
	def release(self):
		return self.c_IVideoDeviceManager.release()
from IAgoraRtcEngine cimport IAudioDeviceCollection
cdef class pyIAudioDeviceCollection:
	cdef IAudioDeviceCollection *c_IAudioDeviceCollection
	def getCount(self):
		return self.c_IAudioDeviceCollection.getCount()
	def getDevice(self,int x1,char*x2,char*x3):
		return self.c_IAudioDeviceCollection.getDevice(x1,x2,x3)
	def setDevice(self,char*x1):
		return self.c_IAudioDeviceCollection.setDevice(x1)
	def setApplicationVolume(self,int x1):
		return self.c_IAudioDeviceCollection.setApplicationVolume(x1)
	def getApplicationVolume(self,int x1):
		return self.c_IAudioDeviceCollection.getApplicationVolume(x1)
	def setApplicationMute(self,bool x1):
		return self.c_IAudioDeviceCollection.setApplicationMute(x1)
	def isApplicationMute(self,bool x1):
		return self.c_IAudioDeviceCollection.isApplicationMute(x1)
	def release(self):
		return self.c_IAudioDeviceCollection.release()
from IAgoraRtcEngine cimport IAudioDeviceManager
cdef class pyIAudioDeviceManager:
	cdef IAudioDeviceManager *c_IAudioDeviceManager
	def enumeratePlaybackDevices(self):
		tmp = pyIAudioDeviceCollection()
		tmp.c_IAudioDeviceCollection=(self.c_IAudioDeviceManager.enumeratePlaybackDevices())
		return tmp
	def enumerateRecordingDevices(self):
		tmp = pyIAudioDeviceCollection()
		tmp.c_IAudioDeviceCollection=(self.c_IAudioDeviceManager.enumerateRecordingDevices())
		return tmp
	def setPlaybackDevice(self,char*x1):
		return self.c_IAudioDeviceManager.setPlaybackDevice(x1)
	def setRecordingDevice(self,char*x1):
		return self.c_IAudioDeviceManager.setRecordingDevice(x1)
	def startPlaybackDeviceTest(self,char*x1):
		return self.c_IAudioDeviceManager.startPlaybackDeviceTest(x1)
	def stopPlaybackDeviceTest(self):
		return self.c_IAudioDeviceManager.stopPlaybackDeviceTest()
	def setPlaybackDeviceVolume(self,int x1):
		return self.c_IAudioDeviceManager.setPlaybackDeviceVolume(x1)
	def getPlaybackDeviceVolume(self,int x1):
		return self.c_IAudioDeviceManager.getPlaybackDeviceVolume(&x1)
	def setRecordingDeviceVolume(self,int x1):
		return self.c_IAudioDeviceManager.setRecordingDeviceVolume(x1)
	def getRecordingDeviceVolume(self,int x1):
		return self.c_IAudioDeviceManager.getRecordingDeviceVolume(&x1)
	def setPlaybackDeviceMute(self,bool x1):
		return self.c_IAudioDeviceManager.setPlaybackDeviceMute(x1)
	def getPlaybackDeviceMute(self,bool x1):
		return self.c_IAudioDeviceManager.getPlaybackDeviceMute(&x1)
	def setRecordingDeviceMute(self,bool x1):
		return self.c_IAudioDeviceManager.setRecordingDeviceMute(x1)
	def getRecordingDeviceMute(self,bool x1):
		return self.c_IAudioDeviceManager.getRecordingDeviceMute(&x1)
	def startRecordingDeviceTest(self,int x1):
		return self.c_IAudioDeviceManager.startRecordingDeviceTest(x1)
	def stopRecordingDeviceTest(self):
		return self.c_IAudioDeviceManager.stopRecordingDeviceTest()
	def getPlaybackDevice(self,char*x1):
		return self.c_IAudioDeviceManager.getPlaybackDevice(x1)
	def getPlaybackDeviceInfo(self,char*x1,char*x2):
		return self.c_IAudioDeviceManager.getPlaybackDeviceInfo(x1,x2)
	def getRecordingDevice(self,char*x1):
		return self.c_IAudioDeviceManager.getRecordingDevice(x1)
	def getRecordingDeviceInfo(self,char*x1,char*x2):
		return self.c_IAudioDeviceManager.getRecordingDeviceInfo(x1,x2)
	def startAudioDeviceLoopbackTest(self,int x1):
		return self.c_IAudioDeviceManager.startAudioDeviceLoopbackTest(x1)
	def stopAudioDeviceLoopbackTest(self):
		return self.c_IAudioDeviceManager.stopAudioDeviceLoopbackTest()
	def release(self):
		return self.c_IAudioDeviceManager.release()
from IAgoraRtcEngine cimport RtcEngineContext
cdef class pyRtcEngineContext:
	cdef RtcEngineContext *c_RtcEngineContext
	@property
	def eventHandler(self):
		tmp = pyEventHandler()
		tmp.c_EventHandler = convertBack(self.c_RtcEngineContext.eventHandler)
		return tmp
	@eventHandler.setter
	def eventHandler(self,pyEventHandler eventHandler):
		self.c_RtcEngineContext.eventHandler=convert(eventHandler.c_EventHandler)
	@property
	def appId(self):
		return cython.operator.dereference(self.c_RtcEngineContext.appId)
	@appId.setter
	def appId(self, appId):
		self.c_RtcEngineContext.appId=appId
	def __cinit__(self):
		self.c_RtcEngineContext = new RtcEngineContext()
	def destruct(self):
		free(self.c_RtcEngineContext)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_RtcEngineContext = new RtcEngineContext()
from IAgoraRtcEngine cimport IRtcEngine
cdef class pyIRtcEngine:
	cdef IRtcEngine *c_IRtcEngine
	def initialize(self,pyRtcEngineContext x1):
		return self.c_IRtcEngine.initialize(cython.operator.dereference(x1.c_RtcEngineContext))
	def release(self,bool x1):
		return self.c_IRtcEngine.release(x1)
	def setChannelProfile(self,CHANNEL_PROFILE_TYPE x1):
		return self.c_IRtcEngine.setChannelProfile(x1)
	def setClientRole(self,CLIENT_ROLE_TYPE x1):
		return self.c_IRtcEngine.setClientRole(x1)
	def joinChannel(self,char*x1,char*x2,char*x3,unsigned int x4):
		return self.c_IRtcEngine.joinChannel(x1,x2,x3,x4)
	def leaveChannel(self):
		return self.c_IRtcEngine.leaveChannel()
	def renewToken(self,char*x1):
		return self.c_IRtcEngine.renewToken(x1)
	def queryInterface(self,INTERFACE_ID_TYPE x1, x2):
		return self.c_IRtcEngine.queryInterface(x1,py2voidptrptr(x2))
	def startEchoTest(self):
		return self.c_IRtcEngine.startEchoTest()
	def startEchoTest(self,int x1):
		return self.c_IRtcEngine.startEchoTest(x1)
	def stopEchoTest(self):
		return self.c_IRtcEngine.stopEchoTest()
	def enableVideo(self):
		return self.c_IRtcEngine.enableVideo()
	def disableVideo(self):
		return self.c_IRtcEngine.disableVideo()
	def setVideoProfile(self,VIDEO_PROFILE_TYPE x1,bool x2):
		return self.c_IRtcEngine.setVideoProfile(x1,x2)
	def setVideoEncoderConfiguration(self,pyVideoEncoderConfiguration x1):
		return self.c_IRtcEngine.setVideoEncoderConfiguration(cython.operator.dereference(x1.c_VideoEncoderConfiguration))
	def setupLocalVideo(self,pyVideoCanvas x1):
		return self.c_IRtcEngine.setupLocalVideo(cython.operator.dereference(x1.c_VideoCanvas))
	def setupRemoteVideo(self,pyVideoCanvas x1):
		return self.c_IRtcEngine.setupRemoteVideo(cython.operator.dereference(x1.c_VideoCanvas))
	def startPreview(self):
		return self.c_IRtcEngine.startPreview()
	def setRemoteUserPriority(self,unsigned int x1,PRIORITY_TYPE x2):
		return self.c_IRtcEngine.setRemoteUserPriority(x1,x2)
	def stopPreview(self):
		return self.c_IRtcEngine.stopPreview()
	def enableAudio(self):
		return self.c_IRtcEngine.enableAudio()
	def enableLocalAudio(self,bool x1):
		return self.c_IRtcEngine.enableLocalAudio(x1)
	def disableAudio(self):
		return self.c_IRtcEngine.disableAudio()
	def setAudioProfile(self,AUDIO_PROFILE_TYPE x1,AUDIO_SCENARIO_TYPE x2):
		return self.c_IRtcEngine.setAudioProfile(x1,x2)
	def startScreenCaptureByDisplayId(self,unsigned int x1,pyRectangle x2,pyScreenCaptureParameters x3):
		return self.c_IRtcEngine.startScreenCaptureByDisplayId(x1,cython.operator.dereference(x2.c_Rectangle),cython.operator.dereference(x3.c_ScreenCaptureParameters))
	def startScreenCaptureByWindowId(self, x1,pyRectangle x2,pyScreenCaptureParameters x3):
		return self.c_IRtcEngine.startScreenCaptureByWindowId(py2voidptr(x1),cython.operator.dereference(x2.c_Rectangle),cython.operator.dereference(x3.c_ScreenCaptureParameters))
	def setScreenCaptureContentHint(self,VideoContentHint x1):
		return self.c_IRtcEngine.setScreenCaptureContentHint(x1)
	def updateScreenCaptureParameters(self,pyScreenCaptureParameters x1):
		return self.c_IRtcEngine.updateScreenCaptureParameters(cython.operator.dereference(x1.c_ScreenCaptureParameters))
	def updateScreenCaptureRegion(self,pyRectangle x1):
		return self.c_IRtcEngine.updateScreenCaptureRegion(cython.operator.dereference(x1.c_Rectangle))
	def stopScreenCapture(self):
		return self.c_IRtcEngine.stopScreenCapture()
	def startScreenCapture(self,unsigned int x1,int x2,pyRect x3,int x4):
		return self.c_IRtcEngine.startScreenCapture(x1,x2,x3.c_Rect,x4)
	def updateScreenCaptureRegion(self,pyRect x1):
		return self.c_IRtcEngine.updateScreenCaptureRegion(x1.c_Rect)
	def getCallId(self,pyAString x1):
		return self.c_IRtcEngine.getCallId(cython.operator.dereference(x1.c_AString))
	def rate(self,char*x1,int x2,char*x3):
		return self.c_IRtcEngine.rate(x1,x2,x3)
	def complain(self,char*x1,char*x2):
		return self.c_IRtcEngine.complain(x1,x2)
	def getVersion(self,int x1):
		return cython.operator.dereference(self.c_IRtcEngine.getVersion(&x1))
	def enableLastmileTest(self):
		return self.c_IRtcEngine.enableLastmileTest()
	def disableLastmileTest(self):
		return self.c_IRtcEngine.disableLastmileTest()
	def startLastmileProbeTest(self,pyLastmileProbeConfig x1):
		return self.c_IRtcEngine.startLastmileProbeTest(cython.operator.dereference(x1.c_LastmileProbeConfig))
	def stopLastmileProbeTest(self):
		return self.c_IRtcEngine.stopLastmileProbeTest()
	def getErrorDescription(self,int x1):
		return cython.operator.dereference(self.c_IRtcEngine.getErrorDescription(x1))
	def setEncryptionSecret(self,char*x1):
		return self.c_IRtcEngine.setEncryptionSecret(x1)
	def setEncryptionMode(self,char*x1):
		return self.c_IRtcEngine.setEncryptionMode(x1)
	def registerPacketObserver(self,pyIPacketObserver x1):
		return self.c_IRtcEngine.registerPacketObserver(x1.c_IPacketObserver)
	def createDataStream(self,int x1,bool x2,bool x3):
		return self.c_IRtcEngine.createDataStream(&x1,x2,x3)
	def sendStreamMessage(self,int x1,char*x2,int x3):
		return self.c_IRtcEngine.sendStreamMessage(x1,x2,x3)
	def addPublishStreamUrl(self,char*x1,bool x2):
		return self.c_IRtcEngine.addPublishStreamUrl(x1,x2)
	def removePublishStreamUrl(self,char*x1):
		return self.c_IRtcEngine.removePublishStreamUrl(x1)
	def setLiveTranscoding(self,pyLiveTranscoding x1):
		return self.c_IRtcEngine.setLiveTranscoding(cython.operator.dereference(x1.c_LiveTranscoding))
	def configPublisher(self,pyPublisherConfiguration x1):
		return self.c_IRtcEngine.configPublisher(cython.operator.dereference(x1.c_PublisherConfiguration))
	def setVideoCompositingLayout(self,pyVideoCompositingLayout x1):
		return self.c_IRtcEngine.setVideoCompositingLayout(cython.operator.dereference(x1.c_VideoCompositingLayout))
	def clearVideoCompositingLayout(self):
		return self.c_IRtcEngine.clearVideoCompositingLayout()
	def addVideoWatermark(self,pyRtcImage x1):
		return self.c_IRtcEngine.addVideoWatermark(cython.operator.dereference(x1.c_RtcImage))
	def clearVideoWatermarks(self):
		return self.c_IRtcEngine.clearVideoWatermarks()
	def setBeautyEffectOptions(self,bool x1,pyBeautyOptions x2):
		return self.c_IRtcEngine.setBeautyEffectOptions(x1,cython.operator.dereference(x2.c_BeautyOptions))
	def addInjectStreamUrl(self,char*x1,pyInjectStreamConfig x2):
		return self.c_IRtcEngine.addInjectStreamUrl(x1,cython.operator.dereference(x2.c_InjectStreamConfig))
	def removeInjectStreamUrl(self,char*x1):
		return self.c_IRtcEngine.removeInjectStreamUrl(x1)
	def registerEventHandler(self,pyEventHandler x1):
		return self.c_IRtcEngine.registerEventHandler(convert(x1.c_EventHandler))
	def unregisterEventHandler(self,pyEventHandler x1):
		return self.c_IRtcEngine.unregisterEventHandler(convert(x1.c_EventHandler))
	def getConnectionState(self):
		return self.c_IRtcEngine.getConnectionState()
from IAgoraRtcEngine cimport IRtcEngineParameter
cdef class pyIRtcEngineParameter:
	cdef IRtcEngineParameter *c_IRtcEngineParameter
	def release(self):
		return self.c_IRtcEngineParameter.release()
	def setBool(self,char*x1,bool x2):
		return self.c_IRtcEngineParameter.setBool(x1,x2)
	def setInt(self,char*x1,int x2):
		return self.c_IRtcEngineParameter.setInt(x1,x2)
	def setUInt(self,char*x1,unsigned int x2):
		return self.c_IRtcEngineParameter.setUInt(x1,x2)
	def setNumber(self,char*x1,double x2):
		return self.c_IRtcEngineParameter.setNumber(x1,x2)
	def setString(self,char*x1,char*x2):
		return self.c_IRtcEngineParameter.setString(x1,x2)
	def setObject(self,char*x1,char*x2):
		return self.c_IRtcEngineParameter.setObject(x1,x2)
	def getBool(self,char*x1,bool x2):
		return self.c_IRtcEngineParameter.getBool(x1,x2)
	def getInt(self,char*x1,int x2):
		return self.c_IRtcEngineParameter.getInt(x1,x2)
	def getUInt(self,char*x1,unsigned int x2):
		return self.c_IRtcEngineParameter.getUInt(x1,x2)
	def getNumber(self,char*x1,double x2):
		return self.c_IRtcEngineParameter.getNumber(x1,x2)
	def getString(self,char*x1,pyAString x2):
		return self.c_IRtcEngineParameter.getString(x1,cython.operator.dereference(x2.c_AString))
	def getObject(self,char*x1,pyAString x2):
		return self.c_IRtcEngineParameter.getObject(x1,cython.operator.dereference(x2.c_AString))
	def getArray(self,char*x1,pyAString x2):
		return self.c_IRtcEngineParameter.getArray(x1,cython.operator.dereference(x2.c_AString))
	def setParameters(self,char*x1):
		return self.c_IRtcEngineParameter.setParameters(x1)
	def setProfile(self,char*x1,bool x2):
		return self.c_IRtcEngineParameter.setProfile(x1,x2)
	def convertPath(self,char*x1,pyAString x2):
		return self.c_IRtcEngineParameter.convertPath(x1,cython.operator.dereference(x2.c_AString))
from IAgoraRtcEngine cimport AAudioDeviceManager
cdef class pyAAudioDeviceManager:
	cdef AAudioDeviceManager *c_AAudioDeviceManager
	def __cinit__(self):
		self.c_AAudioDeviceManager = new AAudioDeviceManager()
	def destruct(self):
		free(self.c_AAudioDeviceManager)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_AAudioDeviceManager = new AAudioDeviceManager()
	def construct_2(self,pyIRtcEngine x1):
		self.c_AAudioDeviceManager = new AAudioDeviceManager(x1.c_IRtcEngine)
from IAgoraRtcEngine cimport AVideoDeviceManager
cdef class pyAVideoDeviceManager:
	cdef AVideoDeviceManager *c_AVideoDeviceManager
	def __cinit__(self):
		self.c_AVideoDeviceManager = new AVideoDeviceManager()
	def destruct(self):
		free(self.c_AVideoDeviceManager)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_AVideoDeviceManager = new AVideoDeviceManager()
	def construct_2(self,pyIRtcEngine x1):
		self.c_AVideoDeviceManager = new AVideoDeviceManager(x1.c_IRtcEngine)
from IAgoraRtcEngine cimport AParameter
cdef class pyAParameter:
	cdef AParameter *c_AParameter
	def __cinit__(self):
		self.c_AParameter = new AParameter()
	def destruct(self):
		free(self.c_AParameter)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_AParameter = new AParameter()
	def construct_2(self,pyIRtcEngine x1):
		self.c_AParameter = new AParameter(cython.operator.dereference(x1.c_IRtcEngine))
	def construct_3(self,pyIRtcEngine x1):
		self.c_AParameter = new AParameter(x1.c_IRtcEngine)
	def construct_4(self,pyIRtcEngineParameter x1):
		self.c_AParameter = new AParameter(x1.c_IRtcEngineParameter)
from IAgoraRtcEngine cimport RtcEngineParameters
cdef class pyRtcEngineParameters:
	cdef RtcEngineParameters *c_RtcEngineParameters
	def enableLocalVideo(self,bool x1):
		return self.c_RtcEngineParameters.enableLocalVideo(x1)
	def muteLocalVideoStream(self,bool x1):
		return self.c_RtcEngineParameters.muteLocalVideoStream(x1)
	def muteAllRemoteVideoStreams(self,bool x1):
		return self.c_RtcEngineParameters.muteAllRemoteVideoStreams(x1)
	def setDefaultMuteAllRemoteVideoStreams(self,bool x1):
		return self.c_RtcEngineParameters.setDefaultMuteAllRemoteVideoStreams(x1)
	def muteRemoteVideoStream(self,unsigned int x1,bool x2):
		return self.c_RtcEngineParameters.muteRemoteVideoStream(x1,x2)
	def setPlaybackDeviceVolume(self,int x1):
		return self.c_RtcEngineParameters.setPlaybackDeviceVolume(x1)
	def startAudioRecording(self,char*x1,AUDIO_RECORDING_QUALITY_TYPE x2):
		return self.c_RtcEngineParameters.startAudioRecording(x1,x2)
	def stopAudioRecording(self):
		return self.c_RtcEngineParameters.stopAudioRecording()
	def startAudioMixing(self,char*x1,bool x2,bool x3,int x4):
		return self.c_RtcEngineParameters.startAudioMixing(x1,x2,x3,x4)
	def stopAudioMixing(self):
		return self.c_RtcEngineParameters.stopAudioMixing()
	def pauseAudioMixing(self):
		return self.c_RtcEngineParameters.pauseAudioMixing()
	def resumeAudioMixing(self):
		return self.c_RtcEngineParameters.resumeAudioMixing()
	def adjustAudioMixingVolume(self,int x1):
		return self.c_RtcEngineParameters.adjustAudioMixingVolume(x1)
	def adjustAudioMixingPlayoutVolume(self,int x1):
		return self.c_RtcEngineParameters.adjustAudioMixingPlayoutVolume(x1)
	def adjustAudioMixingPublishVolume(self,int x1):
		return self.c_RtcEngineParameters.adjustAudioMixingPublishVolume(x1)
	def getAudioMixingDuration(self):
		return self.c_RtcEngineParameters.getAudioMixingDuration()
	def getAudioMixingCurrentPosition(self):
		return self.c_RtcEngineParameters.getAudioMixingCurrentPosition()
	def setAudioMixingPosition(self,int x1):
		return self.c_RtcEngineParameters.setAudioMixingPosition(x1)
	def getEffectsVolume(self):
		return self.c_RtcEngineParameters.getEffectsVolume()
	def setEffectsVolume(self,int x1):
		return self.c_RtcEngineParameters.setEffectsVolume(x1)
	def setVolumeOfEffect(self,int x1,int x2):
		return self.c_RtcEngineParameters.setVolumeOfEffect(x1,x2)
	def playEffect(self,int x1,char*x2,int x3,double x4,double x5,int x6,bool x7):
		return self.c_RtcEngineParameters.playEffect(x1,x2,x3,x4,x5,x6,x7)
	def stopEffect(self,int x1):
		return self.c_RtcEngineParameters.stopEffect(x1)
	def stopAllEffects(self):
		return self.c_RtcEngineParameters.stopAllEffects()
	def preloadEffect(self,int x1,char*x2):
		return self.c_RtcEngineParameters.preloadEffect(x1,x2)
	def unloadEffect(self,int x1):
		return self.c_RtcEngineParameters.unloadEffect(x1)
	def pauseEffect(self,int x1):
		return self.c_RtcEngineParameters.pauseEffect(x1)
	def pauseAllEffects(self):
		return self.c_RtcEngineParameters.pauseAllEffects()
	def resumeEffect(self,int x1):
		return self.c_RtcEngineParameters.resumeEffect(x1)
	def resumeAllEffects(self):
		return self.c_RtcEngineParameters.resumeAllEffects()
	def enableSoundPositionIndication(self,bool x1):
		return self.c_RtcEngineParameters.enableSoundPositionIndication(x1)
	def setRemoteVoicePosition(self,int x1,double x2,double x3):
		return self.c_RtcEngineParameters.setRemoteVoicePosition(x1,x2,x3)
	def setLocalVoicePitch(self,double x1):
		return self.c_RtcEngineParameters.setLocalVoicePitch(x1)
	def setLocalVoiceEqualization(self,AUDIO_EQUALIZATION_BAND_FREQUENCY x1,int x2):
		return self.c_RtcEngineParameters.setLocalVoiceEqualization(x1,x2)
	def setLocalVoiceReverb(self,AUDIO_REVERB_TYPE x1,int x2):
		return self.c_RtcEngineParameters.setLocalVoiceReverb(x1,x2)
	def setLocalVoiceChanger(self,VOICE_CHANGER_PRESET x1):
		return self.c_RtcEngineParameters.setLocalVoiceChanger(x1)
	def setLocalVoiceReverbPreset(self,AUDIO_REVERB_PRESET x1):
		return self.c_RtcEngineParameters.setLocalVoiceReverbPreset(x1)
	def pauseAudio(self):
		return self.c_RtcEngineParameters.pauseAudio()
	def resumeAudio(self):
		return self.c_RtcEngineParameters.resumeAudio()
	def setHighQualityAudioParameters(self,bool x1,bool x2,bool x3):
		return self.c_RtcEngineParameters.setHighQualityAudioParameters(x1,x2,x3)
	def adjustRecordingSignalVolume(self,int x1):
		return self.c_RtcEngineParameters.adjustRecordingSignalVolume(x1)
	def adjustPlaybackSignalVolume(self,int x1):
		return self.c_RtcEngineParameters.adjustPlaybackSignalVolume(x1)
	def enableAudioVolumeIndication(self,int x1,int x2):
		return self.c_RtcEngineParameters.enableAudioVolumeIndication(x1,x2)
	def muteLocalAudioStream(self,bool x1):
		return self.c_RtcEngineParameters.muteLocalAudioStream(x1)
	def muteRemoteAudioStream(self,unsigned int x1,bool x2):
		return self.c_RtcEngineParameters.muteRemoteAudioStream(x1,x2)
	def muteAllRemoteAudioStreams(self,bool x1):
		return self.c_RtcEngineParameters.muteAllRemoteAudioStreams(x1)
	def setDefaultMuteAllRemoteAudioStreams(self,bool x1):
		return self.c_RtcEngineParameters.setDefaultMuteAllRemoteAudioStreams(x1)
	def setExternalAudioSource(self,bool x1,int x2,int x3):
		return self.c_RtcEngineParameters.setExternalAudioSource(x1,x2,x3)
	def setExternalAudioSink(self,bool x1,int x2,int x3):
		return self.c_RtcEngineParameters.setExternalAudioSink(x1,x2,x3)
	def setLogFile(self,char*x1):
		return self.c_RtcEngineParameters.setLogFile(x1)
	def setLogFilter(self,unsigned int x1):
		return self.c_RtcEngineParameters.setLogFilter(x1)
	def setLogFileSize(self,unsigned int x1):
		return self.c_RtcEngineParameters.setLogFileSize(x1)
	def setLocalRenderMode(self,RENDER_MODE_TYPE x1):
		return self.c_RtcEngineParameters.setLocalRenderMode(x1)
	def setRemoteRenderMode(self,unsigned int x1,RENDER_MODE_TYPE x2):
		return self.c_RtcEngineParameters.setRemoteRenderMode(x1,x2)
	def setCameraCapturerConfiguration(self,pyCameraCapturerConfiguration x1):
		return self.c_RtcEngineParameters.setCameraCapturerConfiguration(cython.operator.dereference(x1.c_CameraCapturerConfiguration))
	def enableDualStreamMode(self,bool x1):
		return self.c_RtcEngineParameters.enableDualStreamMode(x1)
	def setRemoteVideoStreamType(self,unsigned int x1,REMOTE_VIDEO_STREAM_TYPE x2):
		return self.c_RtcEngineParameters.setRemoteVideoStreamType(x1,x2)
	def setRemoteDefaultVideoStreamType(self,REMOTE_VIDEO_STREAM_TYPE x1):
		return self.c_RtcEngineParameters.setRemoteDefaultVideoStreamType(x1)
	def setRecordingAudioFrameParameters(self,int x1,int x2,RAW_AUDIO_FRAME_OP_MODE_TYPE x3,int x4):
		return self.c_RtcEngineParameters.setRecordingAudioFrameParameters(x1,x2,x3,x4)
	def setPlaybackAudioFrameParameters(self,int x1,int x2,RAW_AUDIO_FRAME_OP_MODE_TYPE x3,int x4):
		return self.c_RtcEngineParameters.setPlaybackAudioFrameParameters(x1,x2,x3,x4)
	def setMixedAudioFrameParameters(self,int x1,int x2):
		return self.c_RtcEngineParameters.setMixedAudioFrameParameters(x1,x2)
	def enableWebSdkInteroperability(self,bool x1):
		return self.c_RtcEngineParameters.enableWebSdkInteroperability(x1)
	def setVideoQualityParameters(self,bool x1):
		return self.c_RtcEngineParameters.setVideoQualityParameters(x1)
	def setLocalVideoMirrorMode(self,VIDEO_MIRROR_MODE_TYPE x1):
		return self.c_RtcEngineParameters.setLocalVideoMirrorMode(x1)
	def setLocalPublishFallbackOption(self,STREAM_FALLBACK_OPTIONS x1):
		return self.c_RtcEngineParameters.setLocalPublishFallbackOption(x1)
	def setRemoteSubscribeFallbackOption(self,STREAM_FALLBACK_OPTIONS x1):
		return self.c_RtcEngineParameters.setRemoteSubscribeFallbackOption(x1)
	def enableLoopbackRecording(self,bool x1,char*x2):
		return self.c_RtcEngineParameters.enableLoopbackRecording(x1,x2)
	def setInEarMonitoringVolume(self,int x1):
		return self.c_RtcEngineParameters.setInEarMonitoringVolume(x1)
	def __cinit__(self):
		self.c_RtcEngineParameters = new RtcEngineParameters()
	def destruct(self):
		free(self.c_RtcEngineParameters)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_RtcEngineParameters = new RtcEngineParameters()
	def construct_2(self,pyIRtcEngine x1):
		self.c_RtcEngineParameters = new RtcEngineParameters(cython.operator.dereference(x1.c_IRtcEngine))
	def construct_3(self,pyIRtcEngine x1):
		self.c_RtcEngineParameters = new RtcEngineParameters(x1.c_IRtcEngine)
def pycreateAgoraRtcEngine():
	tmp = pyIRtcEngine()
	tmp.c_IRtcEngine = (createAgoraRtcEngine())
	return tmp
from IAgoraRtcEngine cimport EventHandler
cdef class pyEventHandler:
	cdef EventHandler *c_EventHandler
	def onJoinChannelSuccess(self,char*x1,unsigned int x2,int x3):
		return self.c_EventHandler.onJoinChannelSuccess(x1,x2,x3)
	def onRejoinChannelSuccess(self,char*x1,unsigned int x2,int x3):
		return self.c_EventHandler.onRejoinChannelSuccess(x1,x2,x3)
	def onLeaveChannel(self,pyRtcStats x1):
		return self.c_EventHandler.onLeaveChannel(cython.operator.dereference(x1.c_RtcStats))
	def onUserJoined(self,unsigned int x1,int x2):
		return self.c_EventHandler.onUserJoined(x1,x2)
	def onClientRoleChanged(self,CLIENT_ROLE_TYPE x1,CLIENT_ROLE_TYPE x2):
		return self.c_EventHandler.onClientRoleChanged(x1,x2)
	def onUserOffline(self,unsigned int x1,USER_OFFLINE_REASON_TYPE x2):
		return self.c_EventHandler.onUserOffline(x1,x2)
	def onLastmileQuality(self,int x1):
		return self.c_EventHandler.onLastmileQuality(x1)
	def onConnectionInterrupted(self):
		return self.c_EventHandler.onConnectionInterrupted()
	def onConnectionLost(self):
		return self.c_EventHandler.onConnectionLost()
	def onApiCallExecuted(self,int x1,char*x2,char*x3):
		return self.c_EventHandler.onApiCallExecuted(x1,x2,x3)
	def onRequestToken(self):
		return self.c_EventHandler.onRequestToken()
	def onTokenPrivilegeWillExpire(self,char*x1):
		return self.c_EventHandler.onTokenPrivilegeWillExpire(x1)
	def onAudioQuality(self,unsigned int x1,int x2,unsigned short x3,unsigned short x4):
		return self.c_EventHandler.onAudioQuality(x1,x2,x3,x4)
	def onRtcStats(self,pyRtcStats x1):
		return self.c_EventHandler.onRtcStats(cython.operator.dereference(x1.c_RtcStats))
	def onNetworkQuality(self,unsigned int x1,int x2,int x3):
		return self.c_EventHandler.onNetworkQuality(x1,x2,x3)
	def onLocalVideoStats(self,pyLocalVideoStats x1):
		return self.c_EventHandler.onLocalVideoStats(cython.operator.dereference(x1.c_LocalVideoStats))
	def onRemoteVideoStats(self,pyRemoteVideoStats x1):
		return self.c_EventHandler.onRemoteVideoStats(cython.operator.dereference(x1.c_RemoteVideoStats))
	def onRemoteAudioStats(self,pyRemoteAudioStats x1):
		return self.c_EventHandler.onRemoteAudioStats(cython.operator.dereference(x1.c_RemoteAudioStats))
	def onAudioVolumeIndication(self,pyAudioVolumeInfo x1,unsigned int x2,int x3):
		return self.c_EventHandler.onAudioVolumeIndication(x1.c_AudioVolumeInfo,x2,x3)
	def onActiveSpeaker(self,unsigned int x1):
		return self.c_EventHandler.onActiveSpeaker(x1)
	def onVideoStopped(self):
		return self.c_EventHandler.onVideoStopped()
	def onFirstLocalVideoFrame(self,int x1,int x2,int x3):
		return self.c_EventHandler.onFirstLocalVideoFrame(x1,x2,x3)
	def onFirstRemoteVideoDecoded(self,unsigned int x1,int x2,int x3,int x4):
		return self.c_EventHandler.onFirstRemoteVideoDecoded(x1,x2,x3,x4)
	def onFirstRemoteVideoFrame(self,unsigned int x1,int x2,int x3,int x4):
		return self.c_EventHandler.onFirstRemoteVideoFrame(x1,x2,x3,x4)
	def onUserMuteAudio(self,unsigned int x1,bool x2):
		return self.c_EventHandler.onUserMuteAudio(x1,x2)
	def onUserMuteVideo(self,unsigned int x1,bool x2):
		return self.c_EventHandler.onUserMuteVideo(x1,x2)
	def onUserEnableVideo(self,unsigned int x1,bool x2):
		return self.c_EventHandler.onUserEnableVideo(x1,x2)
	def onAudioDeviceStateChanged(self,char*x1,int x2,int x3):
		return self.c_EventHandler.onAudioDeviceStateChanged(x1,x2,x3)
	def onCameraReady(self):
		return self.c_EventHandler.onCameraReady()
	def onVideoDeviceStateChanged(self,char*x1,int x2,int x3):
		return self.c_EventHandler.onVideoDeviceStateChanged(x1,x2,x3)
	def onStreamMessage(self,unsigned int x1,int x2,char*x3,int x4):
		return self.c_EventHandler.onStreamMessage(x1,x2,x3,x4)
	def onConnectionStateChanged(self,CONNECTION_STATE_TYPE x1,CONNECTION_CHANGED_REASON_TYPE x2):
		return self.c_EventHandler.onConnectionStateChanged(x1,x2)
	def onFirstLocalAudioFrame(self,int x1):
		return self.c_EventHandler.onFirstLocalAudioFrame(x1)
	def onMicrophoneEnabled(self,bool x1):
		return self.c_EventHandler.onMicrophoneEnabled(x1)
	def onRemoteVideoStateChanged(self,unsigned int x1,REMOTE_VIDEO_STATE x2):
		return self.c_EventHandler.onRemoteVideoStateChanged(x1,x2)
	def onUserEnableLocalVideo(self,unsigned int x1,bool x2):
		return self.c_EventHandler.onUserEnableLocalVideo(x1,x2)
	def onFirstRemoteAudioFrame(self,unsigned int x1,int x2):
		return self.c_EventHandler.onFirstRemoteAudioFrame(x1,x2)
	def onRemoteAudioTransportStats(self,unsigned int x1,unsigned short x2,unsigned short x3,unsigned short x4):
		return self.c_EventHandler.onRemoteAudioTransportStats(x1,x2,x3,x4)
	def onRemoteVideoTransportStats(self,unsigned int x1,unsigned short x2,unsigned short x3,unsigned short x4):
		return self.c_EventHandler.onRemoteVideoTransportStats(x1,x2,x3,x4)
	def __cinit__(self):
		self.c_EventHandler = new EventHandler()
	def destruct(self):
		free(self.c_EventHandler)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_EventHandler = new EventHandler()
class pyMEDIA_SOURCE_TYPE:
	AUDIO_PLAYOUT_SOURCE = 0
	AUDIO_RECORDING_SOURCE = 1
from IAgoraRtcEngine cimport IAudioFrameObserver
cdef class pyIAudioFrameObserver:
	cdef IAudioFrameObserver *c_IAudioFrameObserver
	def onRecordAudioFrame(self,pyAudioFrame x1):
		return self.c_IAudioFrameObserver.onRecordAudioFrame(cython.operator.dereference(x1.c_AudioFrame))
	def onPlaybackAudioFrame(self,pyAudioFrame x1):
		return self.c_IAudioFrameObserver.onPlaybackAudioFrame(cython.operator.dereference(x1.c_AudioFrame))
	def onMixedAudioFrame(self,pyAudioFrame x1):
		return self.c_IAudioFrameObserver.onMixedAudioFrame(cython.operator.dereference(x1.c_AudioFrame))
	def onPlaybackAudioFrameBeforeMixing(self,unsigned int x1,pyAudioFrame x2):
		return self.c_IAudioFrameObserver.onPlaybackAudioFrameBeforeMixing(x1,cython.operator.dereference(x2.c_AudioFrame))
class pyAUDIO_FRAME_TYPE:
	FRAME_TYPE_PCM16 = 0
from IAgoraRtcEngine cimport AudioFrame
cdef class pyAudioFrame:
	cdef AudioFrame *c_AudioFrame
	@property
	def type(self):
		return self.c_AudioFrame.type
	@type.setter
	def type(self, AUDIO_FRAME_TYPE type):
		self.c_AudioFrame.type=type
	@property
	def samples(self):
		return self.c_AudioFrame.samples
	@samples.setter
	def samples(self, int samples):
		self.c_AudioFrame.samples=samples
	@property
	def bytesPerSample(self):
		return self.c_AudioFrame.bytesPerSample
	@bytesPerSample.setter
	def bytesPerSample(self, int bytesPerSample):
		self.c_AudioFrame.bytesPerSample=bytesPerSample
	@property
	def channels(self):
		return self.c_AudioFrame.channels
	@channels.setter
	def channels(self, int channels):
		self.c_AudioFrame.channels=channels
	@property
	def samplesPerSec(self):
		return self.c_AudioFrame.samplesPerSec
	@samplesPerSec.setter
	def samplesPerSec(self, int samplesPerSec):
		self.c_AudioFrame.samplesPerSec=samplesPerSec
	@property
	def buffer(self):
		return voidptr2py(self.c_AudioFrame.buffer)
	@buffer.setter
	def buffer(self, buffer):
		self.c_AudioFrame.buffer=py2voidptr(buffer)
	@property
	def renderTimeMs(self):
		return self.c_AudioFrame.renderTimeMs
	@renderTimeMs.setter
	def renderTimeMs(self, int renderTimeMs):
		self.c_AudioFrame.renderTimeMs=renderTimeMs
	@property
	def avsync_type(self):
		return self.c_AudioFrame.avsync_type
	@avsync_type.setter
	def avsync_type(self, int avsync_type):
		self.c_AudioFrame.avsync_type=avsync_type
	def __cinit__(self):
		self.c_AudioFrame = new AudioFrame()
	def destruct(self):
		free(self.c_AudioFrame)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport IVideoFrameObserver
cdef class pyIVideoFrameObserver:
	cdef IVideoFrameObserver *c_IVideoFrameObserver
	def onCaptureVideoFrame(self,pyVideoFrame x1):
		return self.c_IVideoFrameObserver.onCaptureVideoFrame(cython.operator.dereference(x1.c_VideoFrame))
	def onRenderVideoFrame(self,unsigned int x1,pyVideoFrame x2):
		return self.c_IVideoFrameObserver.onRenderVideoFrame(x1,cython.operator.dereference(x2.c_VideoFrame))
class pyVIDEO_FRAME_TYPE:
	FRAME_TYPE_YUV420 = 0
from IAgoraRtcEngine cimport VideoFrame
cdef class pyVideoFrame:
	cdef VideoFrame *c_VideoFrame
	@property
	def type(self):
		return self.c_VideoFrame.type
	@type.setter
	def type(self, VIDEO_FRAME_TYPE type):
		self.c_VideoFrame.type=type
	@property
	def width(self):
		return self.c_VideoFrame.width
	@width.setter
	def width(self, int width):
		self.c_VideoFrame.width=width
	@property
	def height(self):
		return self.c_VideoFrame.height
	@height.setter
	def height(self, int height):
		self.c_VideoFrame.height=height
	@property
	def yStride(self):
		return self.c_VideoFrame.yStride
	@yStride.setter
	def yStride(self, int yStride):
		self.c_VideoFrame.yStride=yStride
	@property
	def uStride(self):
		return self.c_VideoFrame.uStride
	@uStride.setter
	def uStride(self, int uStride):
		self.c_VideoFrame.uStride=uStride
	@property
	def vStride(self):
		return self.c_VideoFrame.vStride
	@vStride.setter
	def vStride(self, int vStride):
		self.c_VideoFrame.vStride=vStride
	@property
	def yBuffer(self):
		return voidptr2py(self.c_VideoFrame.yBuffer)
	@yBuffer.setter
	def yBuffer(self, yBuffer):
		self.c_VideoFrame.yBuffer=py2voidptr(yBuffer)
	@property
	def uBuffer(self):
		return voidptr2py(self.c_VideoFrame.uBuffer)
	@uBuffer.setter
	def uBuffer(self, uBuffer):
		self.c_VideoFrame.uBuffer=py2voidptr(uBuffer)
	@property
	def vBuffer(self):
		return voidptr2py(self.c_VideoFrame.vBuffer)
	@vBuffer.setter
	def vBuffer(self, vBuffer):
		self.c_VideoFrame.vBuffer=py2voidptr(vBuffer)
	@property
	def rotation(self):
		return self.c_VideoFrame.rotation
	@rotation.setter
	def rotation(self, int rotation):
		self.c_VideoFrame.rotation=rotation
	@property
	def renderTimeMs(self):
		return self.c_VideoFrame.renderTimeMs
	@renderTimeMs.setter
	def renderTimeMs(self, int renderTimeMs):
		self.c_VideoFrame.renderTimeMs=renderTimeMs
	@property
	def avsync_type(self):
		return self.c_VideoFrame.avsync_type
	@avsync_type.setter
	def avsync_type(self, int avsync_type):
		self.c_VideoFrame.avsync_type=avsync_type
	def __cinit__(self):
		self.c_VideoFrame = new VideoFrame()
	def destruct(self):
		free(self.c_VideoFrame)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport IVideoFrame
cdef class pyIVideoFrame:
	cdef IVideoFrame *c_IVideoFrame
	def release(self):
		return self.c_IVideoFrame.release()
	def buffer(self,PLANE_TYPE x1):
		return cython.operator.dereference(self.c_IVideoFrame.buffer(x1))
	def convertFrame(self,VIDEO_TYPE x1,int x2,unsigned char x3):
		return self.c_IVideoFrame.convertFrame(x1,x2,&x3)
	def allocated_size(self,PLANE_TYPE x1):
		return self.c_IVideoFrame.allocated_size(x1)
	def stride(self,PLANE_TYPE x1):
		return self.c_IVideoFrame.stride(x1)
	def width(self):
		return self.c_IVideoFrame.width()
	def height(self):
		return self.c_IVideoFrame.height()
	def timestamp(self):
		return self.c_IVideoFrame.timestamp()
	def render_time_ms(self):
		return self.c_IVideoFrame.render_time_ms()
	def IsZeroSize(self):
		return self.c_IVideoFrame.IsZeroSize()
class pyPLANE_TYPE:
	Y_PLANE = 0
	U_PLANE = 1
	V_PLANE = 2
	NUM_OF_PLANES = 3
class pyVIDEO_TYPE:
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
from IAgoraRtcEngine cimport IExternalVideoRenderCallback
cdef class pyIExternalVideoRenderCallback:
	cdef IExternalVideoRenderCallback *c_IExternalVideoRenderCallback
	def onViewSizeChanged(self,int x1,int x2):
		return self.c_IExternalVideoRenderCallback.onViewSizeChanged(x1,x2)
	def onViewDestroyed(self):
		return self.c_IExternalVideoRenderCallback.onViewDestroyed()
from IAgoraRtcEngine cimport ExternalVideoRenerContext
cdef class pyExternalVideoRenerContext:
	cdef ExternalVideoRenerContext *c_ExternalVideoRenerContext
	@property
	def renderCallback(self):
		tmp = pyIExternalVideoRenderCallback()
		tmp.c_IExternalVideoRenderCallback = (self.c_ExternalVideoRenerContext.renderCallback)
		return tmp
	@renderCallback.setter
	def renderCallback(self,pyIExternalVideoRenderCallback renderCallback):
		self.c_ExternalVideoRenerContext.renderCallback=renderCallback.c_IExternalVideoRenderCallback
	@property
	def view(self):
		return voidptr2py(self.c_ExternalVideoRenerContext.view)
	@view.setter
	def view(self, view):
		self.c_ExternalVideoRenerContext.view=py2voidptr(view)
	@property
	def renderMode(self):
		return self.c_ExternalVideoRenerContext.renderMode
	@renderMode.setter
	def renderMode(self, int renderMode):
		self.c_ExternalVideoRenerContext.renderMode=renderMode
	@property
	def zOrder(self):
		return self.c_ExternalVideoRenerContext.zOrder
	@zOrder.setter
	def zOrder(self, int zOrder):
		self.c_ExternalVideoRenerContext.zOrder=zOrder
	@property
	def left(self):
		return self.c_ExternalVideoRenerContext.left
	@left.setter
	def left(self, float left):
		self.c_ExternalVideoRenerContext.left=left
	@property
	def top(self):
		return self.c_ExternalVideoRenerContext.top
	@top.setter
	def top(self, float top):
		self.c_ExternalVideoRenerContext.top=top
	@property
	def right(self):
		return self.c_ExternalVideoRenerContext.right
	@right.setter
	def right(self, float right):
		self.c_ExternalVideoRenerContext.right=right
	@property
	def bottom(self):
		return self.c_ExternalVideoRenerContext.bottom
	@bottom.setter
	def bottom(self, float bottom):
		self.c_ExternalVideoRenerContext.bottom=bottom
	def __cinit__(self):
		self.c_ExternalVideoRenerContext = new ExternalVideoRenerContext()
	def destruct(self):
		free(self.c_ExternalVideoRenerContext)
	def __dealloc__(self):
		pass
from IAgoraRtcEngine cimport IExternalVideoRender
cdef class pyIExternalVideoRender:
	cdef IExternalVideoRender *c_IExternalVideoRender
	def release(self):
		return self.c_IExternalVideoRender.release()
	def initialize(self):
		return self.c_IExternalVideoRender.initialize()
	def deliverFrame(self,pyIVideoFrame x1,int x2,bool x3):
		return self.c_IExternalVideoRender.deliverFrame(cython.operator.dereference(x1.c_IVideoFrame),x2,x3)
from IAgoraRtcEngine cimport IExternalVideoRenderFactory
cdef class pyIExternalVideoRenderFactory:
	cdef IExternalVideoRenderFactory *c_IExternalVideoRenderFactory
	def createRenderInstance(self,pyExternalVideoRenerContext x1):
		tmp = pyIExternalVideoRender()
		tmp.c_IExternalVideoRender=(self.c_IExternalVideoRenderFactory.createRenderInstance(cython.operator.dereference(x1.c_ExternalVideoRenerContext)))
		return tmp
from IAgoraRtcEngine cimport ExternalVideoFrame
cdef class pyExternalVideoFrame:
	cdef ExternalVideoFrame *c_ExternalVideoFrame
	@property
	def type(self):
		return self.c_ExternalVideoFrame.type
	@type.setter
	def type(self, VIDEO_BUFFER_TYPE type):
		self.c_ExternalVideoFrame.type=type
	@property
	def format(self):
		return self.c_ExternalVideoFrame.format
	@format.setter
	def format(self, VIDEO_PIXEL_FORMAT format):
		self.c_ExternalVideoFrame.format=format
	@property
	def buffer(self):
		return voidptr2py(self.c_ExternalVideoFrame.buffer)
	@buffer.setter
	def buffer(self, buffer):
		self.c_ExternalVideoFrame.buffer=py2voidptr(buffer)
	@property
	def stride(self):
		return self.c_ExternalVideoFrame.stride
	@stride.setter
	def stride(self, int stride):
		self.c_ExternalVideoFrame.stride=stride
	@property
	def height(self):
		return self.c_ExternalVideoFrame.height
	@height.setter
	def height(self, int height):
		self.c_ExternalVideoFrame.height=height
	@property
	def cropLeft(self):
		return self.c_ExternalVideoFrame.cropLeft
	@cropLeft.setter
	def cropLeft(self, int cropLeft):
		self.c_ExternalVideoFrame.cropLeft=cropLeft
	@property
	def cropTop(self):
		return self.c_ExternalVideoFrame.cropTop
	@cropTop.setter
	def cropTop(self, int cropTop):
		self.c_ExternalVideoFrame.cropTop=cropTop
	@property
	def cropRight(self):
		return self.c_ExternalVideoFrame.cropRight
	@cropRight.setter
	def cropRight(self, int cropRight):
		self.c_ExternalVideoFrame.cropRight=cropRight
	@property
	def cropBottom(self):
		return self.c_ExternalVideoFrame.cropBottom
	@cropBottom.setter
	def cropBottom(self, int cropBottom):
		self.c_ExternalVideoFrame.cropBottom=cropBottom
	@property
	def rotation(self):
		return self.c_ExternalVideoFrame.rotation
	@rotation.setter
	def rotation(self, int rotation):
		self.c_ExternalVideoFrame.rotation=rotation
	@property
	def timestamp(self):
		return self.c_ExternalVideoFrame.timestamp
	@timestamp.setter
	def timestamp(self, long long timestamp):
		self.c_ExternalVideoFrame.timestamp=timestamp
	def __cinit__(self):
		self.c_ExternalVideoFrame = new ExternalVideoFrame()
	def destruct(self):
		free(self.c_ExternalVideoFrame)
	def __dealloc__(self):
		pass
class pyVIDEO_BUFFER_TYPE:
	VIDEO_BUFFER_RAW_DATA = 1
class pyVIDEO_PIXEL_FORMAT:
	VIDEO_PIXEL_UNKNOWN = 0
	VIDEO_PIXEL_I420 = 1
	VIDEO_PIXEL_BGRA = 2
	VIDEO_PIXEL_NV12 = 8
from IAgoraRtcEngine cimport IMediaEngine
cdef class pyIMediaEngine:
	cdef IMediaEngine *c_IMediaEngine
	def release(self):
		return self.c_IMediaEngine.release()
	def registerAudioFrameObserver(self,pyIAudioFrameObserver x1):
		return self.c_IMediaEngine.registerAudioFrameObserver(x1.c_IAudioFrameObserver)
	def registerVideoFrameObserver(self,pyVideoFrameObserver x1):
		return self.c_IMediaEngine.registerVideoFrameObserver(convert2(x1.c_VideoFrameObserver))
	def registerVideoRenderFactory(self,pyIExternalVideoRenderFactory x1):
		return self.c_IMediaEngine.registerVideoRenderFactory(x1.c_IExternalVideoRenderFactory)
	def pushAudioFrame(self,MEDIA_SOURCE_TYPE x1,pyAudioFrame x2,bool x3):
		return self.c_IMediaEngine.pushAudioFrame(x1,x2.c_AudioFrame,x3)
	def pushAudioFrame(self,pyAudioFrame x1):
		return self.c_IMediaEngine.pushAudioFrame(x1.c_AudioFrame)
	def pullAudioFrame(self,pyAudioFrame x1):
		return self.c_IMediaEngine.pullAudioFrame(x1.c_AudioFrame)
	def setExternalVideoSource(self,bool x1,bool x2):
		return self.c_IMediaEngine.setExternalVideoSource(x1,x2)
	def pushVideoFrame(self,pyExternalVideoFrame x1):
		return self.c_IMediaEngine.pushVideoFrame(x1.c_ExternalVideoFrame)
from IAgoraRtcEngine cimport VideoFrameObserver
cdef class pyVideoFrameObserver:
	cdef VideoFrameObserver *c_VideoFrameObserver
	def onCaptureVideoFrame(self,pyVideoFrame x1):
		return self.c_VideoFrameObserver.onCaptureVideoFrame(cython.operator.dereference(x1.c_VideoFrame))
	def onRenderVideoFrame(self,unsigned int x1,pyVideoFrame x2):
		return self.c_VideoFrameObserver.onRenderVideoFrame(x1,cython.operator.dereference(x2.c_VideoFrame))
	def __cinit__(self):
		self.c_VideoFrameObserver = new VideoFrameObserver()
	def destruct(self):
		free(self.c_VideoFrameObserver)
	def __dealloc__(self):
		pass
	def construct_1(self):
		self.c_VideoFrameObserver = new VideoFrameObserver()

def pyGetMediaEngine(pyIRtcEngine e):
	tmp = pyIMediaEngine()
	tmp.c_IMediaEngine = getMediaEngine(e.c_IRtcEngine)
	return tmp