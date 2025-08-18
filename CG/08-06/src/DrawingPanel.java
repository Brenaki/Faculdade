import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

class DrawingPanel extends JPanel {
    private List<PixelInfo> pixels;
    private Point startPoint;
    private Point currentPixel;
    private int lineThickness = 5; // Espessura padrão da linha

    public DrawingPanel() {
        pixels = new ArrayList<>();
    }

    public void setStartPoint(Point point) {
        this.startPoint = point;
    }

    public void addPixel(Point point, Color color) {
        pixels.add(new PixelInfo(point, color, lineThickness));
    }

    public void addPixels(List<Point> points, Color color) {
        for (Point point : points) {
            pixels.add(new PixelInfo(point, color, lineThickness));
        }
    }

    public void setCurrentPixel(Point point) {
        this.currentPixel = point;
    }

    public void setLineThickness(int thickness) {
        this.lineThickness = thickness;
        repaint(); // Forçar repintura para aplicar a nova espessura
    }

    public int getLineThickness() {
        return lineThickness;
    }

    public void clearPixels() {
        pixels.clear();
    }

    public void clearAll() {
        pixels.clear();
        startPoint = null;
        currentPixel = null;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        
        // Configurar renderização para melhor qualidade
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2d.setRenderingHint(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);

        // Desenhar grid leve para melhor visualização
        g2d.setColor(new Color(240, 240, 240));
        for (int x = 0; x < getWidth(); x += 20) {
            g2d.drawLine(x, 0, x, getHeight());
        }
        for (int y = 0; y < getHeight(); y += 20) {
            g2d.drawLine(0, y, getWidth(), y);
        }

        // Desenhar ponto inicial
        if (startPoint != null) {
            g2d.setColor(Color.GREEN);
            g2d.fillOval(startPoint.x - 4, startPoint.y - 4, 8, 8);
            g2d.setColor(Color.BLACK);
            g2d.drawString("Início", startPoint.x + 5, startPoint.y - 5);
        }

        // Desenhar pixels da linha com espessura configurável
        for (PixelInfo pixelInfo : pixels) {
            g2d.setColor(pixelInfo.color);
            // Desenhar pixel com tamanho baseado na espessura da linha
            int halfThickness = pixelInfo.thickness / 2;
            g2d.fillRect(pixelInfo.point.x - halfThickness, pixelInfo.point.y - halfThickness, pixelInfo.thickness, pixelInfo.thickness);
        }

        // Destacar pixel atual durante animação
        if (currentPixel != null) {
            g2d.setColor(Color.YELLOW);
            int halfThickness = lineThickness / 2;
            g2d.drawRect(currentPixel.x - halfThickness - 2, currentPixel.y - halfThickness - 2, lineThickness + 4, lineThickness + 4);
            g2d.setColor(Color.BLACK);
            g2d.drawString("Atual", currentPixel.x + lineThickness + 5, currentPixel.y - 5);
        }
    }

    // Classe interna para armazenar informações do pixel
    private static class PixelInfo {
        Point point;
        Color color;
        int thickness;

        PixelInfo(Point point, Color color, int thickness) {
            this.point = point;
            this.color = color;
            this.thickness = thickness;
        }
    }
}