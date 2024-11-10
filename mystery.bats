setup() {
    load 'bats/bats-support/load'
    load 'bats/bats-assert/load'
}
# Test lorsque la chaine de caractere est vide
@test "chaine vide" {
    run bash -c "echo '' | ./mystery"
    assert_output ''
    assert_success
}

# Test d'une chaine de caracteres sans espaces
@test "chaine sans espaces" {
    run bash -c "echo 'Espace' | ./mystery"
    assert_output 'Espace'
    assert_success

}

# Test d'une chaine d'espace au debut
@test "chaine espace debut" {
    run bash -c "echo ' Test espace debut' | ./mystery"
    assert_output 'Test espace debut'
    assert_success

}


# Test d'une chaine d'espace à la fin
@test "chaine espace fin" {
    run bash -c "echo 'Test espace fin ' | ./mystery"
    assert_output 'Test espace fin'
    assert_success


}

