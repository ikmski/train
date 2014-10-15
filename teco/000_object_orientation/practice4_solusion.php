<?PHP

class Singleton
{
    private static $instance = NULL;

    public function getInstance()
    {
        if (!self::$instance) {
            self::$instance = new self;
        }
        return self::$instance;
    }

    public function doSomething()
    {
        printf("Do Something\n");
    }

    private function __construct() {}
    private function __clone() {}

}

$singleton1 = Singleton::getInstance();
$singleton1->doSomething();

$singleton2 = Singleton::getInstance();

var_dump($singleton1 === $singleton2);

//$singleton3 = new Singleton();

$singleton4 = clone $singleton1;

