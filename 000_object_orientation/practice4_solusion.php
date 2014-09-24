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

}

$singleton = Singleton::getInstance();
$singleton->doSomething();

