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

  def insert(value, node = @root_node)
    if node.nil?
      return Node.new(value)
    end

    if value > node.value
      node.right = insert(value, node.right)
    else
      node,left = insert(value, node.left)
    end
    node
  end

  def visualize(node = @root_node, prefix = '', is_left = true)
    return if node.nil?

    visualize(node.right, prefix + (is_left ? "│   " : "    "), false)
    puts prefix + (is_left ? "└── " : "┌── ") + node.value.to_s
    visualize(node.left, prefix + (is_left ? "    " : "│   "), true)
  end


  def search(value)
  end

  def delete(value)
  end
end

tree = BinaryTree.new
tree.insert(5)
tree.visualize