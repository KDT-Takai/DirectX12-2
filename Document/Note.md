TODOリスト
- [ ] README.mdの作成
- [ ] 363pの続き


今後したいこと
AppクラスのWindowの機能とDirectXの機能を分ける


デバッグブレークするためのメソッド
_CtrSetBreakAlloc(148); // 148は、何回目にメモリを確保したときにブレークするかを指定
メモリリークが発生している場合、原因特定に使用できる

システム値セマンティックの詳細
https://learn.microsoft.com/ja-jp/windows/win32/direct3dhlsl/dx-graphics-hlsl-semantics?redirectedfrom=MSDN

クラス構成
window
device
rendering
log

#define NOMINMAXで消せる

#ifdef PCH_H
#define PCH_H

#ifdef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN