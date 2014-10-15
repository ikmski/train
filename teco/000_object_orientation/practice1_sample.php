<?PHP

const SHAPE_ID_CIRCLE   = 1;
const SHAPE_ID_SQUARE   = 2;
const SHAPE_ID_TRIANGLE = 3;


function drawCircle()
{
    printf("円を描きます\n");
}

function drawSquare()
{
    printf("正方形を描きます\n");
}

function drawTriangle()
{
    printf("正三角形を描きます\n");
}


function drawAllShapes(array $shapes)
{
    foreach ($shapes as $shape)
    {
        if (SHAPE_ID_CIRCLE == $shape)
        {
            drawCircle();
        }
        elseif (SHAPE_ID_SQUARE == $shape)
        {
            drawSquare();
        }
        elseif (SHAPE_ID_TRIANGLE == $shape)
        {
            drawTriangle();
        }
    }
}


$shapes = array();
$shapes []= SHAPE_ID_CIRCLE;
$shapes []= SHAPE_ID_SQUARE;
$shapes []= SHAPE_ID_TRIANGLE;

drawAllShapes($shapes);

