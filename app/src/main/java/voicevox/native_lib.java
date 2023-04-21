package voicevox;

public class native_lib {
    public static String voicevox_get_version() {
        return native_libJNI.voicevox_get_version();
    }
}
