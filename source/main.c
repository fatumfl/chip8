#include <stdio.h>
#include <assert.h>
#include <stdint.h>

typedef struct {
    uint8_t memory[4096];
    uint8_t V[16];          // Регистры общего назначения
    uint16_t I;             // Индексный регистр
    uint16_t pc;            // Счетчик команд
    uint16_t stack[16];     // Стек
    uint8_t sp;             // Указатель стека
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint8_t display[64 * 32]; // Состояние пикселей (0 или 1)
    uint8_t keypad[16];       // Состояние клавиш
} Chip8;


// Функция инициализации, которую должен написать студент
void chip8_init(Chip8 *chip8) {
    // Обнуление всех полей структуры
    for (int i = 0; i < 4096; i++) chip8->memory[i] = 0;
    for (int i = 0; i < 16; i++) chip8->V[i] = 0;
    for (int i = 0; i < 16; i++) chip8->stack[i] = 0;
    for (int i = 0; i < 64 * 32; i++) chip8->display[i] = 0;
    for (int i = 0; i < 16; i++) chip8->keypad[i] = 0;

    chip8->I = 0;
    chip8->sp = 0;
    chip8->delay_timer = 0;
    chip8->sound_timer = 0;

    // Начальный адрес для программ CHIP-8
    chip8->pc = 0x200; 

    // Здесь также обычно загружается шрифт в память (0x50 - 0x9F)
}

int main() {
    Chip8 myChip8;

    printf("Running Step 1 Test: Initialization...\n");

    chip8_init(&myChip8);

    // Проверка 1: Счетчик команд (PC)
    if (myChip8.pc == 0x200) {
        printf("[OK] PC initialized to 0x200\n");
    } else {
        printf("[FAIL] PC is %04X, expected 0x200\n", myChip8.pc);
    }

    // Проверка 2: Указатель стека
    assert(myChip8.sp == 0);
    printf("[OK] Stack pointer (SP) is 0\n");

    // Проверка 3: Память (простая выборка)
    assert(myChip8.memory[0x200] == 0);
    printf("[OK] Memory is cleared\n");

    printf("\nTest passed successfully!\n");

    return 0;
}
