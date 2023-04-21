# tryVoiceVox
voicevox_coreをAndroidネイティブで動かしたいリポジトリ

# 準備
- voicevox_coreのAndroid向けライブラリを[公式](https://github.com/VOICEVOX/voicevox_core/releases)からダウンロードし、`　app/src/main/jniLibs/arm64-v8a/`に配置してください。

- 実行するエミュレータ、もしくは実機のABIがarm64-v8aであることを確認してください。（それ以外のビルドは現在配布されていないので、動作しないと思います。）

# 進捗
とりあえずvoicevox_coreからバージョンを取得して画面に表示するところまで実装しました。
ゆくゆくはラッパーにする予定ですが、C++はほとんど書いたことがないので、完成の目処は立っていません。。。m(_ _)m
