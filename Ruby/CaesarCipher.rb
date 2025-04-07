def caesar_cipher(string, shift_val)
  alphabet = ('a'.. 'z').to_a
  res = ""
  string.each_char do |char|
    if alphabet.include?(char)
    index = alphabet.index(char)
    result = alphabet

end

caesar_cipher("helloworld", 5)