class Node
  attr_reader :value
  attr_accessor :left, :right

  def initialize(value=nil)
    @value = value
    left = nil
    right = nil
  end
end

class BinaryTree
  attr_accessor :root_node

  def initialize(root_value=nil)
    @root_node = Node.new(root_value)
  end

  def insert(node, value)
    if value > node.value
      insert(node.right, value)
    elsif value <= node.value
      insert(node.left, value)
    else
      puts "Ok lil man or woman or in-betweener, the value you inputed wasn't very cool lil bro, try again."
  end

  def search(value)
  end

  def delete(value)
  end
end
