<?PHP

interface ProcAInterface
{
    public function procA();
}

interface ProcBInterface
{
    public function procB();
}

class ProcAType1 implements ProcAInterface
{
    public function procA() { printf("proc A type 1\n"); }
}

class ProcAType2 implements ProcAInterface
{
    public function procA() { printf("proc A type 2\n"); }
}

class ProcBType1 implements ProcBInterface
{
    public function procB() { printf("proc B type 1\n"); }
}

class ProcBType2 implements ProcBInterface
{
    public function procB() { printf("proc B type 2\n"); }
}


class Sample
{
    private $procA;
    private $procB;

    public function __construct(ProcAInterface $procA, ProcBInterface $procB)
    {
        $this->procA = $procA;
        $this->procB = $procB;
    }

    public function doSomething()
    {
        $this->procA->procA(); // 処理A
        $this->procB->procB(); // 処理B
    }
}


$sample = new Sample(new ProcAType1(), new ProcBType2());
$sample->doSomething();

