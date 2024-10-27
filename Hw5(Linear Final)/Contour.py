import numpy as np
import matplotlib.pyplot as plt

# กำหนดสมการ
def f(x1, x2):
    return x1**2 + 5*x1*x2 + 0.5*x2**2 - 3*x1 - 2*x2

# สร้างตารางค่าของ x1 และ x2
x1 = np.linspace(-10, 10, 400)  # สร้างช่วงของ x1
x2 = np.linspace(-10, 10, 400)  # สร้างช่วงของ x2
X1, X2 = np.meshgrid(x1, x2)  # สร้างกริดจาก x1 และ x2

# คำนวณค่าของฟังก์ชัน f(x1, x2) บนกริด
Z = f(X1, X2)

# วาดกราฟ Contour
plt.figure(figsize=(8, 6))
contour = plt.contour(X1, X2, Z, levels=20, cmap='viridis')  # ปรับ levels และ cmap ตามต้องการ
plt.colorbar(contour)  # แสดงแถบสีที่ใช้ในกราฟ
plt.title('Contour Plot')
plt.xlabel('$x_1$')
plt.ylabel('$x_2$')
plt.grid(True)
plt.show()
