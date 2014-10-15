##オブジェクト指向練習問題

###問題1

下記のコードを抽象クラスを使用して修正してください。

``` php
  1 <?PHP
  2
  3 class MusicPlayer
  4 {
  5     private $title;
  6     public function __construct($title) { $this->title = $title; }
  7     public function load()  { printf("load music [%s]\n", $this->title); }
  8     public function play()  { printf("play music [%s]\n", $this->title); }
  9     public function pause() { printf("pause playing\n"); }
 10     public function stop()  { printf("stop it\n"); }
 11 }
 12
 13 class VideoPlayer
 14 {
 15     private $title;
 16     public function __construct($title) { $this->title = $title; }
 17     public function load()  { printf("load video [%s]\n", $this->title); }
 18     public function play()  { printf("play video [%s]\n", $this->title); }
 19     public function pause() { printf("pause playing\n"); }
 20     public function stop()  { printf("stop it\n"); }
 21 }
 22
 23
 24 $musicPlayer = new MusicPlayer('Music Title');
 25 $musicPlayer->load();
 26 $musicPlayer->play();
 27
 28 $videoPlayer = new VideoPlayer('Video Title');
 29 $videoPlayer->load();
 30 $videoPlayer->play();
 31
```

###問題2

下記のコードを Template Method または Storategy パターンを使用して修正してください。

また、 Template Method および Storategy パターンを使用することのメリットを挙げなさい。

※処理Aおよび処理Bのパターンは増える可能性あり<br />
※処理Cが追加される可能性あり

``` php
  1 <?PHP
  2
  3 const PROC_A_TYPE_1 = 11;
  4 const PROC_A_TYPE_2 = 12;
  5 const PROC_B_TYPE_1 = 21;
  6 const PROC_B_TYPE_2 = 22;
  7
  8 class Sample
  9 {
 10     private $procAType;
 11     private $procBType;
 12
 13     public function __construct($procAType, $procBType)
 14     {
 15         $this->procAType = $procAType;
 16         $this->procBType = $procBType;
 17     }
 18
 19     public function doSomething()
 20     {
 21         $this->procA(); // 処理A
 22         $this->procB(); // 処理B
 23     }
 24
 25     private function procA()
 26     {
 27         if (PROC_A_TYPE_1 == $this->procAType) {
 28             printf("proc A type 1\n");
 29         }
 30         elseif (PROC_A_TYPE_2 == $this->procAType) {
 31             printf("proc A type 2\n");
 32         }
 33     }
 34
 35     private function procB()
 36     {
 37         if (PROC_B_TYPE_1 == $this->procBType) {
 38             printf("proc B type 1\n");
 39         }
 40         elseif (PROC_B_TYPE_2 == $this->procBType) {
 41             printf("proc B type 2\n");
 42         }
 43     }
 44 }
 45
 46
 47 $sample = new Sample(PROC_A_TYPE_1, PROC_B_TYPE_1);
 48 $sample->doSomething();
 49
```
