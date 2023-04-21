//
// Created by umsys on 2023/04/18.
//

#include <jni.h>
#include <dlfcn.h>

// サードパーティ製共有ライブラリの関数のプロトタイプを定義
typedef const char *(*voicevox_get_version_t)(void);

extern "C"
JNIEXPORT jstring JNICALL
Java_voicevox_native_1libJNI_voicevox_1get_1version(JNIEnv *env, jobject obj) {
    void *handle = dlopen("libvoicevox_core.so", RTLD_LAZY);
    if (!handle) {
        // ライブラリのロードに失敗した場合のエラーハンドリング
        return env->NewStringUTF("Failed to load library");
    }

    // サードパーティ製共有ライブラリの関数のシンボルを取得
    voicevox_get_version_t voicevox_get_version = (voicevox_get_version_t) dlsym(handle,
                                                                                 "voicevox_get_version");

    if (!voicevox_get_version) {
        dlclose(handle);
        return env->NewStringUTF("Failed to load symbol");
    }

    // 関数ポインタを経由してサードパーティ製共有ライブラリの関数を呼ぶ
    const char *result = voicevox_get_version();

    jstring jresult = env->NewStringUTF(result);

    dlclose(handle);

    return jresult;
}

