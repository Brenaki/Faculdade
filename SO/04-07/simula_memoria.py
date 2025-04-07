import tkinter as tk
from tkinter import messagebox

class MemoryBlock:
    def __init__(self, start, size):
        self.start = start
        self.size = size

class MemoryManager:
    def __init__(self, total_size):
        # Inicializa com um bloco livre de tamanho total
        self.free_blocks = [MemoryBlock(0, total_size)]
    
    def allocate(self, size):
        for block in self.free_blocks:
            if block.size >= size:
                allocated_start = block.start
                block.start += size
                block.size -= size
                if block.size == 0:
                    self.free_blocks.remove(block)
                return allocated_start
        return None  # memoria insuficiente
    
    def free(self, address, size):
        # Insere um novo bloco livre; para simplicidade, nao mescla blocos adjacentes
        self.free_blocks.append(MemoryBlock(address, size))
    
    def get_state(self):
        state = []
        for block in self.free_blocks:
            state.append(f"Inicio: {block.start}, Tamanho: {block.size}")
        return state

class MemoryManagerApp:
    def __init__(self, master):
        self.master = master
        master.title("Gerenciador de Memoria")
        
        self.manager = MemoryManager(100)
        
        self.allocate_frame = tk.Frame(master)
        self.allocate_frame.pack(pady=5)
        
        tk.Label(self.allocate_frame, text="Tamanho a alocar:").grid(row=0, column=0)
        self.alloc_entry = tk.Entry(self.allocate_frame, width=5)
        self.alloc_entry.grid(row=0, column=1, padx=5)
        tk.Button(self.allocate_frame, text="Alocar", command=self.allocate_memory)\
            .grid(row=0, column=2, padx=5)
        
        self.free_frame = tk.Frame(master)
        self.free_frame.pack(pady=5)
        
        tk.Label(self.free_frame, text="Endereco:").grid(row=0, column=0)
        self.free_addr_entry = tk.Entry(self.free_frame, width=5)
        self.free_addr_entry.grid(row=0, column=1, padx=5)
        tk.Label(self.free_frame, text="Tamanho:").grid(row=0, column=2)
        self.free_size_entry = tk.Entry(self.free_frame, width=5)
        self.free_size_entry.grid(row=0, column=3, padx=5)
        tk.Button(self.free_frame, text="Liberar", command=self.free_memory)\
            .grid(row=0, column=4, padx=5)
        
        self.state_listbox = tk.Listbox(master, width=50)
        self.state_listbox.pack(pady=10)
        
        self.update_state()
    
    def allocate_memory(self):
        size_str = self.alloc_entry.get().strip()
        if size_str:
            try:
                size = int(size_str)
            except ValueError:
                messagebox.showerror("Erro", "Tamanho deve ser inteiro")
                return
            addr = self.manager.allocate(size)
            if addr is not None:
                messagebox.showinfo("Alocado", f"Memoria alocada a partir do endereco {addr}")
            else:
                messagebox.showwarning("Insuficiente", "Memoria insuficiente")
            self.alloc_entry.delete(0, tk.END)
            self.update_state()
    
    def free_memory(self):
        addr_str = self.free_addr_entry.get().strip()
        size_str = self.free_size_entry.get().strip()
        if addr_str and size_str:
            try:
                addr = int(addr_str)
                size = int(size_str)
            except ValueError:
                messagebox.showerror("Erro", "Endereco e tamanho devem ser inteiros")
                return
            self.manager.free(addr, size)
            messagebox.showinfo("Liberado", f"Liberadas {size} unidades no endereco {addr}")
            self.free_addr_entry.delete(0, tk.END)
            self.free_size_entry.delete(0, tk.END)
            self.update_state()
        else:
            messagebox.showwarning("Aviso", "Preencha endereco e tamanho")
    
    def update_state(self):
        self.state_listbox.delete(0, tk.END)
        for state in self.manager.get_state():
            self.state_listbox.insert(tk.END, state)

if __name__ == "__main__":
    root = tk.Tk()
    app = MemoryManagerApp(root)
    root.mainloop()
