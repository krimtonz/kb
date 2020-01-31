.section  .text, "ax", @progbits
.set      nomips16
.set      nomicromips
.set      noat
.global   osInvalICache
.ent      osInvalICache
.type     osInvalICache, @function
osInvalICache:
    blez    $a1, ret
    li      $t3, 0x4000
    sltu    $at, $a1, $t3
    beq     $at, 0, $L1
    or      $t0, $a0, 0
    addu    $t1, $a0, $a1
    sltu    $at, $t0, $t1
    beq     $at, 0, ret
    andi    $t2, $t0, 0x1F
    addiu   $t1, $t1, -0x20
    subu    $t0, $t0, $t2
$L2:
    cache   0x10, 0x0($t0)
    sltu    $at, $t0, $t1
    addiu   $t0, $t0, 0x20
    bne     $at, 0, $L2
ret:
    nop
    jr      $ra
$L1:
    lui     $t0, 0x8000
    addu    $t1, $t0, $t3
    addiu   $t1, $t1, -0x20
$L3:
    cache   0x0, 0x0($t0)
    sltu    $at, $t0, $t1
    addiu   $t0, $t0, 0x20
    bne     $at, 0, $L3
    nop
    jr      $ra