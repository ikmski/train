<?PHP

const PROC_A_TYPE_1 = 11;
const PROC_A_TYPE_2 = 12;
const PROC_B_TYPE_1 = 21;
const PROC_B_TYPE_2 = 22;

class Sample
{
    private $procAType;
    private $procBType;

    public function __construct($procAType, $procBType)
    {
        $this->procAType = $procAType;
        $this->procBType = $procBType;
    }

    public function doSomething()
    {
        $this->procA(); // 処理A
        $this->procB(); // 処理B
    }

    private function procA()
    {
        if (PROC_A_TYPE_1 == $this->procAType) {
            printf("proc A type 1\n");
        }
        elseif (PROC_A_TYPE_2 == $this->procAType) {
            printf("proc A type 2\n");
        }
    }

    private function procB()
    {
        if (PROC_B_TYPE_1 == $this->procBType) {
            printf("proc B type 1\n");
        }
        elseif (PROC_B_TYPE_2 == $this->procBType) {
            printf("proc B type 2\n");
        }
    }
}


$sample = new Sample(PROC_A_TYPE_1, PROC_B_TYPE_1);
$sample->doSomething();

