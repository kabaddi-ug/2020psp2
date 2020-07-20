# 課題4 レポート

bb35319026 瀧井祐自

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
l6~11 構造体の宣言
l15~18 各種変数と構造体の使用宣言
l20~22 ファイルを入力できるようにする
l24~27 heights.csvのファイルを入力さしてfnameに格納
l29  fnameで指定した先頭アドレスをfpに代入
l30~32 fpがNULLの場合、プログラム終了
l34 heights.csvの一行目を開く
l35~42 ファイルから身長と性別を読み取り、構造体にそれぞれ値を入れていく
l44~47 ファイルの終わりを示す
l49~72 l24からl47と同じ流れをIDS.csvで行う。ただしIDのファイルは一行目を読むことはしない。
l75 IDを入力
l76~81 入力したIDが構造体にあるか探し、見つけたらループを抜け出す。
l83~93 IDの値を出力し、性別を判別し出力、最後に身長の値を出力。
l94~96 構造体と一致する値がなければNo dataを出力





## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

input the filename of sample height:../sample/heights.csv
the filename of sample : ../sample/heights.csv
input the filename of sample ID:../sample/IDs.csv
the filename of sample: ../sample/IDs.csv
Which ID's data do you want?
45313125
ID : 45313125
gender : Female
height : 152.4



input the filename of sample height:../sample/heights.csv
the filename of sample : ../sample/heights.csv
input the filename of sample ID:../sample/IDs.csv
the filename of sample: ../sample/IDs.csv
Which ID's data do you want?
45313124
No data






## 修正履歴
[comment0708宮下]

修正点はありません。お疲れさまでした！

[comment #20200720 sonoda]
- 課題4の完了を確認しました（薗田）
