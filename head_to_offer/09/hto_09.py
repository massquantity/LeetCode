class CQueue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def appendTail(self, value: int) -> None:
        self.stack1.append(value)

    def deleteHead(self) -> int:
        if not self.stack2:
            if not self.stack1:
                return -1
            else:
                while (self.stack1):
                    self.stack2.append(self.stack1.pop())
        return self.stack2.pop()


if __name__ == "__main__":
    queue = CQueue()
    queue.appendTail(1)
    print(queue.deleteHead())
    print(queue.deleteHead())