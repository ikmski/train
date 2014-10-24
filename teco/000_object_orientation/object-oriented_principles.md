# オブジェクト指向の原則

## 単一責任の原則: SRP
```
クラスを変更する理由は1つ以上存在してはならない。
```
### 例）モデム
モデムを普通にモデリングすると以下のようになる。

![SRP_1](https://cacoo.com/diagrams/rHEF8wOhKYu959Go-1BECF.png)

ここで、「変更」の観点から見る。
もし、アプリケーションで「接続の管理」と「データ通信」が別々に変更されうる場合、モデムクラスは2つの役割を持つことになり、SRPに違反している。
その場合、モデムクラスは以下のように分けるべきである。

![SRP_2](https://cacoo.com/diagrams/rHEF8wOhKYu959Go-5770D.png)

ただし、アプリケーションの仕様上、これらが常に同時に変更される場合は、これらを分離する必要はない。
そうしてしまうと逆に、設計が**不必要に複雑**になってしまう。



## オープン・クローズドの原則: OCP
```
ソフトウェアの構成要素は拡張に対して開いて（オープン）いて、修正に対して閉じて（クローズ）いなければならない。
```

* 拡張に対してオープンとは？
    モジュールの振る舞いを拡張出来る。

* 修正に対してクローズドとは？
    モジュールを拡張しても、そのモジュールのソースコードやバイナリコードは影響をうけない。

この原則はオブジェクト指向の核心である。
この原則に従うことで、オブジェクト指向の最大の利益（柔軟性、再利用性、保守性）を享受できる。
しかし、オブジェクト指向のプログラミング言語を使用すれば自動的にOCPに準拠できるわけではない。
「抽象」という概念を適用することでOCPに準じた設計をすることが出来る。
ただし、あらゆる部分で抽象をむやみに使えば良いというわけでもない。
むしろ、もっとも頻繁に変更される部分に的を絞って抽象を適用するように努めるべきである。

### 例）クライアントとサーバ

以下の設計例はOCPに従わない。

![OCP_1](https://cacoo.com/diagrams/rHEF8wOhKYu959Go-56976.png)

クライアントクラスとサーバクラスの両方が具体的に実装されており、クライアントクラスがサーバクラスを利用している。
クライアントオブジェクトが別のサーバオブジェクトを利用することになれば、クライアントクラスを変更しなければならない。

OCPに準拠するために、以下のように設計する。

![OCP_2](https://cacoo.com/diagrams/rHEF8wOhKYu959Go-FCBD7.png)

この設計では、クライアントインターフェースは抽象クラスであり、抽象メンバ関数を幾つか持っている。
クライアントインターフェースの実装は、派生クラスにまかせている。
したがって、サーバの振る舞いを拡張、変更したければ、クライアントインターフェースの派生クラスを新たに作成し、そのクラスで、拡張や修正に対応した実装をすればよい。

## リスコフの置換原則: LSP

```
派生型はその基本型と置換可能でなければならない。
```

クラスを使用する側からいうと、基本型を引数にとる関数に、どのような派生型のインスタンスを渡されても、気にすることなく使えないといけない。
実装側からいうと、派生クラスがその基本クラスで使用されるところにおいても、正常に動作することを保証しなければならない。

### LSPに違反している例

**簡単な例**

```cpp
struct Point {double x,y;};
struct Shape {
  enum ShapeType {square, circle} itsType;
  Shape(ShapeType t) : itsType(t) {}
};

struct Circle : public Shape
{
  Circle() : Shape(circle) {};
  void Draw() const;
  Point itsCenter;
  double itsRadius;
};

struct Square : public Shape
{
  Square() : Shape(square) {};
  void Draw() const;
  Point itsTopLeft;
  double itsSide;
};

void DrawShape(const Shape& s)
{
  if (s.itsType == Shape::square)
    static_cast<const Square&>(s).Draw();
  else if (s.itsType == Shape::circle)
    static_cast<const Circle&>(s).Draw();
}
```

DrowShape関数は明らかにOCPに違反している。DrowShape関数は、Shapeクラスのあらゆる派生型を知っていなければならない。
新たにShapeクラスの派生型が作成されるたびにDrowShape関数を変更しなければならなくなる。

**派生クラスにおいて退化している機能**

基本クラスで実装されている機能を派生クラスでオーバーライドして、何もなくしてしまう。
このことをクライアントは知らない。

```cpp
public class Base
{
  public void f() {/* 何かのコード */}
}
public class Derived extends Base
{
  public void f() {}
}
```

**派生クラスから例外を投げる**

基本クラスで投げない例外を派生クラスでのメソッドに追加している。
クライアントの期待しない例外が発生してしまう。

### 契約による設計

* **メソッドの事前条件と事後条件を取り決めておく**

    事前条件：メソッドを実行する前に成立していなければならない条件

    事後条件：メソッドが終了したときに成立していなければならない条件

* **派生クラスでオーバーライドした場合**

    事前条件：オリジナルと等しいか、弱い条件で置き換える

    事後条件：オリジナルと等しいか、強い条件で置き換える

## 依存関係逆転の原則: DIP

```
a. 上位のモジュールは下位のモジュールに依存してはならない。どちらのモジュールも「抽象」に依存すべきである。
b. 「抽象」は実装の詳細に依存してはならない。実装の詳細が「抽象」に依存すべきである。
```

従来の手続き型では、ソフトウェアの方針を決める部分が実装の詳細に依存してしまうような構造になりやすい。
方針と実装の詳細を両者とも「抽象」に依存させることで、依存関係を逆転できる。

### 良くない階層化モデルの例

![DIP_1](https://cacoo.com/diagrams/rHEF8wOhKYu959Go-BD970.png)

上位レイヤが下位レイヤを利用する構造になっている。
この例では、上位のPolicyレイヤが下位の全てのレイヤにおける変更の影響を受けてしまう。

### より適切な階層化モデルの例

![DIP_2](https://cacoo.com/diagrams/rHEF8wOhKYu959Go-D8D14.png)

上位レベルの各レイヤは、抽象インターフェースを宣言し、そのインターフェースを通して必要なサービスを受ける。
下位の各レイヤは、これらの抽象インターフェースを実装する。
こうすることで、上位レイヤが下位レイヤに依存することがなくなっている。
逆にサービスを受けるために上位のレイヤが宣言したインターフェースに依存しているのは下位レイヤとなる。

## インターフェース分離の原則: ISP

```
クライアントに、クライアントが利用しないメソッドへの依存を強制してはならない。
```

一般にクライアントは複数のインターフェースを利用するが、その全てが互いに強い関連性を持っているわけではない。
全てのインターフェースを1つのクラスに押し込めてしまうのではなく、関連性を持ったインターフェースはグループ化し、抽象基本クラスとして分けて利用すべきである。

### 例）セキュリティドア

以下のような抽象クラスがある。

```cpp
class Door
{
  public:
    virtual void Lock()   = 0;
    virtual void Unlock() = 0;
    virtual bool IsDoorOpen() = 0;
};
```

このインターフェースを実装したクラスのひとつとして、TimedDoorがあるとする。
TimedDoorは長時間ドアが開いていると警報が鳴るドアでる。
この機能を実現するために、TimedDoorはTimerオブジェクトと通信する。

```cpp
class Timer
{
  public:
    void Register(int timeout, TimerClient* client);
};

class TimerClient
{
  public:
    virtual void TimeOut() = 0;
};
```

タイムアウトを通知してほしい場合、オブジェクトはTimerのRegisterメソッドをコールし、TimerClientを登録する。
タイムアウトした場合、TimeｒClientのTimeOutメソッドがコールバックされる。

TimerClientクラスがTimedDoorクラスにタイムアウトを通知するにはどうすればよいかを考える。

**問題のある設計**

![ISP_1](https://cacoo.com/diagrams/rHEF8wOhKYu959Go-6FC17.png)

この方法では、DoorクラスがTimerClientに依存してしまっている。
Timerを必要としないDoorの派生クラスでは、TimeOutメソッドを使わない（退化させる）ことになり、LSPに違反する。
また、Doorの派生クラスでは、たとえTimerを使わなくてもTimerClientの定義を必ずインポートしなければならず、「不必要な複雑さ」や「不必要な繰り返し」を持つことになる。

**多重継承を使ってインターフェースを分離する方法**

多重継承が許可されている言語においては、多重継承を使ってこの問題を解決できる。

![ISP_2](https://cacoo.com/diagrams/rHEF8wOhKYu959Go-EF783.png)

```cpp
class TimedDoor : public Door, public TimerClient
{
  public:
    virtual void TimeOut(int timeOutId);
};
```

このようにすることで、どちらのクライアントもTimedDoorを利用できるし、TimedDoorに依存しない。
