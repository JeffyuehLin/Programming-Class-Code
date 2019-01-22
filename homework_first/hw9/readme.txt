input                                           output
---------------------------------------------------------------

cat hw9_input1 | ./a.out -c apple               hw9_output1_c_apple
cat hw9_input1 | ./a.out -c banana              hw9_output1_c_banana
cat hw9_input1 | ./a.out -m Apple               hw9_output1_m_Apple
cat hw9_input1 | ./a.out -v apple               hw9_output1_v_apple
cat hw9_input1 | ./patfind -c -m pattern        hw9_output1_error
cat hw9_input1 | ./patfind -d pattern           hw9_output1_error

cat hw9_input2 | ./a.out -c Times               hw9_output2_c_Times
cat hw9_input2 | ./a.out -c the                 hw9_output2_c_the
cat hw9_input2 | ./a.out -m the                 hw9_output2_m_the
cat hw9_input2 | ./a.out -v the                 hw9_output2_v_the
