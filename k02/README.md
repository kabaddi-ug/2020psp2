# 課題 2 レポート

bb35319026 瀧井祐自

## 課題

住んでる A 県で生まれた（ジモティー）20 代の男性の平均と分散が<img src="/k02/tex/d68ce6ca3a5bc0d4119b243192bca39a.svg?invert_in_darkmode&sanitize=true" align=middle width=79.97342429999998pt height=21.18721440000001pt/>,<img src="/k02/tex/597caa4b0247df1b37ce91294b1113a2.svg?invert_in_darkmode&sanitize=true" align=middle width=77.79492434999999pt height=27.89048460000002pt/>と公式発表された．また，隣の B 県生まれの男性は，平均と分散が<img src="/k02/tex/84c6fc6280b3b0404c5624c15c7ba8d1.svg?invert_in_darkmode&sanitize=true" align=middle width=80.58012929999998pt height=21.18721440000001pt/>,<img src="/k02/tex/effffe1010d8efef5aafbd109a8ea79c.svg?invert_in_darkmode&sanitize=true" align=middle width=70.18242824999999pt height=27.89048460000002pt/>と公式発表されている．このとき，手元の標本の尤もらしさ（尤度）を A 県生まれと B 県生まれについて求めよ．実際にはもちろん A 県・B 県以外の県で生まれる人もいるし，標本の全員が同じ県生まれということはないので，この結果の大小からは何も言えない．

まず`double p_stdnorm(double y)`を，平均 0，分散 1 の正規分布（標準正規分布;<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>）における値<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>の出現確率を出力する関数を作成せよ．
良く知られているように，平均 0，分散 1 の正規分布に従う値<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>の出現確率は，

<p align="center"><img src="/k02/tex/dcba64f2c044edfdbde5ea3b05906df0.svg?invert_in_darkmode&sanitize=true" align=middle width=122.21369985pt height=37.0017615pt/></p>
である．これを関数化したものが`p_stdnorm`である．

平均<img src="/k02/tex/07617f9d8fe48b4a7b3f523d6730eef0.svg?invert_in_darkmode&sanitize=true" align=middle width=9.90492359999999pt height=14.15524440000002pt/>，分散<img src="/k02/tex/e6718aa5499c31af3ff15c3c594a7854.svg?invert_in_darkmode&sanitize=true" align=middle width=16.535428799999988pt height=26.76175259999998pt/>の正規分布（<img src="/k02/tex/ab37c7ccf43057fff834fa1367d3156f.svg?invert_in_darkmode&sanitize=true" align=middle width=62.35355114999998pt height=26.76175259999998pt/>）の確率密度曲線は標準正規分布<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>の確率密度曲線と相似である．相似において，<img src="/k02/tex/f706189f7c542a8078a8b5dc271260ce.svg?invert_in_darkmode&sanitize=true" align=middle width=51.52970459999999pt height=24.65753399999998pt/>における<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>が，<img src="/k02/tex/ab37c7ccf43057fff834fa1367d3156f.svg?invert_in_darkmode&sanitize=true" align=middle width=62.35355114999998pt height=26.76175259999998pt/>における<img src="/k02/tex/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=14.15524440000002pt/>に対応しているとすると，<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>は<img src="/k02/tex/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=14.15524440000002pt/>を使って，<img src="/k02/tex/68d6425cfaadabd14aeda684e28f4aa7.svg?invert_in_darkmode&sanitize=true" align=middle width=71.93053724999999pt height=41.4194451pt/>と書ける．この操作を<img src="/k02/tex/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode&sanitize=true" align=middle width=9.39498779999999pt height=14.15524440000002pt/>の「標準化」という．つまり，どんな正規分布上の変数も<img src="/k02/tex/deceeaf6940a8c7a5a02373728002b0f.svg?invert_in_darkmode&sanitize=true" align=middle width=8.649225749999989pt height=14.15524440000002pt/>を求めるとそれは標準正規分布に従う．

尤度とは，標本<img src="/k02/tex/a3dedd496824b6f33a456be5f9917136.svg?invert_in_darkmode&sanitize=true" align=middle width=59.728227899999986pt height=14.15524440000002pt/>と仮定分布<img src="/k02/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>の類似度をあらわす．仮定分布のもとで標本中のデータのそれぞれが同時に出現する同時確率である．尤度<img src="/k02/tex/ddcb483302ed36a59286424aa5e0be17.svg?invert_in_darkmode&sanitize=true" align=middle width=11.18724254999999pt height=22.465723500000017pt/>は

<p align="center"><img src="/k02/tex/b0546b665f9803a72be90a9a55348d3d.svg?invert_in_darkmode&sanitize=true" align=middle width=382.1801676pt height=47.806078649999996pt/></p>

と計算できる．<img src="/k02/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>は仮定した確率密度関数で，<img src="/k02/tex/27e556cf3caa0673ac49a8f0de3c73ca.svg?invert_in_darkmode&sanitize=true" align=middle width=8.17352744999999pt height=22.831056599999986pt/>はその母数．<img src="/k02/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>が正規分布なら，<img src="/k02/tex/27e556cf3caa0673ac49a8f0de3c73ca.svg?invert_in_darkmode&sanitize=true" align=middle width=8.17352744999999pt height=22.831056599999986pt/>は，平均<img src="/k02/tex/07617f9d8fe48b4a7b3f523d6730eef0.svg?invert_in_darkmode&sanitize=true" align=middle width=9.90492359999999pt height=14.15524440000002pt/>と分散<img src="/k02/tex/e6718aa5499c31af3ff15c3c594a7854.svg?invert_in_darkmode&sanitize=true" align=middle width=16.535428799999988pt height=26.76175259999998pt/>である．

## ソースコードの説明

l6 標準正規分布関数のプロトタイプ宣言
l10 各 double 変数の設置
l28~30 A 県の標準化を行い、正規分布の式を求め、尤度を出す
l32~34 B 県の標準化を行い、正規分布の式を求め、尤度を出す
l49 A 県の尤度を出力
l50 B 県の尤度を出力
l57~60 標準正規分布関数を返す

## 入出力結果

```
Likelihood for A：0.000006
Likelihood for B：0.000002
```

## 修正履歴

[comment #20200430]

- 入出力を Readme.md にコピペしてください．
- A 県の尤度と B 県の尤度の大小比較からは，どんなことが言えますか．
- 尤度が最も高くなるような平均値と分散は何だと思いますか？それは，課題 1 で推定した母集団平均と母集団分散になっているはずです．逆に言うと，尤度が最大となるような意味で「最良」な推定値なのです．母集団分散が不偏分散の計算で求められる理由がこれです．確かめてみると面白いかも．

[comment #20200507]

- OK です．課題 2 完了．
- A 県の尤度と B 県の尤度の大小比較からは，どんなことが言えますか．．．．の答えは，「標本は B 県出身というより 3 倍(=0.000006/0.000002)A 県出身っぽい．」です．
  - 県の平均・分散が分かっていない状況では，どちらっぽいか判断つかない（50:50）でしょうが，平均と分散がわかると，それが（0.000006 : 0.000002 = 3 : 1）だと改善するのです．
- 最後のコメントについては，少し私が間違っていました．尤度が最高となるのは，不偏分散ではなく標本分散みたいです．
