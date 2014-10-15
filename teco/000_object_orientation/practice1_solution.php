<?PHP

class Point
{
    public $x;
    public $y;
}


abstract class Shape
{
    abstract public function draw();
}

class Circle extends Shape
{
    private $center;
    private $radius;

    public function __construct()
    {
        $radius = new Point();
    }

    public function draw()
    {
        printf("円を描きます\n");
    }
}

class Square extends Shape
{
    private $side;
    private $topleft;

    public function __construct()
    {
        $topleft = new Point();
    }

    public function draw()
    {
        printf("正方形を描きます\n");
    }
}

class Triangle extends Shape
{
    private $side;
    private $vertex;

    public function __construct()
    {
        $vertex = new Point();
    }

    public function draw()
    {
        printf("正三角形を描きます\n");
    }
}


class DrawingTool
{
    public function drawAllShapes(array $shapes)
    {
        foreach ($shapes as $shape) {
            $shape->draw();
        }
    }
}


$shapes = array();
$shapes []= new Circle();
$shapes []= new Square();
$shapes []= new Triangle();

$tool = new DrawingTool();
$tool->drawAllShapes($shapes);

