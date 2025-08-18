import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.List;
import java.util.ArrayList;

public class ComparisonWindow extends JFrame {
    private DrawingPanel bresenhamPanel;
    private DrawingPanel simplePanel;
    private JLabel bresenhamLabel;
    private JLabel simpleLabel;
    private JTextArea detailsArea;
    private Point startPoint, endPoint;
    private boolean isDrawing = false;
    private Timer animationTimer;
    private List<Point> bresenhamPixels;
    private List<Point> simplePixels;
    private int lineThickness = 5;

    public ComparisonWindow() {
        setTitle("Comparação: Bresenham vs Algoritmo Simples");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLayout(new BorderLayout());
        
        // Definir tamanho da janela de comparação
        setPreferredSize(new Dimension(1000, 600));
        setResizable(true);

        initializeComponents();
        setupLayout();
        setupEventHandlers();

        pack();
        setLocationRelativeTo(null);
    }

    private void initializeComponents() {
        // Painéis de desenho para cada algoritmo
        bresenhamPanel = new DrawingPanel();
        bresenhamPanel.setPreferredSize(new Dimension(400, 300));
        bresenhamPanel.setBackground(Color.WHITE);
        bresenhamPanel.setLineThickness(lineThickness);

        simplePanel = new DrawingPanel();
        simplePanel.setPreferredSize(new Dimension(400, 300));
        simplePanel.setBackground(Color.WHITE);
        simplePanel.setLineThickness(lineThickness);

        // Labels para identificar cada painel
        bresenhamLabel = new JLabel("Algoritmo de Bresenham (Azul)", SwingConstants.CENTER);
        bresenhamLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 14));
        bresenhamLabel.setBorder(BorderFactory.createEtchedBorder());

        simpleLabel = new JLabel("Algoritmo Simples (Vermelho)", SwingConstants.CENTER);
        simpleLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 14));
        simpleLabel.setBorder(BorderFactory.createEtchedBorder());

        // Área de detalhes
        detailsArea = new JTextArea(8, 50);
        detailsArea.setEditable(false);
        detailsArea.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 12));
    }

    private void setupLayout() {
        // Panel superior com os dois painéis de desenho lado a lado
        JPanel drawingPanel = new JPanel(new GridLayout(1, 2, 10, 10));
        drawingPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // Panel para Bresenham
        JPanel bresenhamContainer = new JPanel(new BorderLayout());
        bresenhamContainer.add(bresenhamLabel, BorderLayout.NORTH);
        bresenhamContainer.add(bresenhamPanel, BorderLayout.CENTER);
        drawingPanel.add(bresenhamContainer);

        // Panel para Algoritmo Simples
        JPanel simpleContainer = new JPanel(new BorderLayout());
        simpleContainer.add(simpleLabel, BorderLayout.NORTH);
        simpleContainer.add(simplePanel, BorderLayout.CENTER);
        drawingPanel.add(simpleContainer);

        add(drawingPanel, BorderLayout.CENTER);

        // Panel inferior com detalhes
        JPanel bottomPanel = new JPanel(new BorderLayout());
        JLabel detailsLabel = new JLabel("Detalhes da Comparação:");
        bottomPanel.add(detailsLabel, BorderLayout.NORTH);
        
        JScrollPane scrollPane = new JScrollPane(detailsArea);
        scrollPane.setPreferredSize(new Dimension(1000, 150));
        bottomPanel.add(scrollPane, BorderLayout.CENTER);

        add(bottomPanel, BorderLayout.SOUTH);
    }

    private void setupEventHandlers() {
        // Mouse listeners para ambos os painéis
        MouseAdapter mouseAdapter = new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                handleMouseClick(e.getPoint());
            }
        };

        bresenhamPanel.addMouseListener(mouseAdapter);
        simplePanel.addMouseListener(mouseAdapter);
    }

    private void handleMouseClick(Point point) {
        // Parar qualquer animação em andamento
        if (animationTimer != null && animationTimer.isRunning()) {
            animationTimer.stop();
        }
        
        if (!isDrawing) {
            // Resetar estado para nova linha
            startPoint = point;
            endPoint = null;
            bresenhamPanel.setStartPoint(startPoint);
            simplePanel.setStartPoint(startPoint);
            bresenhamPanel.setCurrentPixel(null);
            simplePanel.setCurrentPixel(null);
            bresenhamPanel.repaint();
            simplePanel.repaint();
            detailsArea.setText("Ponto inicial: (" + startPoint.x + ", " + startPoint.y + "). Clique para definir o ponto final.");
        } else {
            endPoint = point;
            detailsArea.setText("Desenhando linha de (" + startPoint.x + ", " + startPoint.y + ") para (" + endPoint.x + ", " + endPoint.y + ")");
            drawComparisonLines();
        }
        isDrawing = !isDrawing;
    }

    private void drawComparisonLines() {
        if (startPoint == null || endPoint == null) return;

        // Limpar painéis
        bresenhamPanel.clearPixels();
        simplePanel.clearPixels();
        bresenhamPanel.setCurrentPixel(null);
        simplePanel.setCurrentPixel(null);

        // Gerar pixels para cada algoritmo
        bresenhamPixels = bresenhamLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
        simplePixels = simpleLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);

        // Desenhar as linhas
        bresenhamPanel.addPixels(bresenhamPixels, Color.BLUE);
        simplePanel.addPixels(simplePixels, Color.RED);

        bresenhamPanel.repaint();
        simplePanel.repaint();

        // Mostrar detalhes da comparação
        detailsArea.setText("Comparação dos Algoritmos:\n");
        detailsArea.append("Bresenham (Azul): " + bresenhamPixels.size() + " pixels\n");
        detailsArea.append("Simples (Vermelho): " + simplePixels.size() + " pixels\n");
        detailsArea.append("Diferença: " + Math.abs(bresenhamPixels.size() - simplePixels.size()) + " pixels\n");
        
        if (bresenhamPixels.size() < simplePixels.size()) {
            detailsArea.append("Bresenham é mais eficiente!\n");
        } else if (simplePixels.size() < bresenhamPixels.size()) {
            detailsArea.append("Algoritmo Simples é mais eficiente!\n");
        } else {
            detailsArea.append("Ambos os algoritmos geraram o mesmo número de pixels.\n");
        }
    }

    private List<Point> bresenhamLine(int x0, int y0, int x1, int y1) {
        List<Point> pixels = new ArrayList<>();
        
        int dx = Math.abs(x1 - x0);
        int dy = Math.abs(y1 - y0);
        int sx = x0 < x1 ? 1 : -1;
        int sy = y0 < y1 ? 1 : -1;
        int err = dx - dy;

        int x = x0, y = y0;

        while (true) {
            pixels.add(new Point(x, y));
            if (x == x1 && y == y1) break;

            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x += sx;
            }
            if (e2 < dx) {
                err += dx;
                y += sy;
            }
        }

        return pixels;
    }

    private List<Point> simpleLine(int x0, int y0, int x1, int y1) {
        List<Point> pixels = new ArrayList<>();
        
        int dx = Math.abs(x1 - x0);
        int dy = Math.abs(y1 - y0);

        if (dx == 0) { // Linha vertical
            int startY = Math.min(y0, y1);
            int endY = Math.max(y0, y1);
            for (int y = startY; y <= endY; y++) {
                pixels.add(new Point(x0, y));
            }
        } else if (dy == 0) { // Linha horizontal
            int startX = Math.min(x0, x1);
            int endX = Math.max(x0, x1);
            for (int x = startX; x <= endX; x++) {
                pixels.add(new Point(x, y0));
            }
        } else {
            double slope = (double)(y1 - y0) / (x1 - x0);

            if (Math.abs(slope) <= 1) {
                // Iterar sobre X
                int startX = Math.min(x0, x1);
                int endX = Math.max(x0, x1);
                int baseY = (startX == x0) ? y0 : y1;
                int baseX = (startX == x0) ? x0 : x1;

                for (int x = startX; x <= endX; x++) {
                    int y = (int) Math.round(baseY + slope * (x - baseX));
                    pixels.add(new Point(x, y));
                }
            } else {
                // Iterar sobre Y
                int startY = Math.min(y0, y1);
                int endY = Math.max(y0, y1);
                int baseX = (startY == y0) ? x0 : x1;
                int baseY = (startY == y0) ? y0 : y1;
                double invSlope = 1.0 / slope;

                for (int y = startY; y <= endY; y++) {
                    int x = (int) Math.round(baseX + invSlope * (y - baseY));
                    pixels.add(new Point(x, y));
                }
            }
        }

        return pixels;
    }

    public void setLineThickness(int thickness) {
        this.lineThickness = thickness;
        bresenhamPanel.setLineThickness(thickness);
        simplePanel.setLineThickness(thickness);
    }

    public void clearAll() {
        bresenhamPanel.clearAll();
        simplePanel.clearAll();
        detailsArea.setText("");
        isDrawing = false;
        startPoint = null;
        endPoint = null;
    }
}
