Module.onRuntimeInitialized = () => { start(); }

var canvas = document.getElementById('game-canvas');

/* ******************** assets ******************** */

var cursor = new Image();
cursor.src = "assets/img/cursor.png";

var cell_blue = new Image();
cell_blue.src = "assets/img/cell/blue.png";
var cell_imm_blue = new Image();
cell_imm_blue.src = "assets/img/cell/imm_blue.png";
var cell_red = new Image();
cell_red.src = "assets/img/cell/red.png";
var cell_imm_red = new Image();
cell_imm_red.src = "assets/img/cell/imm_red.png";
var cell_empty = new Image();
cell_empty.src = "assets/img/cell/empty.png";
var cell_hover = new Image();
cell_hover.src = "assets/img/cell/hover.png";
var cell_error = new Image();
cell_error.src = "assets/img/cell/error.png";


var rajdhani = new FontFace('Rajdhani', 'url(assets/fonts/Rajdhani-SemiBold.ttf)');
rajdhani.load().then(function (loaded_face) {
    document.fonts.add(loaded_face);
});

/* ******************** variables ******************** */

var EMPTY = 0;
var BLUE = 1;
var RED = 2;
var IMM_BLUE = 3;
var IMM_RED = 4;

var CURSOR_X = -100;
var CURSOR_Y = -100;

var CANVA_X = canvas.offsetLeft;
var CANVA_Y = canvas.offsetTop;
var CANVA_W = canvas.width;
var CANVA_H = canvas.height;

var CTX = canvas.getContext('2d');

var GAME = null;
var ROWS = 0;
var COLS = 0;

/* ******************** register events ******************** */

window.addEventListener('load', windowLoad);              // window load
canvas.addEventListener('click', canvasLeftClick);        // left click event
canvas.addEventListener('contextmenu', canvasRightClick); // right click event
canvas.addEventListener('mousemove', canvasMouseMove);    // mouse move event
canvas.addEventListener('windowresize', windowLoad);      // window resize event
canvas.addEventListener('zoom', windowLoad);              // zoom event (ctrl + scroll)

/* ******************** event callback ******************** */

function canvasLeftClick(event) {
    event.preventDefault();
    CURSOR_X = event.offsetX - 8;
    CURSOR_Y = event.offsetY - 8;
    process();
    play_move(3);   // EMPTY -> BLUE -> RED
    printGame();
}

function canvasRightClick(event) {
    event.preventDefault();
    CURSOR_X = event.offsetX - 8;
    CURSOR_Y = event.offsetY - 8;
    process();
    play_move(4);   // EMPTY -> RED -> BLUE
    printGame();
}

function canvasMouseMove(event) {
    event.preventDefault();
    CURSOR_X = event.offsetX - 8;
    CURSOR_Y = event.offsetY - 8;
    process();
    hover();
    printGame();
}

function windowLoad() {
    process();
    printGame();
}

/* ******************** PROCESS ******************** */

function process() {
    // Canva Update
    CTX = canvas.getContext('2d');
    CANVA_X = canvas.offsetLeft;
    CANVA_Y = canvas.offsetTop;
    canvas.width = (800 * 100 / 1920) * (window.innerWidth) / 100;
    // canvas.height = (800 * 100 / 1080) * (window.innerHeight) / 100;
    canvas.height = canvas.width;
    CANVA_W = canvas.width;
    CANVA_H = canvas.height;

    CTX.clearRect(0, 0, CANVA_W, CANVA_H);

    // Game Update
    ROWS = Module._nb_rows(GAME);
    COLS = Module._nb_cols(GAME);
}

function printGame() {
    var cell_width = CANVA_W / COLS;
    var cell_height = CANVA_H / ROWS;

    for (var row = 0; row < ROWS; row++) {
        for (var col = 0; col < COLS; col++) {
            var square = Module._get_square(GAME, row, col);
            var error = Module._has_error(GAME, row, col);
            if (square == EMPTY)
                CTX.drawImage(cell_empty, col * cell_width, row * cell_height, cell_width, cell_height);
            else if (square == BLUE)
                CTX.drawImage(cell_blue, col * cell_width, row * cell_height, cell_width, cell_height);
            else if (square == RED)
                CTX.drawImage(cell_red, col * cell_width, row * cell_height, cell_width, cell_height);
            else if (square == IMM_BLUE)
                CTX.drawImage(cell_imm_blue, col * cell_width, row * cell_height, cell_width, cell_height);
            else if (square == IMM_RED)
                CTX.drawImage(cell_imm_red, col * cell_width, row * cell_height, cell_width, cell_height);

            if (error && (square == BLUE || square == RED))
                CTX.drawImage(cell_error, col * cell_width, row * cell_height, cell_width, cell_height);
        }
    }

    CTX.drawImage(cursor, CURSOR_X, CURSOR_Y, 50, 50);

    // put this text in <div> element with ID 'result'
    var elm = document.getElementById('result');
}

function play_move(mode) {
    var col = Math.floor(CURSOR_X * COLS / CANVA_W);
    var row = Math.floor(CURSOR_Y * ROWS / CANVA_H);

    var square = Module._get_square(GAME, row, col);
    if (mode == 3) {
        square++;
        if (square > RED)
            square = EMPTY;
    } else if (mode == 4) {
        square--;
        if (square < EMPTY)
            square = RED;
    } else {
        square = mode;
    }

    if (!Module._is_immutable(GAME, row, col))
        Module._play_move(GAME, row, col, square);
}

function hover() {
    var col = Math.floor(CURSOR_X * COLS / CANVA_W);
    var row = Math.floor(CURSOR_Y * ROWS / CANVA_H);

    CTX.drawImage(cell_hover, col * CANVA_W / COLS, row * CANVA_H / ROWS, CANVA_W / COLS, CANVA_H / ROWS);
}

/* ******************** Button Functions ******************** */

function restart() { process(); Module._restart(GAME); printGame(); }
function undo() { process(); Module._undo(GAME); printGame(); }
function redo() { process(); Module._redo(GAME); printGame(); }
function solve() { process(); Module._solve(GAME); printGame(); }
function blue() { process(); play_move(BLUE); printGame(); }
function red() { process(); play_move(RED); printGame(); }
function empty() { process(); play_move(EMPTY); printGame(); }

/* ******************** start ******************** */

function start() {
    console.log("call start routine");
    GAME = Module._new_default();
}

