<?PHP

class MusicPlayer
{
    private $title;
    public function __construct($title) { $this->title = $title; }
    public function load()  { printf("load music [%s]\n", $this->title); }
    public function play()  { printf("play music [%s]\n", $this->title); }
    public function pause() { printf("pause playing\n"); }
    public function stop()  { printf("stop it\n"); }
}

class VideoPlayer
{
    private $title;
    public function __construct($title) { $this->title = $title; }
    public function load()  { printf("load video [%s]\n", $this->title); }
    public function play()  { printf("play video [%s]\n", $this->title); }
    public function pause() { printf("pause playing\n"); }
    public function stop()  { printf("stop it\n"); }
}


$musicPlayer = new MusicPlayer('Music Title');
$musicPlayer->load();
$musicPlayer->play();

$videoPlayer = new VideoPlayer('Video Title');
$videoPlayer->load();
$videoPlayer->play();


