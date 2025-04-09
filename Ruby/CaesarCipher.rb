def caesar_cipher(string, shift_val)
  alphabet = ('a'.. 'z').to_a
  res = ""
  string.each_char do |char|
    if alphabet.include?(char)
      index = alphabet.index(char)
      res += alphabet[(index + shift_val) % 26] // this is actually ths where the shift is happening
    else
      res += char
    end
  end
  res
end
