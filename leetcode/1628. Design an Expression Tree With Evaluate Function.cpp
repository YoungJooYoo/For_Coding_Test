// Node interface
class Node 
{
public:
    virtual ~Node() {};
    virtual int evaluate() const = 0;
};

// OperandNode class representing a leaf node (operands)
class OperandNode : public Node 
{
public:
    OperandNode(const int value) 
        : mValue(value) 
    {

    }

    int evaluate() const override 
    {
        return mValue;
    }

private:
    const int mValue;
};

// OperatorNode class representing an internal node (operators)
class OperatorNode : public Node 
{
public:
    OperatorNode(const char op, const Node* left, const Node* right) 
        : op(op)
        , left(left)
        , right(right) 
    {

    }

    int evaluate() const override 
    {
        const int leftVal = left->evaluate();
        const int rightVal = right->evaluate();

        switch (op) 
        {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': return leftVal / rightVal;
        }

        return 0; // Should never reach here
    }

    ~OperatorNode() 
    {
        delete left;
        delete right;
    }

private:
    const char op;
    const Node* left;
    const Node* right;
};

// TreeBuilder class to build the expression tree from postfix notation
class TreeBuilder 
{
public:
    Node* buildTree(const vector<string>& postfix) 
    {
        stack<Node*> st;

        for (const string& token : postfix) 
        {
            if (isOperator(token)) 
            {
                const Node* right = st.top(); st.pop();
                const Node* left = st.top(); st.pop();
                Node* node = new OperatorNode(token[0], left, right);
                st.push(node);
            } 
            else 
            {
                st.push(new OperandNode(stoi(token)));
            }
        }

        return st.top();
    }

private:
    bool isOperator(const string& token) 
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};

// https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/description/


 /*
 ### 1628. 평가 함수가 있는 표현식 트리 설계

**난이도**: 중간

#### 문제 설명:

산술 표현식의 후위 표기법 토큰이 주어졌을 때, 이 표현식을 나타내는 이진 표현식 트리를 작성하고 반환하세요.

후위 표기법은 피연산자(숫자)가 연산자 앞에 나오는 산술 표현식 표기법입니다. 예를 들어, 표현식 `4*(5-(7+2))`의 후위 표기법은 배열 `postfix = ["4","5","7","2","+","-","*"]`로 나타냅니다.

`Node` 클래스는 이진 표현식 트리를 구현하는 데 사용해야 하는 인터페이스입니다. 반환된 트리는 트리의 값을 평가하는 `evaluate` 함수로 테스트됩니다. `Node` 클래스를 삭제해서는 안되지만, 원하는 경우 수정하거나 구현하는 데 필요한 다른 클래스를 정의할 수 있습니다.

이진 표현식 트리는 산술 표현식을 나타내는 이진 트리의 일종입니다. 이진 표현식 트리의 각 노드는 0개 또는 2개의 자식을 가질 수 있습니다. 자식이 없는 리프 노드(leaf node)는 피연산자(숫자)에 해당하며, 두 자식을 가진 내부 노드는 연산자 '+'(덧셈), '-'(뺄셈), '*'(곱셈), '/'(나눗셈)에 해당합니다.

어떠한 서브트리도 절대 값이 `10^9`을 초과하지 않는다는 것이 보장되며, 모든 연산은 유효합니다(예: 0으로 나누는 연산은 없습니다).

#### 추가 질문:
표현식 트리를 더 모듈화되게 설계할 수 있을까요? 예를 들어, 기존 `evaluate` 구현을 변경하지 않고 추가 연산자를 지원할 수 있습니까?

#### 예시 1:

```
입력: s = ["3","4","+","2","*","7","/"]
출력: 2
설명: 이 표현식은 ((3+4)*2)/7 = 14/7 = 2로 평가됩니다.
```

#### 예시 2:

```
입력: s = ["4","5","2","7","+","-","*"]
출력: -16
설명: 이 표현식은 4*(5-(2+7)) = 4*(-4) = -16로 평가됩니다.
```

#### 제약 조건:

- `1 <= s.length < 100`
- `s.length`는 홀수입니다.
- `s`는 숫자와 문자 '+', '-', '*', '/'로 구성됩니다.
- `s[i]`가 숫자인 경우, 그 정수 값은 `10^5`를 넘지 않습니다.
- `s`는 유효한 표현식임이 보장됩니다.
- 결과값 및 중간 값의 절대 값은 `10^9`을 넘지 않습니다.
- 표현식에 0으로 나누는 연산은 포함되지 않습니다.
 
 */
