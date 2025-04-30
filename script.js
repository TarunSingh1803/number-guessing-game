const blocks = {
    A: [[8, 9, 10, 11], [15, 14, 13, 12], [24, 25, 26, 27], [28, 29, 30, 31]],
    B: [[16, 27, 31, 20], [17, 21, 26, 30], [18, 22, 29, 25], [19, 28, 24, 23]],
    C: [[1, 3, 5, 7], [9, 11, 13, 15], [17, 19, 21, 23], [31, 29, 27, 25]],
    D: [[2, 3, 6, 7], [10, 11, 14, 15], [30, 31, 27, 26], [18, 19, 22, 23]],
    E: [[4, 5, 6, 7], [12, 20, 28, 31], [29, 13, 21, 15], [22, 23, 14, 30]]
};

let currentBlockIndex = 0;
let sum = 0;
const blockOrder = ['A', 'B', 'C', 'D', 'E'];

document.getElementById('start-btn').addEventListener('click', startGame);
document.getElementById('yes-btn').addEventListener('click', () => handleAnswer(true));
document.getElementById('no-btn').addEventListener('click', () => handleAnswer(false));
document.getElementById('play-again').addEventListener('click', resetGame);

function startGame() {
    document.getElementById('game-instructions').style.display = 'none';
    document.getElementById('game-area').style.display = 'block';
    document.getElementById('result').style.display = 'none';
    displayBlock(blockOrder[currentBlockIndex]);
}

function displayBlock(blockLetter) {
    document.getElementById('current-block').textContent = blockLetter;
    const grid = document.getElementById('number-grid');
    grid.innerHTML = '';
    
    blocks[blockLetter].forEach(row => {
        row.forEach(number => {
            const cell = document.createElement('div');
            cell.className = 'number-cell';
            cell.textContent = number;
            grid.appendChild(cell);
        });
    });
}

function handleAnswer(isYes) {
    if (isYes) {
        sum += blocks[blockOrder[currentBlockIndex]][0][0];
    }
    
    currentBlockIndex++;
    
    if (currentBlockIndex < blockOrder.length) {
        displayBlock(blockOrder[currentBlockIndex]);
    } else {
        showResult();
    }
}

function showResult() {
    document.getElementById('game-area').style.display = 'none';
    document.getElementById('result').style.display = 'block';
    document.getElementById('guessed-number').textContent = sum;
}

function resetGame() {
    currentBlockIndex = 0;
    sum = 0;
    document.getElementById('game-instructions').style.display = 'block';
    document.getElementById('game-area').style.display = 'none';
    document.getElementById('result').style.display = 'none';
}
