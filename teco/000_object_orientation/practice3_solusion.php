<?PHP

interface Shape
{
    public function draw();
}

class Square implements Shape
{
    public function draw() { printf("Draw Square\n"); }
}

class Circle implements Shape
{
    public function draw() { printf("Draw Circle\n"); }
}

interface ShapeFactory
{
    public function make($shapeName);
}

class ShapeFactoryImplementation implements ShapeFactory
{
    public function make($shapeName)
    {
        $instance = NULL;
        switch ($shapeName) {
            case 'Square':
                $instance = new Square();
                break;
            case 'Circle':
                $instance = new Circle();
                break;
        }

        return $instance;
    }
}

$factory = new ShapeFactoryImplementation();
$shape = $factory->make('Circle');
$shape->draw();

