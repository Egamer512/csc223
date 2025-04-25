def caesar_cipher(string, shift_val)
  alphabet = ('a'.. 'z').to_a
  res = ""
  string.each_char do |char|
    if alphabet.include?(char)
      index = alphabet.index(char)
      res += alphabet[(index + shift_val) % 26] 
    else
      res += char
    end
  end
  puts res
end

caesar_cipher("wow", 4)