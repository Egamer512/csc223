class Node
  attr_reader :value
  attr_accessor :left, :right

  def initialize(value=nil)
    @value = value
    @left = nil
    @right = nil
  end
end

class BinaryTree
  attr_accessor :root_node

  def initialize(root_value=nil)
    @root_node = root_value.nil? ? nil:Node.new(root_value)
  end

  def insert(value, node = @root_node)
    if @root_node.nil?
      @root_node = Node.new(value)
      return @root_node
    end

    if node.nil?
      return Node.new(value)
    end

    if value > node.value
      node.right = insert(value, node.right)
    else
      node.left = insert(value, node.left)
    end
    node
  end

  def visualize(node = @root_node, prefix = '', is_left = true)
    return if node.nil?

    visualize(node.right, prefix + (is_left ? "│   " : "    "), false)
    puts prefix + (is_left ? "└── " : "┌── ") + node.value.to_s
    visualize(node.left, prefix + (is_left ? "    " : "│   "), true)
  end


  def search(root = @root_node, value)
    return nil if root.nil?
    if root.value == value
      return root
    end
    if root.value < value
      return search(root.right, value)
    end
    search(root.left, value)
  end

  def delete(value, node = @root_node)
    return nil if node.nil?
    reutrn @root_node unless search(@root_node, value)

    if value < node.value
      node.left = delete(value, node.left)
    elsif value > node.value
      node.right = delete(value, node.right)
    else
      return node.right if node.left.nil?
      return node.left if node.right.nil?

      successor = node.right
      successor = successor.left while successor.left

      node.value = successor.value
      node.right = delete(successor.value, node.right)
    end
    node
  end
  
end

tree = BinaryTree.new
[6, 9, 4, 2, 8, 23, 100, 28, 75, 47].each {|val| tree.insert(val)}
tree.visualize
tree. delete(23)
tree.visualize