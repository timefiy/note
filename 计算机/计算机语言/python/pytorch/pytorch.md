# pytorch

## 什么是pytorch

PyTorch（[https://pytorch.org/）是一个基于](https://pytorch.org/%EF%BC%89%E6%98%AF%E4%B8%80%E4%B8%AA%E5%9F%BA%E4%BA%8E) Python 的开源深度学习库。根据 [Papers With Code](https://paperswithcode.com/trends)自 2019 年以来一直是研究领域中使用最广泛的深度学习库，且领先优势明显。部分原因在于其用户友好的界面和高效性，同时并未牺牲灵活性，依然为高级用户提供了调整模型底层细节以实现定制和优化的能力

### pytorch的三个核心组件

![](assets/pytorch/file-20260302090642444.jpg)

- **张量库**：它在数组导向编程库 NumPy 的基础上扩展了功能，增加了对 GPU 加速计算的支持，从而实现了 CPU 和 GPU 之间的无缝切换。
- **自动微分引擎（ autograd）**：能够自动计算张量操作的梯度，从而简化反向传播过程和模型优化
- **深度学习库**：提供模块化、灵活和高效的构建模块（包括预训练模型、损失函数和优化器），用于设计和训练各种深度学习模型，同时满足研究人员和开发人员的需求